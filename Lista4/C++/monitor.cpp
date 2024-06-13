#include "monitor.hpp"

Monitor::Monitor(int numberOfPhilosophers, int numberOfMeals) {
    this->numberOfPhilosophers = numberOfPhilosophers;
    okToEatS = std::vector< std::binary_semaphore * >{static_cast<unsigned long>(numberOfPhilosophers)};
    for(int i = 0; i < numberOfPhilosophers; i++) {
        Fork.push_back(2);
        okToEatS[i] = new std::binary_semaphore{0};
        okToEatC.push_back(0);
        roster.push_back(false);
        mealsLeft.push_back(numberOfMeals);
    }
}

void Monitor::takeFork(int i) {
    int forkToTheLeft = (i + 1) % numberOfPhilosophers;
    int forkToTheRight = (numberOfPhilosophers + i - 1) % numberOfPhilosophers;
    S.acquire();
    if (Fork[i] != 2) {
        okToEatC[i] += 1;
        S.release();
        okToEatS[i]->acquire();
        S.acquire();
        okToEatC[i] -= 1;
    }
    Fork[forkToTheLeft] -= 1;
    Fork[forkToTheRight] -= 1;
    addToRoster(i);
    S.release();
}

void Monitor::releaseFork(int i) {
    int forkToTheLeft = (i + 1) % numberOfPhilosophers;
    int forkToTheRight = (numberOfPhilosophers + i - 1) % numberOfPhilosophers;
    S.acquire();
    Fork[forkToTheLeft] += 1;
    Fork[forkToTheRight] += 1;
    if (Fork[forkToTheLeft] == 2) {
        if (okToEatC[forkToTheLeft] != 0) {
            okToEatS[forkToTheLeft]->release();
        }
    }
    if (Fork[forkToTheRight] == 2) {
        if (okToEatC[forkToTheRight] != 0) {
            okToEatS[forkToTheRight]->release();
        }
    }
    removeFromRoster(i);
    S.release();
}

void Monitor::addToRoster (int i) {
    roster[i] = true;
    std::cout << "=============" << std::endl;
    std::cout << "Philosopher " << i << " started eating" << std::endl;
    if(roster[0]) {
        std::cout << "(0";
    } else {
        std::cout << "(_";
    }
    for(int j = 1; j <  numberOfPhilosophers; j++) {
        if(roster[j]) {
            std::cout << ", " << j;
        } else {
            std::cout << ", _";
        }
    }
    std::cout << ")" << std::endl;
}

void Monitor::removeFromRoster (int i) {
    roster[i] = false;
    mealsLeft[i] -=1;
    std::cout << "=============" << std::endl;
    std::cout << "Philosopher " << i << " stopped eating" << std::endl;
    if (mealsLeft[i] > 0) {
        std::cout << "Meals left: " << i << std::endl;
    } else {
        std::cout << "Philosopher " << i << " finished all of their meals" << std::endl;
    }
    if(roster[0]) {
        std::cout << "(0";
    } else {
        std::cout << "(_";
    }
    for(int j = 1; j <  numberOfPhilosophers; j++) {
        if(roster[j]) {
            std::cout << ", " << j;
        } else {
            std::cout << ", _";
        }
    }
    std::cout << ")" << std::endl;
}
