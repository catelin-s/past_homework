/*
 *  MetroSim.cpp
 *  Catelin Smith (csmith48)
 *  10/3/23
 *
 *  CS 15 Project 1: MetroSim
 *
 *  Purpose: to open the provided files, output errors
 *           when needed, and create an interactive 
 *           metro simulator
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"

using namespace std;

MetroSim open_stations(ifstream &stream, string filename);

template<typename streamtype>
void open_or_die(streamtype &stream, string filename);

int main(int argc, char *argv[])
{   // error if file number is wrong
    if (argc < 3 or argc > 4) {
        cerr << "Usage: ./MetroSim stationsFile outputFile [commandsFile]";
        cerr << endl;
        exit(EXIT_FAILURE);
    }

    ifstream instream, command_stream;
    ofstream outstream;

    // open necessary files
    if (argc > 3){
        open_or_die(command_stream, argv[3]);
    }

    // read in stations
    MetroSim current_sim = open_stations(instream, argv[1]);
    open_or_die(outstream, argv[2]);

    // run MetroSim
    if (argc < 4){
        current_sim.user_command(outstream, cin);
    } else {
        current_sim.user_command(outstream, command_stream);
        command_stream.close();
    }

    outstream.close();
    return 0;
}

/*
 * name:      open_stations
 * purpose:   opens the station file, reads in the
 *            station names, and determines the number
 *            of stations
 * arguments: an address of an ifstream and a string
 *            containing the file's name
 * returns:   a MetroSim
 * effects:   creates a MetroSim with the number of
 *            stations in the station file
 */

MetroSim open_stations(ifstream &stream, string filename){
    open_or_die(stream, filename);
    string station;
    int tot_stations = 0;

    std::vector<string> station_vector;

    // count number of stations and take in their names
    while (getline(stream, station)){
        tot_stations++;
        station_vector.push_back(station);
    }

    // create a MetroSim with those stations
    MetroSim read_sim(tot_stations);

    for (int i = 0; i < tot_stations; i++){
        read_sim.add_station(station_vector.at(i));
    }

    stream.close();
    return read_sim;
}

/*
 * name:      open_or_die
 * purpose:   attempts to open a file; if it does not
 *            open, it creates an error
 * arguments: the address of a stream of any type and
 *            a string that contains the file's name
 * returns:   none
 * effects:   either opens the file or prints out an
 *            error if unsuccessful
 */

template<typename streamtype>
void open_or_die(streamtype &stream, string filename){
    stream.open(filename);
    if (not stream.is_open()){
        cerr << "Error: could not open file " << filename << endl;
        exit(EXIT_FAILURE);
    }
}
