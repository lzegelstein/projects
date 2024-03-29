#include <sstream>
#include <queue>
#include "dijkstras.h"
#include "Airport.h"
#include <list>


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
            pathMap.erase(& current->end->IATA); 
            pathMap.insert(std::make_pair(& current->end->IATA, current));
        }
        
        if (! endNode->visited) { //if the path hasn't been visited, you need to push destinations to pq
            
            for (Airport::Flights f : endNode->airport->destinations) {
                pq.push(new Path(endNode->airport,  f.other_airport, endNode->weight + f.distance));
            }
            
            endNode->visited = true;
        }
        
    }
    
    return;
}



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

void printShortestRoute(std::list<Airport*> print_list) {

    std::cout<<"Shortest Route: "<<std::endl;
    while(!print_list.empty()) {
        std::cout<<print_list.front()->name<<std::endl;
        print_list.pop_front();
    }
    std::cout<<"----------"<<std::endl;
    return;
}



