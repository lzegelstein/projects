#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include <math.h>
#include "Airport.h"

using std::string;

Airport::Airport() : name(""), city(""), country(""), IATA(""), latitude(0), longitude(0) {
    //Nothing
}

Airport::Airport(std::string name, std::string city, std::string country, std::string IATA, double latitude, double longitude)
                : name(name), city(city), country(country), IATA(IATA), latitude(latitude), longitude(longitude) {
    //Nothing
}

bool Airport::operator<(const Airport& other) const {
    return (IATA < other.IATA);
}

bool Airport::operator==(const Airport& other) const {
    return (IATA == other.IATA);
}

void Airport::addDestination(Airport* that) {
    double lat_diff = this->latitude - that->latitude;
    double lon_diff = this->longitude - that->longitude;

    lat_diff *= lat_diff;
    lon_diff *= lon_diff;
    
    Flights route;
    route.other_airport = that;
    route.distance = sqrt(lat_diff + lon_diff);
    
    int i = 0;
    bool same = false;

    while (i < (int) destinations.size()) {
        if (destinations[i].other_airport == route.other_airport) {
            same = true;
            break;
        }
        i++;
    }
    
    if (!same) {
        this->destinations.push_back(route);
    }
}
