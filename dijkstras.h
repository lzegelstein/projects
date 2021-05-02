#pragma once
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include "Airport.h"
#include "AirTravel.h"

//does this need to be a class?
// Maybe not... Does it need to return double
class Dijkstras {
    public:
 
    /**
     * TODO: - finish writing this and move it out of the class probs into another class
     */

    //Return: double
    Dijkstras(std::map<std::string, Airport* > AirportList, Airport* source);
};


//OLD COMMENTS
//ASK LYLA TO DELETE

/*   public:
    Dijkstras(const std::map<std::string, Airport*>&);
    //Need a function to return the path from A to B
    //Need const methods :0
    
        /Constructor that creates a graph from the data from airplane/routes
        Dijkstras(std::vector<std::vector<std::string>> data);
    
        //Constructor creates vector of edges (shortest path)
        std::vector<Edge> edges(Vertex a, Vertex b);
    
        //Main Dijkstras function, has all the helper functions
        std::vector<Edge> mainDijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b);

    private:
     const std::map<std::string, Airport*> & AirportList;
     */
