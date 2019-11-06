kubectl delete secret -n aaas atlasrift
kubectl create secret -n aaas generic atlasrift --from-file=arconf=secrets/config.json

kubectl delete -f frontend.yaml
kubectl create -f frontend.yaml