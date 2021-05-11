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


std::string yesOrNo (bool value) {
    std::string string;
    if (value == 0) {
        string = "No";
    }
    else {
        string = "Yes";
    }
    return string;
}


void dfs_print(AirportTraversal::Iterator it, DFS dfs);

void dfs_print(AirportTraversal::Iterator it, DFS dfs) {
    while (it != dfs.end()) {
        std::cout<<(*it).name<<std::endl;
        ++ it;
    }
}

int main(int argc, char** argv) {
    std::cout << "AirTravel application started" << std::endl;
  
    //CHOOSE YOUR DATASET
    AirTravel ourmap("data/dijkstraAirports.csv", "data/dijkstrastestroutes.csv");
    //AirTravel ourmap("/Users/lylazegelstein/Desktop/airports-short.csv", "/Users/lylazegelstein/Desktop/routes-short.csv");
    //AirTravel ourmap("data/airport.csv", "data/routes.csv");

  //Dijkstra's algorithm
   std::cout<<"Dijkstra's"<<std::endl;
   std::string source_airport("JFK");
   std::string destination_airport("HPN");
   Airport* source = ourmap.IATAsearch(source_airport);
   Airport* destination = ourmap.IATAsearch(destination_airport);
   std::list<Airport*> ourList = ourmap.Air_Dijkstras(source)->getShortestRoute(destination);
   ourmap.printList(ourList);
   std::cout<<"-----------------------------"<<std::endl;
   std::cout<<std::endl;

  //DFS
  /*
    std::string dfs_source_airport("ATL");
    Airport* dfs_source = ourmap.IATAsearch(dfs_source_airport);
    DFS * dfs_ptr = ourmap.DepthFirstSearch(dfs_source);
    dfs_print(dfs_ptr->begin(), *dfs_ptr);
    std::cout<<"-----------------------------"<<std::endl;
    std::cout<<std::endl;
    */
  //Graphic Output
  /*
    Graph * gr = ourmap.worldMap(10000, 10000);
    cs225::PNG * png_ptr = gr->makeImage();
    png_ptr->writeToFile("out-ourGraph.png");
  */


  //QUESTIONS WE CAN ANSWER AS STATED IN OUR PROPOSAL (based on the full dataset)
  Airport * busiestAirport = ourmap.findBusiestAirport(); 
  std::cout<<"Busiest Airport: "<<busiestAirport->name<<std::endl;
  std::cout<<std::endl;

  std::string isDirectStart("RUT");
  std::string isDirectEnd("JFK");
  bool answer = ourmap.isDirectFlight(isDirectStart, isDirectEnd);
  std::cout<<"Is there a direct flight from "<<isDirectStart<<" to "<<isDirectEnd<<" ? "<<yesOrNo(answer)<<std::endl;
  std::cout<<std::endl;

  ourmap.roundTrip("JFK", "HPN");
  std::cout<<std::endl;

  bool under3 = ourmap.underThreeStops("JFK", "RUT");
  std::cout<<"Can we get from JFK to RUT in under 3 stops? "<<yesOrNo(under3)<<std::endl;
  std::cout<<std::endl;

  std::cout << "AirTravel application ended" << std::endl;

  return 0;
}



