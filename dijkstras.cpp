/*#include <sstream>
#include <string>
#include <iostream>
#include "dijkstras.h"
#include <map>
#include "Airport.h"
#include <sstream>
*/
//#include <iostream>
#include <queue>
#include "dijkstras.h"
//#include "dijkstras.hpp"
#include "Airport.h"
#include<limits.h>
#include<float.h>
//#include "airport.hpp"

/*
struct Path { //iterate through these in the queues
    Airport * start;
    Airport * end;
    double weight;
    Path(Airport * s, Airport * e, double w = DBL_MAX) : start(s), end(e), weight(w) {}
};

struct AirportNode {
    bool visited;
    double weight;
    Airport * airport;
    AirportNode(Airport * a) : visited(false), weight(DBL_MAX), airport(a) {}
};
*/

int Dijkstras(std::map<std::string, Airport*> airportList, Airport* source) {


/*
               The 3 maps and there purposes:
 1.
 2.
 3.
 */

 /*
    //Section 1: building the graph seen in lecture
    std::map<std::string *, AirportNode *> allAirports;
    std::map<std::string *, Path *> pathMap; //should create a class, and have this as a private member within the class, that way you have access to the results from Dijkstras
    
    auto my_comp = [](const Path* p1, const Path* p2) { return p1->weight > p2->weight; };
    std::priority_queue<Path *, std::vector<Path*>, decltype(my_comp)> pq(my_comp);
    
    for (auto it = airportList.begin(); it != airportList.end(); it ++) {
        AirportNode * airport = new AirportNode(it->second);
        allAirports.insert(std::make_pair(& airport->airport->IATA, airport));
    }
    
    pq.push(new Path(NULL, source, 0)); //push the source to the priority queue
    
    while (! pq.empty()) {
        Path * current = pq.top();
        
        pq.pop();
        
        AirportNode* endNode = allAirports.at(& current->end->IATA);
        //Do we have a better path to this ending node?

        if (current->weight < endNode->weight) {
            endNode->weight = current->weight;
            pathMap.erase(& current->end->IATA); //TODO: -> see if this creates a memory leak
            pathMap.insert(std::make_pair(& current->end->IATA, current));
        }
        
        if (! endNode->visited) { //if the path hasn't been visited, you need to push destinations to pq
            
            for (Airport::Flights f : endNode->airport->destinations) {
                pq.push(new Path(endNode->airport,  f.other_airport, endNode->weight + f.distance));
            }
            
            endNode->visited = true;
        }
        //TODO: possible memory leak here, because the Path() we new() needs to get deleted
        
    }
    */
    return 0;
}




/*
 Need to make sure this is not a multi edge graph.
 Must take every unique path and sort it by distance using a priority queue.
 Need a visisted vector or something
 */






