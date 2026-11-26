/*
 *  PassengerQueue.cpp
 *  Catelin Smith (csmith48)
 *  10/1/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to define the functions of the PassengerQueue class
 *
 */

#include "PassengerQueue.h"
#include <list>

/*
 * name:      front
 * purpose:   to find and return the first element in the queue
 * arguments: none
 * returns:   a Passenger that is the first in the queue
 * effects:   none
 */

Passenger PassengerQueue::front(){
    return queue.front();
}

/*
 * name:      dequeue
 * purpose:   to remove the first element in the queue
 * arguments: none
 * returns:   none
 * effects:   removes a passenger from the front of the queue,
 *            size will decrease by one
 */

void PassengerQueue::dequeue(){
    queue.pop_front();
}

/*
 * name:      enqueue
 * purpose:   add an element to the back of the queue
 * arguments: the address of a passenger that will be added
 * returns:   none
 * effects:   adds a passenger to the back of the queue, size
 *            will increase by one
 */

void PassengerQueue::enqueue(const Passenger &passenger){
    queue.push_back(passenger);
}

/*
 * name:      size
 * purpose:   find and return the amount of elements in the queue
 * arguments: none
 * returns:   an integer representing the size of the queue
 * effects:   none
 */

int PassengerQueue::size(){
    return queue.size();
}

/*
 * name:      print
 * purpose:   print out the information of the passengers in 
 *            the queue in order
 * arguments: the address of an ostream 
 * returns:   none
 * effects:   outputs strings that contain each passenger's 
 *            information (id, arrived at station, depart
 *            from station) in the order that they exist
 *            in the queue
 */

void PassengerQueue::print(std::ostream &output){
    // use an iterator function that starts at the first
    // element and loops through the linked list, printing
    // out each passenger element as it goes
    
    for (std::list<Passenger>::iterator it = queue.begin(); 
    it != queue.end(); it++){
        it->print(output);
    }
}