/*
 *  PassengerQueue.h
 *  Catelin Smith (csmith48)
 *  10/1/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to initialize the PassengerQueue class. The class
 *           will start out with an empty list and can have
 *           Passengers added to the back or removed from the
 *           front
 *
 */

#ifndef PASSENGER_QUEUE_H
#define PASSENGER_QUEUE_H
#include "Passenger.h"
#include <sstream>
#include <list>

class PassengerQueue {
public:
    Passenger front();
    void dequeue();
    void enqueue(const Passenger &passenger);
    int size();
    void print(std::ostream &output);

private:
    // a queue made of a linked list of 
    // passenger elements
    
    std::list<Passenger> queue;
};

#endif