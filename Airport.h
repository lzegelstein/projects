#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "cs225/PNG.h"
#include "Node.h"

struct Airport {
public:
    std::string name;    //name of airport
    std::string city;    //city of airport
    std::string country; //country of airport
    std::string IATA;    //IATA code of airport
    double latitude;     //latitude of airport
    double longitude;    //longitude of airport

    /**
     * Default constructor,
     * All strings are empty
     * Latitude and Longitude to (0,0)
     * The vector is also empty 
     */
    Airport();
    
    /**
     * Constructor
     * 
     * All Parameters match the explaination given in the member variables
     * @param name 
     * @param city 
     * @param country
     * @param IATA
     * @param latitude
     * @param longitude
     */
    Airport(std::string name, std::string city, std::string country,
    std::string IATA, double latitude, double longitude);

    /**
     * overload operator <
     * 
     * //What does this do?//
     * 
     * @param other The other point
     * @return True for smaller in map, false for otherwise
     */
    bool operator<(const Airport& other) const; 

    /**
     * overload operator ==
     * 
     * //What does this do?//
     * 
     * @param other The other point
     * @return True for smaller, false for otherwise
     */
    bool operator==(const Airport& other) const; 


    /**
    * Weighted edges for our graph
    *
    * Takes into account one way flights!!
    */
    struct Flights {
        //Airport* other_airport = new Airport(); //connected node
        Airport * other_airport;
        //Need to find the airport in the map and when populating the edges, find the other airport
        double distance; //weight
    };

    std::vector<Flights> destinations; //outgoing flights from airport
    
    /**
     * Function for calculating distance between airports and adding a new Flight struct to the destinations vector
     *
     * @param other A pointer to the destination airport to be added
     */
    void addDestination(Airport* other);
};