package main

import (
	"fmt"
	"encoding/json"
	"io/ioutil"
)

func main() {
	// When those members aren't capitalized, they don't work ...
	type Ace struct {
		Plane string `json:"plane"`
		Pilot string `json:"pilot"`
	}

	byteValue, _ := ioutil.ReadFile("pilot.json")
	
	var ace Ace
	json.Unmarshal(byteValue, &ace)

	fmt.Println(ace.Plane);
	fmt.Println(ace.Pilot);
}