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

    //Member Variables for disconnected graph

    /**
     * Nodes for our graph
     */
    struct Airport {
        std::string name;   //name of airport
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

    //Memeber Variables for alaphabetized graph

    /**
     * Node Structure for our BST's
     */
    struct Node{
        std::string code;
        Airport* port; //COME BACK TO (MAY NOT BE VALID TYPE)
        Node* right;
        Node* left;
    };

    /**
     * Vector of root nodes in alphabetical order
     */
    std::vector<Node*> Alphabet;

    //Member Functions for disconnected graph
    /**
     * 
     */
    void readInAirportData();

    //Member Functions for alphabetized graph
    /**
     * 
     */
    void addAirport(Airport* Airport);

    /**
     * 
     */
    Airport* findAirport(std::string Airport);

    

};