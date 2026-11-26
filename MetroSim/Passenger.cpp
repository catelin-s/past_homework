/*
 *  Passenger.cpp
 *  Catelin Smith (csmith48)
 *  10/1/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to define the functions in the Passenger struct
 *
 */

#include <iostream>
#include <string>
#include "Passenger.h"

/*
 * name:      print
 * purpose:   to print out a passenger's information
 * arguments: the address of an ostream
 * returns:   none
 * effects:   assigns a string containing the passenger's
 *            number, station entered, and station left
 *            to an output
 */

void Passenger::print(std::ostream &output)
{
    output << "[" << id << ", " << from << "->" << to << "]";
}
