#########################################################
#             PROJECT 1: MetroSim Makefile             #
#########################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -Wpedantic -Wshadow
LDFLAGS  = -g3 

# link the .o files together to create MetroSim
MetroSim: Passenger.o PassengerQueue.o MetroSim.o main.o
	$(CXX) $(LDFLAGS) -o $@ $^


# builds Passenger.o
Passenger.o: Passenger.cpp Passenger.h

# This rule builds PassengerQueue.o
PassengerQueue.o: PassengerQueue.cpp PassengerQueue.h Passenger.h 
	$(CXX) $(CXXFLAGS) -c PassengerQueue.cpp

# builds MetroSim.o
MetroSim.o: MetroSim.cpp MetroSim.h PassengerQueue.h Passenger.h

# builds main.o
main.o: main.cpp MetroSim.h PassengerQueue.h Passenger.h


# link .o files together to create unit_test
unit_test: unit_test_driver.o PassengerQueue.o Passenger.o MetroSim.o
	$(CXX) $(CXXFLAGS) $^

# remove executables, object code, and temporary files from the current folder 
# -- the executable created by unit_test is called a.out
clean: 
	rm -f MetroSim *.o *~
