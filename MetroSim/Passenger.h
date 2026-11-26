/*
 *  Passenger.h
 *  Catelin Smith (csmith48)
 *  10/1/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to initialize the Passenger struct. This struct
 *           will contain the ID, destination, and the station
 *           the passenger entered the train at
 *
 */
 

#ifndef __PASSENGER_H__
#define __PASSENGER_H__

#include <iostream>

struct Passenger
{

        int id, from, to;
        
        Passenger()
        {
                id   = -1;
                from = -1;
                to   = -1;
        }

        Passenger(int newId, int arrivalStation, int departureStation)
        {
                id   = newId;
                from = arrivalStation;
                to   = departureStation;
        }

        void print(std::ostream &output);

};

#endif
