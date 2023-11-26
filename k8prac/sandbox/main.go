package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"
	"os"
	"os/exec"
	"log"
	"time"

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

	fmt.Printf("Kubeconfig at: ", *kubeconfig)

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
				checkAddedStatus(deployment)
			case watch.Deleted:
				log.Printf("Deployment %s deleted \n", deployment.Name)
			case watch.Modified:
				log.Printf("Deployment %s modified \n", deployment.Name)
				if deployment.Status.ReadyReplicas == 0 {
					fmt.Printf("Deployment %s has 0 number of ready replicas, waiting to see if it'll spawn\n", deployment.Name)
					cmd := exec.Command("kubectl", "rollout", "undo", "deployment", deployment.Name)
					err := cmd.Run()
					if err != nil {
						fmt.Printf("Error executing command: %v\n", err)
						return
					}
					time.Sleep(20 * time.Second)
				}
		}
	}
}

func checkAddedStatus(deployment *v1.Deployment) {
	fmt.Printf("Number of replicas: %d\n", deployment.Status.ReadyReplicas)
}