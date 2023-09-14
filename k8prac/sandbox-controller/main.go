package main

import (
	"context"
	"path/filepath"
	"flag"
	"log"
	"net/http"
	"fmt"
	"k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	 "k8s.io/apimachinery/pkg/watch"
	 "k8s.io/client-go/util/homedir"
)

func main() {
	var _namespace,
	 	_labelSelector,
		_fieldSelector string

	//Define kubeconfig file
	var kubeconfig *string
	if home := homedir.HomeDir(); home != "" { // check if machine has home directory.
		// read kubeconfig flag. if not provided use config file $HOME/.kube/config
		kubeconfig = flag.String("kubeconfig", filepath.Join(home, ".kube", "config"), "(optional) absolute path to the kubeconfig file")
	} else {
		kubeconfig = flag.String("kubeconfig", "", "absolute path to the kubeconfig file")
	}


	//Load kubernetes config
	config, err := clientcmd.BuildConfigFromFlags("", *kubeconfig)
	if err != nil {
		log.Fatal(err)
	}

	//Create a client set to use k8s apis
	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		log.Fatal(err)
	}

	//create an api object
	api := clientset.CoreV1()

	// Read namesapce from command line
	flag.StringVar(&_namespace, "n", "default", " namespace")
	flag.StringVar(&_labelSelector, "l", "", "Label selector ")
	flag.StringVar(&_fieldSelector, "f", "", "Field selector ")
	flag.Parse()

	opts := metav1.ListOptions{
		LabelSelector: _labelSelector,
		FieldSelector: _fieldSelector,
	}

	//Create a watcher on pods
	fmt.Printf("Starting a Pod watcher in namespace [%s]\n",_namespace)

	podWatcher, err := api.Pods(_namespace).Watch(context.TODO(), opts)
	if err != nil {
		log.Fatal(err)
	}


    //Watch loop 

	podChannel := podWatcher.ResultChan()

	for event := range podChannel {
		pod,ok  :=event.Object.(*v1.Pod)
		if (! ok ) { log. Fatal(err )
		}

		switch event.Type{

		case watch.Added:
			log.Printf(" Pod %s added \n",pod.Name)

			// serviceName := "nginx-service"
			// servicePort := 80
			// service, err := api.Services(_namespace).Get(context.TODO(), serviceName, metav1.GetOptions{})
			// if err != nil {
			// 	log.Fatal(err)
			// }
			// serviceIP := service.Spec.ClusterIPss
			// Use something like this: minikube service nginx-service --url
			// to grab the IP.
			serviceIP := "Your Minikube IP goes here."	
			servicePort := 1234 

			// Construct the URL for the GET request
			url := fmt.Sprintf("http://%s:%d", serviceIP, servicePort)

			// Send the GET request
			response, err := http.Get(url)
			if err != nil {
				log.Printf("Error making GET request: %v\n", err)
			} else {
				defer response.Body.Close()
				log.Printf("GET request to %s returned status code: %d\n", url, response.StatusCode)
				if response.StatusCode == 500 {
					log.Printf("Got 500")
				}
			}

		case watch.Deleted:
						log.Printf(" Pod %s deleted \n",pod.Name)

		}
	}



}