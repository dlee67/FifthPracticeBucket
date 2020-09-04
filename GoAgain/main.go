package main

import (
	"fmt"
	"net/http"
	"time"
	"strings"
)

func main() {
	http.HandleFunc("/", func(w http.ResponseWriter, r *http.Request) {
		urlPathElements := strings.Split(r.URL.Path, "/")
		fmt.Println("first element of split at: " + urlPathElements[0])
	})
	s := &http.Server{
		Addr: ":8000",
		ReadTimeout: 10 * time.Second,
		WriteTimeout: 10 * time.Second,
		MaxHeaderBytes: 1 << 20,
	}
	s.ListenAndServe()
}