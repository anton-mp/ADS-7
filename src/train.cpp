// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train(): first(nullptr), countOp(0) {}

void Train::addCar(bool light) {
    if (first) {
        Car* car = new Car;
        car->light = light;
        car->next = first;
        car->prev = first->prev;
        first->prev->next = car;
        first->prev = car;
    } else {
        first = new Car;
        first->light = light;
        first->next = first;
        first->prev = first;
    }
}

int Train::getLength() {
    countOp = 0;
    if (first == nullptr)
        return 0;

    Car* curr = first;
    curr->light = true;
    int count = 0;
    while (true) {
        curr = curr->next;
        ++count;
        ++countOp;
        while (!curr->light) {
            curr = curr->next;
            ++count;
            ++countOp;
        }
        curr->light = false;
        for (int i = 0; i < count; i++) {
            curr = curr->prev;
            ++countOp;
        }
        if (!curr->light)
            return count;
        count = 0;
    }
}

int Train::getOpCount() {
    return countOp;
}
