package main

import (
	"log"
	"os"

	"github.com/dywoq/voidmare/server/database"
)

func main() {
	if err := database.EnvSetup(); err != nil {
		log.Printf("failed to setup database environment variables: %v", err)
		os.Exit(1)
	}
	if err := database.ClientSetup(); err != nil {
		log.Printf("failed to setup database client: %v", err)
		os.Exit(1)
	}
}
