#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "AirTravel.h"
#include "Airport.h"
#include "graph.h"
#include "cs225/PNG.h"



/**
 * TODO: Questions that still need answering
 * 1. Use DFS somehow
 * 2. Call Dijkstras
*/

/**
 * Hi, welcome to the main of our Air Travel Program!
 * All of our algorithms on shorter datasets are commented out at the moment.
 * Whichever one you want to see, just uncomment out or you can work with the full dataset. 
*/
   
//AirTravel ourmap("data/airports-short.csv", "data/routes-short.csv");

void dfs_print(AirportTraversal::Iterator it, DFS dfs);

void dfs_print(AirportTraversal::Iterator it, DFS dfs) {
    while (it != dfs.end()) {
        std::cout<<(*it).name<<std::endl;
        ++ it;
    }
}
int main(int argc, char** argv) {
   std::cout << "AirTravel application started" << std::endl;
  

  //Dijkstra's algorithm
  /*
   AirTravel dijkstraAlg("data/dijkstraAirports.csv", "data/dijkstrastestroutes.csv");
   std::string source_airport("JFK");
   std::string destination_airport("RUT");
   Airport* source = dijkstraAlg.IATAsearch(source_airport);
   Airport* destination = dijkstraAlg.IATAsearch(destination_airport);
   dijkstraAlg.Air_Dijkstras(source)->getShortestRoute(destination);
   */

  //DFS
  /*
    AirTravel dfsAlg("/Users/lylazegelstein/Desktop/airports-short.csv", "/Users/lylazegelstein/Desktop/routes-short.csv");
    std::string dfs_source_airport("ATL");
    //std::string dfs_destination_airport("ULK");
    Airport* dfs_source = dfsAlg.IATAsearch(dfs_source_airport);
    DFS * dfs_ptr = dfsAlg.DepthFirstSearch(dfs_source);
    dfs_print(dfs_ptr->begin(), *dfs_ptr);
  */
    
  //Graphic Output
  
    AirTravel ourmap("data/airport.csv", "data/routes.csv");
    Graph * gr = ourmap.worldMap(4000, 2000);
    cs225::PNG * png_ptr = gr->makeImage();
    png_ptr->writeToFile("out-ourGraph.png");
  


    std::cout << "AirTravel application ended" << std::endl;
    return 0;
}



