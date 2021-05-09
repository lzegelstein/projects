#include <_stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AirTravel.h"
#include "Airport.h"
/*
 Questions for mentor meeting:
 1. Is there a way to get around having to do AirTravel:: like in line for loop of findBusiestAirport()?
 Make airport struct external, it can still be in the same file.
 Don't template it
 
 
 Mazes:
 We get the distance easily from the BFS, #of steps. The end of the maze is defined as the square on the bottom that is the furthest.
 
 Do BFS of the whole thing as a traversal and at the end, you'll know the distance traveled. Do't do BFS to a point.
 BFS finds the endpoint by computing the distance.
 Along the way, save what square you came from
 */

/* NEXT STEPS:
1. Fixing the runtime of BusiestAirport(). Right now it is O(N) but we will continuously update it as the destination vector is filled in. That is a task for not today though
2. Complete the algorithms
3. Get a graphic output
 */

/*
 Mentor meeting:
 Issue with Distrikya's -> how do you know where a "superior" vertex is?
 It is difficult to know how to handle the priority code -> next group session we should discuss this
 If we knew where it was, we could check to see if it was too big or too small and then heapify accordingly
 One way to get around it is to used a pointer based structure
 Another solution is to put extra nodes in but that compromises runtime sounds complex, do the other one
 
 
 */
//"/Users/lylazegelstein/Desktop/airportnames.csv"
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
