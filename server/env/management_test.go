package env_test

import (
	"testing"

	"github.com/dywoq/voidmare/server/env"
)

func TestSetRequirementAndCheckSuccess(t *testing.T) {
	m := &env.Management{}
	envVar := "TEST_ENV_VAR"
	t.Setenv(envVar, "value")

	m.SetRequirement(envVar)

	if err := m.Check(); err != nil {
		t.Fatalf("expected check to pass, got error: %v", err)
	}

	val := m.Get(envVar)
	if val != "value" {
		t.Fatalf("expected value 'value', got %s", val)
	}
}

func TestCheckWithMissingVariables(t *testing.T) {
	m := &env.Management{}
	existingVar := "EXISTING_VAR"
	missingVar := "MISSING_VAR"
	t.Setenv(existingVar, "val")

	m.SetRequirement(existingVar)
	m.SetRequirement(missingVar)

	err := m.Check()
	if err == nil {
		t.Fatalf("expected error due to missing variable")
	}
}

func TestGetBeforeCheckPanics(t *testing.T) {
	m := &env.Management{}
	defer func() {
		if r := recover(); r == nil {
			t.Fatalf("expected panic when calling Get before Check")
		}
	}()
	m.Get("ANY_VAR")
}

func TestGetAfterFailedCheckPanics(t *testing.T) {
	m := &env.Management{}
	m.SetRequirement("MISSING_VAR")
	_ = m.Check() // expected to fail
	defer func() {
		if r := recover(); r == nil {
			t.Fatalf("expected panic when calling Get after failed Check")
		}
	}()
	m.Get("MISSING_VAR")
}

func TestSetRequirementAfterCheckPanics(t *testing.T) {
	m := &env.Management{}
	m.Check()
	defer func() {
		if r := recover(); r == nil {
			t.Fatalf("expected panic when calling SetRequirement after Check")
		}
	}()
	m.SetRequirement("VAR")
}
