#include <sstream>
//#include <iostream> - not in here anymore
#include <queue>
#include "dijkstras.h"
//#include "dijkstras.hpp"
#include "Airport.h"
//#include "airport.hpp"
#include <list>

//needs testing & fix memory leaks

Dijkstras::Dijkstras(std::map<std::string, Airport*> airportList, Airport* source) {

    //Section 1: building the graph seen in lecture
     //should create a class, and have this as a private member within the class, that way you have access to the results from Dijkstras
    
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
    
    return;
}

/*
 Need to make sure this is not a multi edge graph.
 Must take every unique path and sort it by distance using a priority queue.
 Need a visisted vector or something
 */

std::list<Airport*> Dijkstras::getShortestRoute(Airport* destination){
    std::list<Airport*> route;
    Path* current = pathMap[&destination->IATA];
    if (current == NULL){
        return route;
    }
    route.push_front(current->end);
    while (current->start != NULL){
        current = pathMap[&(current->start->IATA)];
        route.push_front(current->end);
    }
    return route;
}



