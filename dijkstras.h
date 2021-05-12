#pragma once
#include <algorithm>
#include <float.h>
#include <map>
#include <list>
#include "Airport.h"

/**
 * Represents flights between different airports
 * start is the starting airport, end is the ending airport
 * weight is distance between these airports
 */
struct Path { //iterate through these in the queues
    Airport * start;
    Airport * end;
    double weight;
    Path(Airport * s, Airport * e, double w = DBL_MAX) : start(s), end(e), weight(w) {}
};

/**
 * Each airport from the dataset will be represented by an AirportNode.
 * We have a boolean to see if we already visited it or not. The visited boolean lets us know whether we will need to push 
 * the destinations of the airport * to the priority queue in the dijkstra's algorithm
 */
struct AirportNode {
    bool visited;
    double weight;
    Airport * airport;
    AirportNode(Airport * a) : visited(false), weight(DBL_MAX), airport(a) {}
};

class Dijkstras {
public:

    /**
     * Dijkstra's constructor
     * 
     * @param aiportList Map containing all the airports in the dataset with the key being the
     * @param source All distances will be calculated relative to the source airport which is passed in 
     */
    Dijkstras(std::map<std::string, Airport*> airportList, Airport* source);

    /**
     * Function that returns useful information from Dijkstra's algorithm
     * Takes in the ending point and returns the shortest path to the
     * source airport from the constructor
     *
     * @param destination aiport to find the route to
     *
     * @returns a list of airports needed to visit.
     *   Starting with source, ending with destination
     *   List is empty if there is no route
     */
    std::list<Airport*> getShortestRoute(Airport* destination);

private:
    /**
     * Holds all of the "vertices" aka AirportNodes
     */
    std::map<std::string *, AirportNode *> allAirports;

    /**
     * Holds all "edges" aka Paths
     */
    std::map<std::string *, Path *> pathMap;
};
