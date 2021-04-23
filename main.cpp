#include <_stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "air_travel.hpp"
/*
 Questions for mentor meeting:
 1. Is there a way to get around having to do AirTravel:: like in line for loop of findBusiestAirport()?
 */

/* NEXT STEPS:
 1. Fixing the runtime of BusiestAirport(). Right now it is O(N) but we will continuously update it as the destination vector is filled in. That is a task for not today though

 */

//"/Users/lylazegelstein/Desktop/airportnames.csv"
int main(int argc, char** argv) {
    std::cout << "AirTravel application started" << std::endl;
    AirTravel ourmap("/Users/lylazegelstein/Desktop/airports-short.csv", "/Users/lylazegelstein/Desktop/routes-short.csv");
    
    AirTravel::Airport* busiest = ourmap.findBusiestAirport();
    std::cout<<"busiest airport is "<<busiest->name<<std::endl;
    
    std::cout << "AirTravel application ended" << std::endl;
    return 0;
}

/*
 std::string starting_point("ORD");
 std::string ending_point("JFK");
 std::cout << "Retreiving airport data for " << starting_point << std::endl;
 AirTravel::Airport* start = ourmap.IATAsearch(starting_point);
 std::cout << "Retreiving airport data for " << ending_point << std::endl;
 AirTravel::Airport* end = ourmap.IATAsearch(ending_point);
 TODO - print out airport code, full name of airport and it's latitude and longitude and lastly the distance between the as the 787 flies.
 Optional - work in progress - find a route between the 2 locations with zero or 1 stop.
 */
