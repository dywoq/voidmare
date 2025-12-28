package database

import "github.com/dywoq/voidmare/server/env"

type Database struct {
	env *env.Management
}

func New() *Database {
	return &Database{
		env: &env.Management{},
	}
}

// Setup runs all steps that are needed to make database function normally.
// Recommended to run before using it.
func (d *Database) Setup() error {
	if err := d.envSetup(); err != nil {
		return err
	}
	return nil
}

// Url returns the database URL.
// Use it after running Setup.
func (d *Database) Url() string {
	return d.env.Get("DATABASE_URL")
}

// ApiKey returns the database API key.
// Use it after running Setup.
func (d *Database) ApiKey() string {
	return d.env.Get("DATABASE_API_KEY")
}

// related to setup

func (d *Database) envSetup() error {
	d.env.SetRequirement("DATABASE_URL")
	d.env.SetRequirement("DATABASE_API_KEY")
	return d.env.Check()
}
