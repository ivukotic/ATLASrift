// Copyright 2015 Ilija Vukotic. Licensed under the 	Educational Community License, Version 2.0 (the 

#include "ATLASrift.h"
#include "Reporter.h"

#include "NetServer.h"


// Sets default values for this component's properties
UReporter::UReporter()
{
	TargetHost = "http://atlasrift.appspot.com";
	Http = &FHttpModule::Get();
	
	FString address = TEXT("128.141.224.219");
	//FString address = TEXT("pb-d-128-141-164-172.cern.ch");
	int32 port = 5005;
	FIPv4Address::Parse(address, RemoteAddress);

	RemoteEndpoint = FIPv4Endpoint(RemoteAddress, port);
	
	SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);


	if (SocketSubsystem != nullptr) { // is SocketSybstystem OK
		SenderSocket = SocketSubsystem->CreateSocket(NAME_DGram, TEXT("default"), true);

		if (SenderSocket != nullptr) {
			bool Error = !SenderSocket->SetNonBlocking(true) || !SenderSocket->SetReuseAddr(true) || !SenderSocket->SetRecvErr();

		//	if (!Error) {
		//		Error = SenderSocket->Bind(*RemoteEndpoint.ToInternetAddr());
		//	}
			if (!Error) {
				int32 OutNewSize;
				SenderSocket->SetReceiveBufferSize(1000, OutNewSize);
				SenderSocket->SetSendBufferSize(1000, OutNewSize);
			}
			if (Error) {
				UE_LOG(LogTemp, Error, TEXT("ERROR on connecting Keep Alive UDP"));
			}
			else {
				UE_LOG(LogTemp, Display, TEXT("SUCCESS on connecting Keep Alive UDP"));
			}
		}
	}


}

void UReporter::StartWork(FString parameters)
{
	UE_LOG(LogTemp, Display, TEXT("Sending START message"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	UE_LOG(LogTemp, Display, TEXT("configuration: %s"), *parameters);

	Request->SetVerb("POST");
	Request->SetURL(TargetHost + "/ATLASriftMonitor");
	Request->SetHeader("User-Agent", "ATLASriftClient/0.7");
	Request->SetHeader("Accept", "application/json");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(parameters);
	Request->OnProcessRequestComplete().BindUObject(this, &UReporter::OnResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Sending START message"));
	}
	
}

void UReporter::OnResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful){
	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error in sending data."));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		UE_LOG(LogTemp, Display, TEXT("Message sent"));
	}
}

void UReporter::StopWork()
{
	UE_LOG(LogTemp, Display, TEXT("Sending STOP message"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/eventserver");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");
	Request->SetContentAsString("stopped");
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Sending STOP message"));
	}
}

void  UReporter::LoadNetServers()
{
	ANetServers.Empty();
	UE_LOG(LogTemp, Display, TEXT("Loading NetServers"));
	if (!Http) return;
	if (!Http->IsHttpEnabled()) return;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
	Request->SetVerb("GET");
	Request->SetURL(TargetHost + "/netservers");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Accept", "application/json");
	Request->OnProcessRequestComplete().BindUObject(this, &UReporter::OnServersResponseReceived);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on receiving NetServers"));
	}
}

void UReporter::OnServersResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful) {
	UE_LOG(LogTemp, Display, TEXT("got something for netservers"));
	FString MessageBody = "";

	if (!Response.IsValid())
	{
		UE_LOG(LogTemp, Error, TEXT("Error Receiving NetServers"));
	}
	else if (EHttpResponseCodes::IsOk(Response->GetResponseCode()))
	{
		MessageBody = Response->GetContentAsString();

		UE_LOG(LogTemp, Display, TEXT("MessageBody: %s"), *MessageBody);

		TSharedPtr<FJsonObject> jServers;
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(MessageBody);
		if (FJsonSerializer::Deserialize(JsonReader, jServers))
		{
			for (auto currJsonValue = jServers->Values.CreateConstIterator(); currJsonValue; ++currJsonValue)
			{

				FNetServer ns;
				ns.ip = (*currJsonValue).Key;
				TSharedPtr<FJsonValue> jServerDetails = (*currJsonValue).Value;
				TSharedPtr<FJsonObject> jSD = jServerDetails->AsObject();
				ns.description = jSD->GetStringField("description");
				ns.accessCode = jSD->GetStringField("ac");
				ns.clients = jSD->GetIntegerField("clients");
				UE_LOG(LogTemp, Display, TEXT("IP: %s     Description: %s    Clients: %d"),  *ns.ip, *ns.description, ns.clients);
				ANetServers.Push(ns);
			}
		}
		UE_LOG(LogTemp, Display, TEXT("Loaded %i"), ANetServers.Num() );
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("{\"success\":\"HTTP Error: %d\"}"), Response->GetResponseCode());
	}
}

bool UReporter::HostAServer(FString description ) {
	UE_LOG(LogTemp, Display, TEXT("Registering as a server"));
	if (!Http) return false;
	if (!Http->IsHttpEnabled()) return false;
	TSharedRef < IHttpRequest > Request = Http->CreateRequest();

	Request->SetVerb("POST");
	Request->SetURL(TargetHost + "/netservers");
	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
	Request->SetHeader("Content-Type", "application/json");
	Request->SetContentAsString(description);
	if (!Request->ProcessRequest())
	{
		UE_LOG(LogTemp, Error, TEXT("ERROR on Registering as a server message"));
		return false;
	}
	else
		return true;
}
//void UReporter::KeepAlive(int32 clients) {
//	UE_LOG(LogTemp, Display, TEXT("keeping alive"));
//	if (!Http) return;
//	if (!Http->IsHttpEnabled()) return;
//	TSharedRef < IHttpRequest > Request = Http->CreateRequest();
//
//	Request->SetVerb("GET");
//	Request->SetURL(TargetHost + "/keepalive");
//	Request->SetHeader("User-Agent", "ATLASriftClient/1.0");
//	Request->SetHeader("Content-Type", "application/json");
//	Request->SetContentAsString("{\"clients\":" + FString::FromInt(clients) +"}");
//	if (!Request->ProcessRequest())
//	{
//		UE_LOG(LogTemp, Error, TEXT("ERROR on Registering Keep Alive"));
//	}
//}

void UReporter::KeepAliveUDP(FString message) {
	// UE_LOG(LogTemp, Display, TEXT("keeping alive UDP"));

	if (!SenderSocket) return;
	TCHAR *serializedChar = message.GetCharArray().GetData();
	int32 size = FCString::Strlen(serializedChar);
	int32 sent = 0;

	bool successful = SenderSocket->SendTo((uint8*)TCHAR_TO_UTF8(serializedChar), size, sent,*RemoteEndpoint.ToInternetAddr());
	if (!successful) {
		UE_LOG(LogTemp, Error, TEXT("ERROR on sending Keep Alive UDP"));
	}
	else {
		UE_LOG(LogTemp, Display, TEXT("SUCCESS on sending Keep Alive UDP"));
	}
		
}