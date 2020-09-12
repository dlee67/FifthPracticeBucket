package main

import (
	"fmt"
	"net/http"
)

func index(w http.ResponseWriter, req *http.Request) {
	w.Header().Set("Access-Control-Allow-Origin", "*")
    w.Header().Set("Access-Control-Allow-Methods", "*")
    w.Header().Set("Access-Control-Allow-Headers", "*")
    w.Header().Set("Access-Control-Expose-Headers", "*")
	fmt.Fprintf(w, "AmpRobotics")
}

func main() {
	http.HandleFunc("/", index)
	http.ListenAndServe(":8080", nil)
}
