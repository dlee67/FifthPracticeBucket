package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"

	core "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
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

	// build the pod defination we want to deploy
	pod := getPodObject()

	// now create the pod in kubernetes cluster using the clientset
	// https://pkg.go.dev/context
	// I am guessing context is like a semaphor?
	// https://pkg.go.dev/k8s.io/apimachinery/pkg/apis/meta/v1
	pod, err = clientset.CoreV1().Pods(pod.Namespace).Create(context.TODO(), pod, metav1.CreateOptions{})
	if err != nil {
		panic(err)
	}
	fmt.Println("Pod created successfully...")

	// err = clientset.CoreV1().Pods(pod.Namespace).Delete(context.TODO(), pod.Name, metav1.DeleteOptions{})
	// if err != nil {
	// 	panic(err)
	// }
	// fmt.Println("Pod delete successfully...")
}

// Referring the book: "Kubernetes Programming with Go: Programming Kubernetes Clients and Operators Using Go and the Kubernetes API"
// The ObjectMeta structure is defined as follows (deprecated fields as well as internal fields have been removed):
// Type ObjectMeta {
//     Name                string
//     GenerateName        string
//     Namespace           string
//     UID                 types.UID
//     ResourceVersion     string
//     Generation          int64
//     Labels              map[string]string
//     Annotations         map[string]string
//     OwnerReferences     []OwnerReference
//     [...]
// }
func getPodObject() *core.Pod {
	return &core.Pod{
		ObjectMeta: metav1.ObjectMeta{
			Name:      "my-test-pod",
			Namespace: "default",
			Labels: map[string]string{
				"app": "demo",
			},
		},
		Spec: core.PodSpec{
			Containers: []core.Container{
				{
					Name: "your-cave",
					Image: "nginx",
					ImagePullPolicy: core.PullIfNotPresent,
				},
			},
		},
	}
}