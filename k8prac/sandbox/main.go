package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"
	"os"
	"log"
	"slices"

	core "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	apps "k8s.io/api/apps/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
	"k8s.io/apimachinery/pkg/watch"
)

var (
	deploymentWatchList = []string{"your-app-deployment", ""}
	healthyNodes        = []string{}
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

	deploymentsWatcher, err := clientset.AppsV1().Deployments("").Watch(context.Background(), listOptions)
	if err != nil {
		fmt.Printf("Error getting deployments: %v\n", err)
		os.Exit(1)
	}	
	deploymentChannel := deploymentsWatcher.ResultChan()
	for event := range deploymentChannel {
		deployment, ok := event.Object.(*apps.Deployment)
		if (!ok) { 
			log.Fatal(err)
		}
		switch event.Type{
			case watch.Added:
				log.Printf("Deployment %s added \n", deployment.Name)
			case watch.Deleted:
				log.Printf("Deployment %s deleted \n", deployment.Name)
			case watch.Modified:
				log.Printf("Deployment %s modified \n", deployment.Name)
				if slices.Contains(deploymentWatchList, deployment.Name) {
					checkModifiedStatus(deployment)
				}
		}
	}
}

func checkModifiedStatus(deployment *apps.Deployment) {
	if deployment.Status.ReadyReplicas == 0 {
		fmt.Printf("Deployment %s has 0 number of ready replicas\n", deployment.Name)
		
		nodes, err := clientset.CoreV1().Nodes().List(context.Background(), listOptions)
		if err != nil {
			fmt.Printf("Error getting nodes: %v\n", err)
			return
		}

		for _, node := range nodes.Items {
			nodeName := node.Name
			ramCapacity := node.Status.Capacity.Memory().String()
			osImage := node.Status.NodeInfo.OSImage
			fmt.Printf("Node %s:\n", nodeName)
			fmt.Printf("RAM Capacity: %s\n", ramCapacity)
			fmt.Printf("Operating System: %s\n", osImage)
			// https://stackoverflow.com/questions/57343326/using-kubernetes-client-go-how-to-check-programatically-if-node-is-ready
			// This is actually the best practice that the community recommands.
			for _, condition := range node.Status.Conditions {
				fmt.Printf("\t%s: %s\n", condition.Type, condition.Status)
			}
		}
		return
	}
}