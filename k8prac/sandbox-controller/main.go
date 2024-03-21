package main

import (
	"os"
	"context"
	"path/filepath"
	"flag"
	"log"
	// "net/http"
	"fmt"
	core "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	 "k8s.io/apimachinery/pkg/watch"
	 "k8s.io/client-go/util/homedir"
)

var (
	clientset           *kubernetes.Clientset // Declare clientset at the package level
	listOptions 		= metav1.ListOptions{}
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
	fmt.Printf("Kubeconfig at: ", *kubeconfig)
	// build configuration from the config file.
	config, err := clientcmd.BuildConfigFromFlags("", *kubeconfig)
	if err != nil {
		panic(err)
	}
	// create kubernetes clientset. this clientset can be used to create,delete,patch,list etc for the kubernetes resources
	clientset, err = kubernetes.NewForConfig(config)
	if err != nil {
		panic(err)
	}
	
	nodesWatcher, err := clientset.CoreV1().Nodes().Watch(context.Background(), listOptions)
	if err != nil {
		fmt.Printf("Error getting deployments: %v\n", err)
		os.Exit(1)
	}
	nodesChannel := nodesWatcher.ResultChan()
	for event := range nodesChannel {
		node, ok := event.Object.(*core.Node)
		if (!ok) { 
			log.Fatal(err)
		}
		switch event.Type{
			case watch.Added:
				log.Printf("Node %s added \n", node.Name)
			case watch.Deleted:
				log.Printf("Node %s deleted \n", node.Name)
			case watch.Modified:
				log.Printf("Node %s modified \n", node.Name)
		}
	}
}