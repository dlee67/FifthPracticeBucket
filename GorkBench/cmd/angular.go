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
	},
}

func angular() {
	out, err := exec.Command("apt", "update").Output()
	if err != nil {
		fmt.Println(err)
	} 
	fmt.Printf("%s\n", out)
	out, err = exec.Command("apt", "install nodejs").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
	out, err = exec.Command("apt", "install npm").Output()
	if err != nil {
		fmt.Println(err)
	}
	fmt.Printf("%s\n", out)
}

func init() {
	rootCmd.AddCommand(addCmd)
}