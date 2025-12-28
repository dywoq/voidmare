package main

import (
	"log"

	"github.com/dywoq/voidmare/server/database"
)

func main() {
	db := database.New()
	if err := db.Setup(); err != nil {
		log.Printf("Failed to setup database")
	}
}
