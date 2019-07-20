// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.IO;

public class ATLASrift : ModuleRules
{

    //private string ModulePath
    //{
    //    get { return Path.GetDirectoryName(RulesCompiler.GetModuleFilename(this.GetType().Name)); }
    //}

    //private string ThirdPartyPath
    //{
    //    get { return Path.GetFullPath(Path.Combine(ModulePath, "../../ThirdParty/")); }
    //}

	public ATLASrift(ReadOnlyTargetRules Target) : base (Target)
	{
        PrivatePCHHeaderFile = "ATLASrift.h";
        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HTTP", "Json", "Sockets", "Networking", "OnlineSubsystemNull" , "HeadMountedDisplay" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");
		// if ((Target.Platform == UnrealTargetPlatform.Win32) || (Target.Platform == UnrealTargetPlatform.Win64))
		// {
		//		if (UEBuildConfiguration.bCompileSteamOSS == true)
		//		{
		//			DynamicallyLoadedModuleNames.Add("OnlineSubsystemSteam");
		//		}
		// }
	}
}
