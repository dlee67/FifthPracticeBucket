package cmd

import (
	"fmt"
	
	"github.com/spf13/cobra"
)

var addCmd = &cobra.Command{
	Use:   "Angular",
	Short: "A brief description of your command",
	Long: ``,
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("Gotta try to install necessary softwares for Angular.")
	},
}

func init() {
	rootCmd.AddCommand(addCmd)
}