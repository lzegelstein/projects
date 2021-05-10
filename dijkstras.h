#pragma once
#include <algorithm>
#include <float.h>
//#include "airport.hpp"
//#include "air_travel.hpp" - not in here anymore
#include <map>
#include <list>
#include "Airport.h"

/**
 *
 */
struct Path { //iterate through these in the queues
    Airport * start;
    Airport * end;
    double weight;
    Path(Airport * s, Airport * e, double w = DBL_MAX) : start(s), end(e), weight(w) {}
};

/**
 *
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
     * @param source
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
     *
     */
    std::map<std::string *, AirportNode *> allAirports;

    /**
     *
     */
    std::map<std::string *, Path *> pathMap;
};
