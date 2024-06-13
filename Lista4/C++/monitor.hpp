#ifndef MONITOR_HPP
#define MONITOR_HPP

#include <iostream>
#include <semaphore>
#include <vector>

class Monitor {
public:
    Monitor(int numberOfPhilosophers, int numberOfMeals);

    void takeFork(int i);

	void releaseFork(int i);
private:
	// monitor functionality
    int numberOfPhilosophers;
    std::binary_semaphore S{1};
    std::vector< int > Fork;
    std::vector< std::binary_semaphore * > okToEatS;
    std::vector< int > okToEatC;
	// roster functionality
	std::vector< bool > roster;
	std::vector< int > mealsLeft;

	void addToRoster (int i);

	void removeFromRoster (int i);
};

#endif