package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"
	"os"
	"log"

	// core "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/api/apps/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	"k8s.io/apimachinery/pkg/watch"
)

func main() {
	var kubeconfig *string
	if home := homedir.HomeDir(); home != "" { // check if machine has home directory.
		// read kubeconfig flag. if not provided use config file $HOME/.kube/config
		kubeconfig = flag.String("kubeconfig", filepath.Join(home, ".kube", "config"), "(optional) absolute path to the kubeconfig file")
	} else {
		kubeconfig = flag.String("kubeconfig", "", "absolute path to the kubeconfig file")
	}
	flag.Parse()

	// build configuration from the config file.
	config, err := clientcmd.BuildConfigFromFlags("", *kubeconfig)
	if err != nil {
		panic(err)
	}
	// create kubernetes clientset. this clientset can be used to create,delete,patch,list etc for the kubernetes resources
	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		panic(err)
	}

	listOptions := metav1.ListOptions{}
	deploymentsWatcher, err := clientset.AppsV1().Deployments("").Watch(context.Background(), listOptions)
	if err != nil {
		fmt.Printf("Error getting deployments: %v\n", err)
		os.Exit(1)
	}
	
	deploymentChannel := deploymentsWatcher.ResultChan()

	for event := range deploymentChannel {
		deployment, ok := event.Object.(*v1.Deployment)
		if (!ok) { 
			log.Fatal(err)
		}
		switch event.Type{
			case watch.Added:
				log.Printf("Deployment %s added \n", deployment.Name)
			case watch.Deleted:
				log.Printf("Deployment %s deleted \n", deployment.Name)
		}
	}
}
