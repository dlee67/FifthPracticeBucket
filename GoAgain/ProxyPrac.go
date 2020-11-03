package main

import (
    "net/http"    
)

func main() {
    // I need this if I am using a proxy.
    // https://golang.org/pkg/net/http/#Transport
    // transport := &http.Transport {
    //     Proxy: // Assign proxy function here like &http.ProxyURL()
    // }
    // The same transport object can be chucked into the http Client
    // https://golang.org/pkg/net/http/#Client
    // client := &http.Client{
    //     Transport: transport,
    // }

    // This is how I can make a new request.
    // https://golang.org/pkg/net/http/#NewRequest
    // newRequest, _ := http.NewRequest(request.method, url, request.body)
    // newRequest.SetBasicAuth() // this is how I can set an authentication for the requests.
    
    // If I have an object for it, I can make a request again.
    // https://golang.org/pkg/net/http/#Client.Do
    // response, _ := client.Do(newRequest)

    // I never knew that HTTP transactions can also be represented as an object.
    // https://golang.org/pkg/net/http/#RoundTripper
}