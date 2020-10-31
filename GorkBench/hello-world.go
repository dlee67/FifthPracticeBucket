package main

	
import (
    "fmt"
    "log"
    "os/exec"
)

func main() {
    out, err := exec.Command("echo", "Hello, World!").Output()
    if err != nil {
        log.Fatal(err)
    }
    fmt.Printf("%s", out)
}