package cmd

import (
	"github.com/spf13/cobra"
	"fmt"
	"os/exec"
)

var addCmd = &cobra.Command{
	Use:   "Angular", // The actual command that'll be used.
	Short: "Installs the necessary software to get started in programming in Angular.",
	Long: `Installs npm and ng cli upon being executed. This command can be executed along with the option --all
			to also installs the ngrx, electron, and ngbootstrap.`,
	Run: func(cmd *cobra.Command, args []string) {
		
		getAll, _ := cmd.Flags().GetBool("all")

		if !getAll {
			angular()
		} else {
			angularAll()
		}
	},
}

func angular() {

	fmt.Println("Starting a regular installation")

	fmt.Println("Apt updating")
	out, err := exec.Command("apt", "update").Output()
	if err != nil {
		fmt.Println("Failed to apt update")
		fmt.Println(err)
	} 
	fmt.Printf("%s\n", out)
	
	fmt.Println("Installing npm")
	out, err = exec.Command("apt", "install", "npm").Output()
	if err != nil {
		fmt.Println("Failed to install npm")
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
	
	fmt.Println("Installing node")
	out, err = exec.Command("apt", "install", "nodejs").Output()
	if err != nil {
		fmt.Println("Failed to install node")
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)

	fmt.Println("Installing ng cli")
	out, err = exec.Command("npm", "install", "-g", "@angular/cli").Output()
	if err != nil {
		fmt.Println("Failed to install ng cli")
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
}

func angularAll() {

	fmt.Println("Installing with all")

	out, err := exec.Command("apt", "update").Output()
	if err != nil {
		fmt.Println(err)
	} 
	fmt.Printf("%s\n", out)

	out, err = exec.Command("apt", "install", "npm").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)

	out, err = exec.Command("apt", "install", "nodejs").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
	
	out, err = exec.Command("ng", "add", "@ngrx/store@latest").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)

	out, err = exec.Command("npm", "install", "electron", "--save-dev").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)

	nvmOut, err := exec.Command("curl", "-o-", "https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.0/install.sh").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", nvmOut)

	out, err = exec.Command("snap", "install", "postman").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
}

func init() {
	rootCmd.AddCommand(addCmd)
	addCmd.Flags().BoolP("all", "a",  false, "Install all the utilities I've usually use for Angular.")
}