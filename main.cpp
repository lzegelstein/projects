#include <_stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
//#include "air_travel.hpp"
#include "AirTravel.h"

Airport* findBusiestAirport() {
    // will use begin() & end(() to get an iterator for the AirportList map;
    // go through the map and find the airport with the largest number of links
    // ties get broken arbitrarily

    return NULL;
}

bool isThereADirectFlight(const std::string & start, const std::string & end) {
    return false;
}


//"/Users/lylazegelstein/Desktop/airportnames.csv"
int main(int argc, char** argv) {
    std::cout << "AirTravel application started" << std::endl;
    AirTravel ourmap("/Users/lylazegelstein/Desktop/airports-short.csv", "/Users/lylazegelstein/Desktop/routes-short.csv");
    
    std::string starting_point("ORD");
    std::string ending_point("JFK");
    
    std::cout << "Retreiving airport data for " << starting_point << std::endl;
    AirTravel::Airport* start = ourmap.IATAsearch(starting_point);
    
    std::cout << "Retreiving airport data for " << ending_point << std::endl;
    AirTravel::Airport* end = ourmap.IATAsearch(ending_point);
    
    // TODO - print out airport code, full name of airport and it's latitude and longitude and lastly the distance between the as the 787 flies.
    
    // Optional - work in progress - find a route between the 2 locations with zero or 1 stop.
    
    /*
     answer questions 1 and 2 today from project proposal
     */
    
    // find busiest & is there a direct flight calls with output here
    
    std::cout << "AirTravel application ended" << std::endl;
    return 0;
}
