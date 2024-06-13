package main

import (
	"context"
	"os"
	"strconv"
	"sync"
	L "zad1/lib"
)

func main() {
	if len(os.Args) != 4 {
		println("Format: go run [main] numberOfPhilosophers numberOfMeals maxWaitTime")
		os.Exit(1)
	}
	numberOfPhilosophers, err := strconv.Atoi(os.Args[1])
	if err != nil {
		println("Format: go run [main] numberOfPhilosophers numberOfMeals maxWaitTime")
		os.Exit(1)
	}
	numberOfMeals, err := strconv.Atoi(os.Args[2])
	if err != nil {
		println("Format: go run [main] numberOfPhilosophers numberOfMeals maxWaitTime")
		os.Exit(1)
	}
	maxWaitTime, err := strconv.Atoi(os.Args[3])
	if err != nil {
		println("Format: go run [main] numberOfPhilosophers numberOfMeals maxWaitTime")
		os.Exit(1)
	}

	ct := context.Background()
	ctx, cancelCtx := context.WithCancel(ct)

	monitor := L.NewMonitor(ctx, numberOfPhilosophers)

	var wg sync.WaitGroup
	reportChannel := make(chan int, numberOfPhilosophers)

	wg.Add(1)
	go L.Roster(numberOfPhilosophers, numberOfMeals, reportChannel, &wg)

	for i := 0; i < numberOfPhilosophers; i++ {
		wg.Add(1)
		go L.Philosopher(i, numberOfMeals, maxWaitTime, &monitor, reportChannel, &wg)
	}

	wg.Wait()
	cancelCtx()
}
