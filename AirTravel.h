#pragma once
#include <_stdio.h>
#include <vector>
#include <string>

class AirTravel {
    public:

    /**
     * Constructor
     */
    AirTravel();

    /**
     * Constructor with parameters
     * 
     * @param Airport_File name of csv file containing airport data 
     * @param Routes_File name of csv file containing routes data
     */
    AirTravel(std::string Airport_File, std::string Routes_File);

    /**
     * Copy Contructor
     */
    AirTravel(AirTravel& other);

    /**
     * Destructor
     */
    ~AirTravel();

    /**
     * Copy Assignment Constructor
     */
    AirTravel& operator=(const AirTravel& other);

    private:

    /**
     * Weighted edges for our graph
     * 
     * Takes into account one way flights!!
     */
    struct Flights {
        char other_airport; //connected node
        double distance; //weight
    };

    /**
     * Nodes for our graph
     */
    struct Airport {
        std::string name; //name of airport
        std::vector<Flights> destinations; //outgoing flights from airport
        double latitude; //latitude of airport
        double longitude; //longitude of airport
    };

};