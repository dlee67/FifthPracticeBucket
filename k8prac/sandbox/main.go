package main

import (
	"context"
	"flag"
	"fmt"
	"path/filepath"

	appsv1 "k8s.io/api/apps/v1"
	apiv1 "k8s.io/api/core/v1"
	metav1 "k8s.io/apimachinery/pkg/apis/meta/v1"
	"k8s.io/client-go/kubernetes"
	"k8s.io/client-go/tools/clientcmd"
	"k8s.io/client-go/util/homedir"
)

func main() {
	var kubeconfig *string
	// https://pkg.go.dev/k8s.io/client-go/util/homedir
	// Returns the homedirectory of the current user.
	if home := homedir.HomeDir(); home != "" {
		fmt.Println("In home not empty")
		kubeconfig = flag.String("kubeconfig", filepath.Join(home, ".kube", "config"), "(optional) absolute path to the kubeconfig file")
		fmt.Println("kubeconfig in: ", kubeconfig)
	} else {
		fmt.Println("In home is empty")
		kubeconfig = flag.String("kubeconfig", "", "absolute path to the kubeconfig file")
		fmt.Println("kubeconfig in: ", kubeconfig)
	}
	// https://pkg.go.dev/flag
	flag.Parse()
	// All of the information, such as the kube-apiserver endpoint, its port, 
	// and the client certificate used to authenticate against kube-apiserver, must be written in this file called Kubeconfig.

	// https://pkg.go.dev/k8s.io/client-go/tools/clientcmd#BuildConfigFromFlags
	config, err := clientcmd.BuildConfigFromFlags("", *kubeconfig)
	if err != nil {
		panic(err)
	}
	// https://pkg.go.dev/k8s.io/client-go/kubernetes#NewForConfig
	clientset, err := kubernetes.NewForConfig(config)
	if err != nil {
		panic(err)
	}

	// https://pkg.go.dev/k8s.io/client-go/kubernetes#Clientset.AppsV1
	deploymentsClient := clientset.AppsV1().Deployments(apiv1.NamespaceDefault)

	deployment := &appsv1.Deployment{
		ObjectMeta: metav1.ObjectMeta{
			Name: "demo-deployment",
		},
		Spec: appsv1.DeploymentSpec{
			Replicas: int32Ptr(2),
			Selector: &metav1.LabelSelector{
				MatchLabels: map[string]string{
					"app": "demo",
				},
			},
			Template: apiv1.PodTemplateSpec{
				ObjectMeta: metav1.ObjectMeta{
					Labels: map[string]string{
						"app": "demo",
					},
				},
				Spec: apiv1.PodSpec{
					Containers: []apiv1.Container{
						{
							Name:  "web",
							Image: "nginx:1.12",
							Ports: []apiv1.ContainerPort{
								{
									Name:          "http",
									Protocol:      apiv1.ProtocolTCP,
									ContainerPort: 80,
								},
							},
						},
					},
				},
			},
		},
	}

	// Create Deployment
	fmt.Println("Creating deployment...")
	result, err := deploymentsClient.Create(context.TODO(), deployment, metav1.CreateOptions{})
	if err != nil {
		panic(err)
	}
	fmt.Printf("Created deployment %q.\n", result.GetObjectMeta().GetName())

	// fmt.Println("Deleting deployment...")
	// deletePolicy := metav1.DeletePropagationForeground
	// if err := deploymentsClient.Delete(context.TODO(), "demo-deployment", metav1.DeleteOptions{
	// 	PropagationPolicy: &deletePolicy,
	// }); err != nil {
	// 	panic(err)
	// }
	// fmt.Println("Deleted deployment.")
}

func int32Ptr(i int32) *int32 { return &i }