package database

import "github.com/dywoq/voidmare/server/env"

var envManagement = &env.Management{}

// EnvSetup setups the environment variables requirements,
// and checks if environment variables are set.
func EnvSetup() error {
	envManagement.SetRequirement("DATABASE_API_KEY")
	envManagement.SetRequirement("DATABASE_URL")
	return envManagement.Check()
}

func EnvDatabaseApiKey() string {
	return envManagement.Get("DATABASE_API_KEY")
}

func EnvDatabaseUrl() string {
	return envManagement.Get("DATABASE_URL")
}
