#pragma once
#include <_stdio.h>
#include <vector>
#include <string>
#include <map>

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

    //Member Variables for disconnected graph

    /**
     * Nodes for our graph
     */
    struct Airport {
        std::string name;   //name of airport
        std::string city;   //city of airport
        std::string country;//country of airport 
        std::string IATA;   //IATA code of airport
        double latitude;    //latitude of airport
        double longitude;   //longitude of 
        
        /**
        * Weighted edges for our graph
        * 
        * Takes into account one way flights!!
        */
        struct Flights {
            Airport* other_airport; //connected node
            double distance; //weight
        };

        std::vector<Flights> destinations; //outgoing flights from airport
    };

    std::map<std::string, Airport*> AirportList;

    //Member Functions for disconnected graph
    /**
     * Reads data from airport file
     * 
     * @param fileName name of file to be analyzed
     */
    void readInAirportData(std::string fileName);

    /**
     * Takes a line of code
     * Goes through character by character looking for a comma
     * As we parse, build the data structure -> be populating the map
     * field_num #1: airport name
     * field_num #2: city
     * field_num #3: country
     * field_num #4: 3 letter code
     * field_num #6: latitude
     * field_num #7: longitude
     * 
     * @param input Line to be parsed
     */
    void AirportParseLine(std::string input);

    /**
     * 
     */
    bool AirportLineCheck(int field_num, std::string value);

    /**
     * Adds values to our map with the key of IATA values;
     */
    void addAirport(Airport* Airport);

    /**
     * 
     */
    Airport* findAirport(std::string Airport);

    

};