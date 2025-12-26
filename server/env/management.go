package env

import (
	"fmt"
	"os"
	"sync"
	"sync/atomic"
)

// Management is a thread-safe structure, responsible for managing
// environment variables.
type Management struct {
	checkingFailed    atomic.Bool
	checkingCompleted atomic.Bool
	mu                sync.Mutex
	requirements      []string
}

// SetRequirement sets new environment variable requirement.
// Panics if the checking have already completed or failed.
func (m *Management) SetRequirement(name string) {
	m.mu.Lock()
	defer m.mu.Unlock()
	m.panicIfWrong()
	m.requirements = append(m.requirements, name)
}

// Check performs the requirements check.
//
// If there are no set requirements, the function returns nil
// and marks the checking as completed.
//
// If there are any not satisfied requirements, Check returns
// an error.
//
// Panics if the checking completed, preventing double using.
func (m *Management) Check() error {
	m.mu.Lock()
	defer m.mu.Unlock()
	m.panicIfWrong()
	if len(m.requirements) == 0 {
		m.checkingCompleted.Store(true)
		return nil
	}
	missing := []string{}
	for _, req := range m.requirements {
		if _, ok := os.LookupEnv(req); !ok {
			missing = append(missing, req)
		}
	}
	m.checkingCompleted.Store(true)
	if len(missing) != 0 {
		m.checkingFailed.Store(true)
		return fmt.Errorf("missing environment variables: %v", missing)
	}
	return nil
}

// Get gets the environment variable value by name.
// Panics if the checking failed, or it wasn't completed.
func (m *Management) Get(name string) string {
	m.mu.Lock()
	defer m.mu.Unlock()
	if !m.checkingCompleted.Load() {
		panic("checking is not completed")
	}
	if m.checkingFailed.Load() {
		panic("checking failed")
	}
	return os.Getenv(name)
}

func (m *Management) panicIfWrong() {
	if m.checkingFailed.Load() {
		panic("checking failed")
	}
	if m.checkingCompleted.Load() {
		panic("checking already completed")
	}
}
