package database

import "github.com/dywoq/voidmare/server/env"

type Database struct {
	env *env.Management
}

// EnvSetup sets the environment variable requirements needed by the database,
// and performs checking.
// 
// Returns an error if checking fails.
func (d *Database) EnvSetup() error {
	d.env.SetRequirement("DATABASE_URL")
	d.env.SetRequirement("DATABASE_API_KEY")
	return d.env.Check()
}

// Url returns the database URL.
// Use it after running EnvSetup.
func (d *Database) Url() string {
	return d.env.Get("DATABASE_URL")
}

// ApiKey returns the database API key.
// Use it after running EnvSetup.
func (d *Database) ApiKey() string {
	return d.env.Get("DATABASE_API_KEY")
}
