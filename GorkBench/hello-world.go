package main

	
import (
    "fmt"
    "log"
    "os"
    "os/exec"
)

func main() {
    userInputs := os.Args
    if len(userInputs) < 3 {
        fmt.Println("Gorkbench v 0.0.1 \n\n\n" + 
                    "Commands:\n\n" +
                    "Angular - Installs npm and ng cli if there aren't any.\n\n" +
                    "Android - Installs JDK and Android Studio if there aren't any.\n\n")
        return
    }

    app := userInputs[1]
    command := userInputs[2]

    fmt.Printf("App at: %s    Command at: %s", app, command)
    out, err := exec.Command(app, command).Output()
    if err != nil {
        log.Fatal(err)
    }
    fmt.Printf("%s\n", out)
    return
}