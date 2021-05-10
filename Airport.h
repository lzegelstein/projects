#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>



struct Airport {
public:
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
     * Compares the strings containing IATA codes
     *
     * @param other The other point
     * @return True for smaller in map, false for otherwise
     */
    bool operator<(const Airport& other) const;

    /**
     * overload operator ==
     *
     * Compares the strings containing IATA codes
     *
     * @param other The other point
     * @return True for smaller, false for otherwise
     */
    bool operator==(const Airport& other) const;

    /**
     * Function for calculating distance between airports and adding a
     * new Flight struct to the destinations vector
     *
     * Makes sure not to include repeats since airlines are ignored in
     * this graph
     *
     * @param other A pointer to the destination airport to be added
     */
    void addDestination(Airport* other);

    /**
    * Struct for the outgoing flights from this airport
    *
    * Contains pointer to other airport and a double of
    * distsnce to that airport
    */
    struct Flights {
        Airport* other_airport;
        double distance;
    };

    /**
     * Member variables
     */
    std::string name;    //name of airport
    std::string city;    //city of airport
    std::string country; //country of airport
    std::string IATA;    //IATA code of airport
    double latitude;     //latitude of airport
    double longitude;    //longitude of airport
    std::vector<Flights> destinations; //outgoing flights from airport
};
