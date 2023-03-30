`kubectl apply -f .\ng-deployment.yaml` creates the pods and ...

`kubectl apply -f .\ng-service.yaml` creates the services.

`minikube service ng-service-example --url` will give me the URL to access it.