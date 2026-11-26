/*
 *  MetroSim.cpp
 *  Catelin Smith (csmith48)
 *  10/3/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to define the functions in the MetroSim class
 *           that make it possible for the metro simulator
 *           to be edited and interacted with by the user
 *
 */

#include "MetroSim.h"
#include <string>
#include <sstream>

/*
 * name:      MetroSim constructor
 * purpose:   create a new MetroSim instance
 * arguments: an integer representing the number of
 *            stations
 * returns:   none
 * effects:   sets the current station it is on to
 *            zero, the number of passengers to zero,
 *            and changes the size of both the train
 *            and station vectors to the number of
 *            stations as well as the integer
 *            representing the latter
 */

MetroSim::MetroSim(int station_num){
    current_station = 0;
    total_passengers = 0;
    train.resize(station_num);
    stations.resize(station_num);
    total_stations = station_num;
}

/*
 * name:      add_station
 * purpose:   add the name of a station to the back of a
 *            vector containing station names
 * arguments: a string representing a station name
 * returns:   none
 * effects:   a string has been added to the back of
 *            a vector
 */

void MetroSim::add_station(std::string station_name){
    station_names.push_back(station_name);
}

/*
 * name:      exit_train
 * purpose:   to dequeue the passengers on the train who
 *            are at the PassengerQueue at that index
 *            and send this information to the output file
 * arguments: and integer representing a train index and 
 *            the address of an ostream
 * returns:   none
 * effects:   the PassengerQueue at that index is now empty;
 *            the output file contains a string detailing
 *            who exited the train and where
 */


void MetroSim::exit_train(int index, std::ostream &stream){
    // put the passenger number and the station they are leaving
    // into the output file until the passenger queue is empty

    PassengerQueue *current_queue = &(train.at(index));
    while (current_queue->size() != 0){
        stream << "Passenger " << current_queue->front().id;
        stream << " left train at station ";
        stream << station_names.at(current_station) << std::endl;
        current_queue->dequeue();
    }
}

/*
 * name:      add_passenger
 * purpose:   to enqueue a passenger to a vector of PassengerQueues
 *            at a specific index
 * arguments: a passenger to add
 * returns:   none
 * effects:   there is now an additional passenger at the
 *            back of a specific PassengerQueue in a vector;
 *            it will either be the PassengerQueue representing the
 *            passenger's arrival station if they are waiting for
 *            the train or the passenger's destination if they are
 *            boarding the train
 */


void MetroSim::add_passenger(int index, Passenger rider, 
std::vector<PassengerQueue> &queue_vector){
    PassengerQueue *current_queue = &(queue_vector.at(index));
    current_queue->enqueue(rider);
}

/*
 * name:      print
 * purpose:   to print out the train's information
 * arguments: the address of an ostream
 * returns:   none
 * effects:   assigns a string containing the information
 *            of the passengers on the train (in order of
 *            destination) to an output
 */

void MetroSim::print(std::ostream &output){
    // print out the passengers in each passenger queue on the
    // train in order from front to back

    for (std::vector<PassengerQueue>::iterator it = train.begin(); 
    it != train.end(); it++){
        it->print(output);
    }
}


/*
 * name:      print_screen
 * purpose:   to print out the home screen of MetroSim
 * arguments: none
 * returns:   none
 * effects:   outputs the passengers on the train, all of the
 *            stations in order, where the train is located,
 *            and which passengers are waiting at which
 *            stations
 *
 */

void MetroSim::print_screen(){
    std::cout << "Passengers on the train: {";
    print(std::cout);
    std::cout << "}" << std::endl;
    
    // print where the train is, all of the stations, and
    // passengers waiting at the stations

    for (int i = 0; i < total_stations; i++){
        if (i != current_station){
            std::cout << "       "; 
        } else {
            std::cout << "TRAIN: ";
        }

        std::cout << "[" << i << "] ";
        std::cout << station_names.at(i) << " {";
        (stations.at(i)).print(std::cout);
        std::cout << "}" << std::endl;
    }

    std::cout << "Command? ";
}

/*
 * name:      user_command
 * purpose:   to allow the user (or a command file) to interact with
 *            the simulation
 * arguments: the address of an ostream, the address of an istream
 * returns:   none
 * effects:   prints out the home screen and takes in a command;
 *            it will terminate when it reaches the end of the
 *            command file or when the command "m f" is given
 */


void MetroSim::user_command(std::ostream &output, std::istream &input){
    print_screen();
    std::string command1, command2;
    bool quit = false;
    input >> command1;
    while (not quit){
        if (input.eof()){
            quit = true;
        }
        if (command1 == "p"){
            p_command(input);
        } else if (command1 == "m"){
            input >> command2;
            if (command2 == "m"){
                mm_command(output);
            } else if (command2 == "f"){
                quit = true;
            }

            command1 = " ";
            command2 = " ";
        }
        if (not quit){
            print_screen();
            input >> command1;
        }
    }
    std::cout << "Thanks for playing MetroSim. Have a nice day!";
    std::cout << std::endl;
}

/*
 * name:      p_command
 * purpose:   to create a new passenger at a station
 * arguments: the address of an istream
 * returns:   none
 * effects:   takes in the given passenger information and
 *            adds a passenger to their arrival station
 */

void MetroSim::p_command(std::istream &input){
    total_passengers++;
    int arrival, departure;

    input >> arrival >> departure;
    Passenger new_passenger(total_passengers, arrival, departure);
    add_passenger(new_passenger.from, new_passenger, stations);
    
}

/*
 * name:      mm_command
 * purpose:   to move the train to the next station and
 *            takes in passengers or releases them
 * arguments: the address of an ostream
 * returns:   none
 * effects:   takes in passengers from the current station
 *            and then increases the current station integer
 *            by one; if passengers need to get off at this
 *            station, they leave
 *
 */

void MetroSim::mm_command(std::ostream &stream){
    PassengerQueue *current_queue = &(stations.at(current_station));

    // if there are passengers at the current station, add them
    // to the train

    if (current_queue->size() != 0){
        while(current_queue->size() != 0){
            Passenger front_passenger = current_queue->front();
            add_passenger(front_passenger.to, front_passenger, train);
            current_queue->dequeue();
        }
    } 

    // move to next station (or loop to first if at last)
    if (current_station == total_stations - 1){
        current_station = 0;
    } else {
        current_station++;
    }

    exit_train(current_station, stream);
}
