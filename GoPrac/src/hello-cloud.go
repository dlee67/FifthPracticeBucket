package main

import (
	"fmt"
	"net/http"
	"os"
	"./api"
)

func main() {
	// Passing in the function pointer.
	http.HandleFunc("/", index)
	// Passing in the function pointer.
	http.HandleFunc("./echo", echo)
	http.HandleFunc("./books", api.BooksHandleFunc)
	http.ListenAndServe(port(), nil)
}

func port() string {
	port := os.Getenv("PORT");
	if len(port) == 0 {
		port = "8080"
	}
	return ":" + port
}

func index(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	fmt.Fprintf(w, "Hello Cloud Native Go.")
}

func echo(w http.ResponseWriter, r *http.Request) {
	message := r.URL.Query()["message"][0] // Can chuck in something like /echo?message=....
	
	w.Header().Add("Content-type", "text/plain")
	fmt.Fprintf(w, message)
}