#pragma once
#include <algorithm>
#include <float.h>
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
