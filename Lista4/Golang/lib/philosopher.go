package lib

import (
	"math/rand"
	"sync"
	"time"
)

func Philosopher(i, numberOfMeals, waitTime int, m *Monitor, reportChannel chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	for j := 0; j < numberOfMeals; j++ {
		// think
		time.Sleep(time.Duration(rand.Intn(waitTime)) * time.Millisecond)
		// grab forks
		m.TakeFork(i)
		// eat
		reportChannel <- i
		time.Sleep(time.Duration(rand.Intn(waitTime)) * time.Millisecond)
		// release forks
		m.ReleaseFork(i)
		reportChannel <- i
	}
}
