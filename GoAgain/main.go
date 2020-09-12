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
	// These three request headers are the characteristics you see
	// in CORS request. The first CORS request will always
	// be an OPTIONS pre-flight request.
	if (*request).Method = "OPTIONS" && 
		req.Header.Get("Origin") != "" && 
		req.Header.Get("Access-Control-Request-Method") {
		return
	}
	fmt.Fprintf(w, "AmpRobotics")
}

func main() {
	http.HandleFunc("/", index)
	http.ListenAndServe(":8080", nil)
}
