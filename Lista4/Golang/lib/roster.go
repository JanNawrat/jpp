package lib

import "sync"

func Roster(numberOfPhilosophers int, numberOfMeals int, reportChannel chan int, wg *sync.WaitGroup) {
	defer wg.Done()
	roster := make([]bool, numberOfPhilosophers)
	mealsLeft := make([]int, numberOfPhilosophers)
	for i := range mealsLeft {
		mealsLeft[i] = numberOfMeals
	}
	for {
		finished := true
		for i := range mealsLeft {
			if mealsLeft[i] > 0 {
				finished = false
				break
			}
		}
		if finished {
			println("All philosophers finished their meals")
			return
		}

		i := <-reportChannel
		println("=============")
		roster[i] = !roster[i]
		if roster[i] {
			println("Philosopher", i, "started eating")
		} else {
			println("Philosopher", i, "stopped eating")
			mealsLeft[i] -= 1
			if mealsLeft[i] > 0 {
				println("Meals left:", mealsLeft[i])
			} else {
				println("Philosopher", i, "finished all of their meals")
			}
		}
		if roster[0] {
			print("(0")
		} else {
			print("(_")
		}
		for i := 1; i < numberOfPhilosophers; i++ {
			if roster[i] {
				print(", ", i)
			} else {
				print(", _")
			}
		}
		println(")")
	}
}
