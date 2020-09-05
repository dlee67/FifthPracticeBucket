package main

import (
	"fmt"
	"github.com/gorilla/mux"
	"log"
	"net/http"
	"time"
)

func ArticleHandler(w http.ResponseWriter, r *http.Request) {
	w.WriteHeader(http.StatusOK)
	fmt.Fprintf(w, "valid request")
}

func main() {
	// Create a new router
	r := mux.NewRouter()
	// Attach an elegant path with handler
	// https://stackoverflow.com/questions/6564558/wildcards-in-the-pattern-for-http-handlefunc
	// But Gorillamux is different.
	// https://godoc.org/github.com/gorilla/mux
	// They explicitly state that I can pass in a regular expression.
	r.HandleFunc("/products/{[0-9]+}", ArticleHandler)
	srv := &http.Server{
		Handler: r,
		Addr:    "127.0.0.1:8080",
		// Good practice: enforce timeouts for servers you create!
		WriteTimeout: 15 * time.Second,
		ReadTimeout:  15 * time.Second,
	}
	log.Fatal(srv.ListenAndServe())
}
