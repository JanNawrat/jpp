#include <iostream>
#include <cstdlib>
#include <thread>
#include <random>
#include <chrono>
#include <functional>
#include "monitor.hpp"

void philosopher(int i, int numberOfMeals, std::function<int()> randomWaitTime, Monitor& monitor) {
    for(int j = 0; j < numberOfMeals; j++) {
        // think
        std::this_thread::sleep_for( std::chrono::milliseconds(randomWaitTime()) );
		monitor.takeFork(i);
        // eat
        std::this_thread::sleep_for( std::chrono::milliseconds(randomWaitTime()) );
		monitor.releaseFork(i);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Format: go run [main] numberOfPhilosophers numberOfMeals maxWaitTime" << std::endl;
        return 1;
    }
    int numberOfPhilisophers = std::atoi(argv[1]);
    int numberOfMeals = std::atoi(argv[2]);
    int maxWaitTime = std::atoi(argv[3]);

	// initialize monitor
	Monitor monitor = Monitor(numberOfPhilisophers, numberOfMeals);

	// initialize randomizer
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, maxWaitTime);
    auto randomWaitTime = [&dist, &gen]() -> int {
        return dist(gen);
    };

    // start philosophers
    std::vector< std::thread > philosophers;
    for(int i = 0; i < numberOfPhilisophers; i++) {
        std::thread t(philosopher, i, numberOfMeals, randomWaitTime, std::ref(monitor));
        philosophers.push_back(std::move(t));
    }

    // wait for philosophers to finish
    for(int i = 0; i < numberOfPhilisophers; i++) {
        philosophers[i].join();
    }

	return 0;
}
