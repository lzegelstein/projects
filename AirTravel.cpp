#include <stdio.h>
#include <vector>
#include <string>
#include "AirTravel.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <math.h>

using std::string;

/*
 Perhaps, we need to create different print routines i.e. print all the destinations of _______ airport
 Be able to pass it in a 3 letter code
 */

/**
 * This file includes all the usable functions from AirTravel.h
 */

/**
 * Default Constructor
 */
AirTravel::AirTravel(){}

AirTravel::Airport* AirTravel::IATAsearch(std::string code) {
    return AirportList[code];
}

AirTravel::Airport* AirTravel::findBusiestAirport() {
    Airport* current_busiest = AirportList.begin()->second;
    std::map<std::string, Airport*>::iterator it;
    for (it = AirportList.begin(); it != AirportList.end(); it++) {
        if (it->second->destinations.size() >= current_busiest->destinations.size()){
            current_busiest = it->second;
        }
    }
    return current_busiest;
}

bool AirTravel::isDirectFlight(std::string start, std::string end) {
    Airport* source = AirportList[start];
    Airport* dest = AirportList[end];
    for (unsigned int i = 0; i< source->destinations.size(); i++){
        if(source->destinations[i].other_airport->IATA == dest->IATA){
            return true;
        }
    }
    return false;
}

cs225::PNG AirTravel::createGraph(std::map<std::string, Airport*> list){
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    int distx_max = 0;
    int distx_min = 0;
    int disty_max = 0;
    int disty_min = 0;

    //find current max/min size of image
    for(auto it: list){
        Airport air_curr = *(it.second);
        if(air_curr.latitude > distx_max){
            distx_max = air_curr.latitude;
        }
        if(air_curr.latitude < distx_min){
            distx_min = air_curr.latitude;
        }
        if(air_curr.longitude > disty_max){
            disty_max = air_curr.longitude;
        }
        if(air_curr.longitude < disty_min){
            disty_min = air_curr.longitude;
        }
    }

    //create image PNG
    cs225::PNG image((distx_max - distx_min), (disty_max - disty_min));

    //populate nodes and edges
    for(auto it: list){
        Airport air_curr = *(it.second);
        int x = air_curr.latitude - distx_min;
        int y = air_curr.longitude - disty_min;
        Node node_curr(x, y, air_curr.destinations.size());
        nodes.push_back(node_curr);

        for(auto j : air_curr.destinations){
            int x = j.other_airport->latitude - distx_min;
            int y = j.other_airport->longitude - disty_min;
            Node other(x, y, j.other_airport->destinations.size());
            Edge edge_curr(node_curr, other, j.distance);
            edges.push_back(edge_curr);
        }  
    }

    for(auto it: nodes){
        drawNode(it, image);
    }

    for(auto it: edges){
        drawEdge(it, image);
    }

    return image;
}

