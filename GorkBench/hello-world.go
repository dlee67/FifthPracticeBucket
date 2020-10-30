package main

	
import (
    "os"
    "os/exec"
)

func main() {
    cmd := exec.Command("echo", "Hello, World!")
    testFile, err := os.Create("text.txt")
    if err != nil {
        panic(err)
    }
    cmd.Stdout = testFile

    err = cmd.Start();
    if err != nil {
        panic(err)
    }
    cmd.Wait()
}