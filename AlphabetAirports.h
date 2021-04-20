#include <vector>
#include <stdio.h>
#include <string>
#include "AirTravel.h"

/**
 * Helper class to reduce runtime of creating edges
 * This class creates a quick way to find the source/destination airports to then populare the edges of our graph.
 * We will have a vector of pointers. The vector will "contain" pointers to letters A through Z. Each pointer points to a BST.
 * We created a Node struct and plan to use recursion to aid in finding specific airports.
 * Clarification: Data does not get read in by this class, it simply gets organized. 
 */
class AlphabetAirports::AirTravel{
    public:

    /**
     * Constructor
     */
    AlphabetAirports();

    ~AlphabetAirports();

    /**
     * Adds airport to the respective tree
     * 
     * @param Airport point to the airport we're adding the node for
     */
    void addAirport(Airport* Airport);

    /**
     * getter function for finding a specific airport
     * 
     * @param Airport IATA code for the airport we're looking for
     * 
     * @returns pointer to the airport
     */
    Airport* findAirport(char* Airport); 

    private:

    struct Node{
        char[2] code;
        Airport* port; //COME BACK TO (MAY NOT BE VALID TYPE)
        Node* right;
        Node* left;
    };

    std::vector<Node*> Alphabet;

};