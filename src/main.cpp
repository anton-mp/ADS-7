// Copyright 2022 NNTU-CS
#include <iostream>
#include <random>
#include "train.h"

void expAllOn(int n) {
    Train train;
    while (n--)
        train.addCar(true);
    train.getLength();
    std::cout << train.getOpCount() << " ";
}

void expAllOff(int n) {
    Train train;
    while (n--)
        train.addCar(false);
    train.getLength();
    std::cout << train.getOpCount() << " ";
}

void expAllRandom(int n) {
    Train train;
    unsigned int seed = static_cast<unsigned int>(time(NULL));
    while (n--)
        train.addCar(rand_r(&seed) % 2);
    train.getLength();
    std::cout << train.getOpCount() << " ";
}

int main() {
    std::cout << "On | Off | Random" << std::endl;
    for (int count = 2; count < 100; count++) {
        std::cout << count << ": ";
        expAllOn(count);
        expAllOff(count);
        expAllRandom(count);
        std::cout << std::endl;
    }
    return 0;
}
