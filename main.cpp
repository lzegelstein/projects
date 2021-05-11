#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AirTravel.h"
#include "Airport.h"
#include "graph.h"
#include "cs225/PNG.h"
int main() {
    std::cout << "AirTravel application started" << std::endl;
    //AirTravel ourmap("data/airports-short.csv", "data/routes-short.csv");
    AirTravel ourmap("data/airport.csv", "data/routes.csv");
    Graph * gr = ourmap.worldMap(2000, 4000);
    cs225::PNG * png_ptr = gr->makeImage();

    png_ptr->writeToFile("out-ourGraph.png");

    Airport* lyr = ourmap.IATAsearch("LYR");

    std::cout << lyr->name << std::endl;

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
