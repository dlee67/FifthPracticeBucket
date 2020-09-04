package main

import (
	"fmt"
	"strconv"
)

func Intn(n int) int {
	fmt.Println("In the Intn function")
	return n
}

func main() {
	fmt.Println("hello world")
	fmt.Println("Passing in: " + string(Intn(5)))
}