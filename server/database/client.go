package database

import (
	supabase "github.com/supabase-community/supabase-go"
)

var client *supabase.Client

// ClientSetup setups the database client, using the URL and API key.
// Returns an error if it fails.
func ClientSetup() error {
	got, err := supabase.NewClient(EnvDatabaseUrl(), EnvDatabaseApiKey(), nil)
	if err != nil {
		return err
	}
	client = got
	return nil
}
