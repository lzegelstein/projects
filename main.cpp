#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AirTravel.h"
#include "Airport.h"

int main() {
    std::cout << "AirTravel application started" << std::endl;
    AirTravel ourmap("data/airports-short.csv", "data/routes-short.csv");
    
    Airport* busiest = ourmap.findBusiestAirport();
    std::cout<<"busiest airport is "<< busiest->name <<std::endl;
    
    std::string ohare = "ORD";
    std::string atlanta = "CDG";
    bool x = ourmap.isDirectFlight(ohare, atlanta);
    std::cout<<"Direct flight from ORD to ATL? "<< x << " routes"<<std::endl;
    
    std::cout << "AirTravel application ended" << std::endl;
    return 0;
}

//Previos Main 
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
