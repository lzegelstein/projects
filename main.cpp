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

void dfs_print(DFS * stuff);

void dfs_print(DFS * stuff) {
    while (!stuff->empty()) {
        std::cout<<stuff->pop().name<<std::endl;
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
    AirTravel dfsAlg("data/airport.csv", "data/routes.csv");
    std::string dfs_source_airport("MHC");
    //std::string dfs_destination_airport("ULK");
    Airport* dfs_source = dfsAlg.IATAsearch(dfs_source_airport);
    DFS * dfs_ptr = dfsAlg.DepthFirstSearch(dfs_source);
    dfs_print(dfs_ptr);
    

//Airport* destination = dfsAlg.IATAsearch(dfs_destination_airport);

  //DFS* DepthFirstSearch(Airport* source);

  //Graphic Output
  /*
    AirTravel ourmap("data/airport.csv", "data/routes.csv");
    Graph * gr = ourmap.worldMap(4000, 2000);
    cs225::PNG * png_ptr = gr->makeImage();
    png_ptr->writeToFile("out-ourGraph.png");
  */


    std::cout << "AirTravel application ended" << std::endl;
    return 0;
}


/*
    Graph * gr = ourmap.worldMap(4000, 2000);
    cs225::PNG * png_ptr = gr->makeImage();

    png_ptr->writeToFile("out-ourGraph.png");

    Airport* lyr = ourmap.IATAsearch("LYR");

    std::cout << lyr->name << std::endl;

*/
