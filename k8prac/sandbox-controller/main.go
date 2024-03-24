package main

import (
    "context"
    "fmt"
	"flag"
	"path/filepath"

    metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	corev1 "k8s.io/api/core/v1"
    "k8s.io/apimachinery/pkg/watch"
    "k8s.io/client-go/kubernetes"
    "k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
)

func listNodes(clientset *kubernetes.Clientset) {
	nodes, err := clientset.CoreV1().Nodes().List(context.TODO(), metav1.ListOptions{})
	if err != nil {
		fmt.Printf("Error listing nodes: %v\n", err)
		return
	}
	fmt.Println("Listing nodes at the start:")
	for _, node := range nodes.Items {
		fmt.Printf("Node Name: %s\n", node.Name)
	}
}

func watchNodes(clientset *kubernetes.Clientset) {
    watcher, err := clientset.CoreV1().Nodes().Watch(context.TODO(), metav1.ListOptions{})
    if err != nil {
        fmt.Printf("Error watching nodes: %v\n", err)
        return
    }
    defer watcher.Stop()

    for event := range watcher.ResultChan() {
        switch event.Type {
        case watch.Modified:
            node, ok := event.Object.(*corev1.Node)
            fmt.Printf("Node %s modified\n", node.Name)
			if !ok {
                fmt.Println("Unexpected type")
                continue
            }
            for _, condition := range node.Status.Conditions {
                if condition.Type == corev1.NodeReady && condition.Status != corev1.ConditionTrue {
                    fmt.Printf("Node %s is not ready\n", node.Name)
                    // Custom action here
                }
            }
        }
    }
}

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

    clientset, err := kubernetes.NewForConfig(config)
    if err != nil {
        panic(err.Error())
    }

	listNodes(clientset)

    // Start watching nodes
    go watchNodes(clientset)

    // Keep the main goroutine alive
    select {}
}
