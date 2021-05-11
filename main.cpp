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

/** More things to add to the main:
 * Can we get from point a to point b in under 3 stops?
 * if list < 5
*/ 

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
  
  //QUESTIONS WE CAN ANSWER AS STATED IN OUR PROPOSAL (based on the full dataset)
  Airport * busiestAirport = ourmap.findBusiestAirport();
  std::cout<<"Busiest Airport: "<<busiestAirport->name<<std::endl;

  std::string isDirectStart("LYR");
  std::string isDirectEnd("JFK");
  bool answer = ourmap.isDirectFlight(isDirectStart, isDirectEnd);
  std::cout<<"Is there a direct flight from "<<isDirectStart<<" to "<<isDirectEnd<<" ? "<<answer<<std::endl;
  
  //a to c and c to a
  ourmap.roundTrip("JFK", "LYR");


  std::cout << "AirTravel application ended" << std::endl;
  return 0;
}



