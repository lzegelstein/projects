#pragma once
#include <algorithm>
#include <float.h>
#include "Airport.h"
#include "AirTravel.h"
//#include "airport.hpp"
//#include "air_travel.hpp"

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

class Dijkstras {
    
public:
    void dijkstras(std::map<std::string, Airport*> airportList, Airport* source);

    
    
private:
    
};
