#pragma once
#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include "cs225/PNG.h"
#include "Node.h"

class AirTravel {

/**
 * Functions included in AirTravel_parse.cpp
 */
public:
    /**
     * Aiport struct are the nodes of the graphs
     * This holds all of the relevent information for an airport
     *
     * TODO:
     * Fix Flights stuct to be more straighforward
     * Lyla's Comments:
     * //Modified 4/23 @ 7 am. We shouldn't be creating a new airport object
     */
    struct Airport {
            std::string name;   //name of airport
            std::string city;   //city of airport
            std::string country;//country of airport
            std::string IATA;   //IATA code of airport
            double latitude;    //latitude of airport
            double longitude;   //longitude of airport

            /**
             * Default constructor, set the Airport to (0, 0)
             */
            Airport() : name(""), city(""), country(""), IATA(""), latitude(0), longitude(0) { }
            /**
             * Constructor
             * @param name 
             * @param city 
             * @param country
             * @param IATA
             * @param latitude
             * @param longitude
             */
            Airport(std::string name, std::string city, std::string country,
            std::string IATA, double latitude, double longitude) : name(name), city(city), country(country),
            IATA(IATA), latitude(latitude), longitude(longitude) { }

            /**
             * overload operator <
             * @param other The other point
             * @return True for smaller in map, false for otherwise
             */
            bool operator<(const Airport &other) const {
                return (IATA < other.IATA);
            }

            /**
             * overload operator ==
             * @param other The other point
             * @return True for smaller, false for otherwise
             */
            bool operator==(const Airport &other) const {
                return (IATA == other.IATA);
            }


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

    /**
     * Constructor
     *
     * @param Airport_File name of csv file containing airport data
     * @param Routes_File name of csv file containing routes data
     */
    AirTravel (std::string Airport_File, std::string Routes_File);

    /** Map
     * Key is airport code
     * the value is pointer to airport struct
     */
    std::map<std::string, Airport*> AirportList;

    /** MOVED TO PUBLIC FOR TESTCASES
     * Takes a line of the airport data
     * Goes through character by character looking for a comma
     * As we parse, build the data structure -> be populating the map
     * field_num #1: airport name
     * field_num #2: city
     * field_num #3: country
     * field_num #4: 3 letter code
     * field_num #6: latitude
     * field_num #7: longitude
     * All other fields will be ignored
     *
     * @param input Line to be parsed
     */
    void AirportParseLine(std::string input);

/**
 * Functions included in AirTravel_parse.cpp
 */
private:

    //Member Functions for disconnected graph
    /**
     * Reads data from airport file
     *
     * @param fileName name of file to be analyzed
     */
    void readInAirportData(std::string fileName);

    /**
     * Removes the quotation marks from the string
     * (first and last indexes of the array)
     *
     * @param temp string to modify
     */
    std::string removeQuotes(std::string temp);

    /**
     * Makes sure that inputed data of airports is valid.
     *
     * @param field_num corresponding feild number since each field has different requirements
     * @param value string to be checked
     *
     * @returns true if string is valid
     */
    bool AirportLineCheck(int field_num, std::string value);

    /**
     * Adds values to our map with the key of IATA values;
     *
     * @param Airport new pointer to be added to the map of airports
     */
    void addAirport(Airport* Airport);

    /**
     * Reads data from routes file
     *
     * @param fileName name of file to analyzed
     */
    void readInRoutesData(std::string fileName);

    /**
     * Takes a line of the routes data
     * Goes through character by character looking for a comma
     * As we parse, build the data structure by adding edges
     * field_num #2: source airport
     * field_num #4: destination airport
     * All other fields will be ignored
     *
     * @param input the string of the current line from the routes file
     */
    void RoutesParseLine(std::string input);


/**
 * Functions included in AirTravel.cpp
 */
public:

    /**
     * Default Constructor
     */
    AirTravel();

    /**
     * getter for airport
     *
     * @param code Three letter IATA code for the airport in question
     *
     * @returns pointer to the airport with corresponding code
     * NULL if airport not found;
     */
    Airport* IATAsearch(std::string code);

    /**
     * The busiest airport is the airport which the most number of outgoing flights.
     * We will find the busiest airport by comparing the size of the destination vector.
     *
     * @returns a pointer to the busiest airport
     */
    Airport* findBusiestAirport();

    /**
     * Determines whether or not there is a direct flight between two airports
     *
     * @param start source Airport's IATA code
     * @param end destination Airport's IATA code
     *
     * @returns true if there is a direct flight.
     */
    bool isDirectFlight(std::string start, std::string end);


    /**
     * Creates a graph PNG output ready to be writtentoFile
     * Use the functions drawNode and drawEdge 
     * 
     * @param list to obtain nodes and edges from map
     * 
     * @returns png output
     */
    cs225::PNG createGraph(std::map<std::string, Airport*> list);

};