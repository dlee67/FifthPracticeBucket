package main

import (
	"fmt"
	"time"
)

func SendValue(c chan string, name string) {
	c <- name
}

func main() {
	fmt.Println("Go channels Tutorial")

	values := make(chan string, 3) // https://www.youtube.com/watch?v=e4bu9g-bYtg
	defer close(values) // https://www.digitalocean.com/community/tutorials/understanding-defer-in-go
						// https://gobyexample.com/closing-channels
	go SendValue(values, "One")
	go SendValue(values, "Two")
	go SendValue(values, "Three")

	value := <- values
	fmt.Println(value)

	time.Sleep(1 * time.Second)

	secondValue := <- values
	fmt.Println(secondValue)

	time.Sleep(1 * time.Second)

	thirdValue := <- values
	fmt.Println(thirdValue)
}