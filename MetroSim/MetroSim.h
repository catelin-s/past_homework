/*
 *  MetroSim.h
 *  Catelin Smith (csmith48)
 *  10/3/23
 *
 *  CS 15 Project 1 MetroSim
 *
 *  Purpose: to initialize the MetroSim class. This class
 *           will contain two vectors of type PassengerQueue
 *           that will hold the passengers on the train and
 *           at the stations
 *
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_

#include "Passenger.h"
#include "PassengerQueue.h"
#include <sstream>
#include <vector>
#include <string>


class MetroSim
{
public:
    MetroSim(int station_num);
    
    void add_station(std::string station_name);
    void user_command(std::ostream &output, std::istream &input);

private:
    // adds or removes passengers
    void exit_train(int index, std::ostream &stream);
    void add_passenger(int index, Passenger rider, 
    std::vector<PassengerQueue> &queue_vector);

    // aids user interaction (prints information, commands, etc.)
    void print(std::ostream &output);
    void print_screen();
    void p_command(std::istream &input);
    void mm_command(std::ostream &stream);

    //holds passengers on the train
    std::vector<PassengerQueue> train;

    //holds passengers waiting at stations
    std::vector<PassengerQueue> stations;

    std::vector<std::string> station_names;

    int current_station;
    int total_stations;
    int total_passengers;
};

#endif
