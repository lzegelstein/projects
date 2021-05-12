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

//Printing Routines
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

void dfs_print(AirportTraversal::Iterator it, DFS dfs) {
    while (it != dfs.end()) {
        std::cout<<(*it).name<<std::endl;
        ++ it;
    }
}

int main(int argc, char** argv) {
  std::cout << "AirTravel application started" << std::endl;
  std::cout<<std::endl;

  std::string airports = "data/airport.csv"; //Full Data
  //std::string airports = "data/aiports-short.csv"; //Short Version of Airport Data for testing
  std::string routes = "data/routes.csv"; //Full Data
  //std::string routes = "data/routes-short.csv"; //Short Version of Routes Data for testing

  AirTravel ourmap(airports,routes);

  //Dijkstra's algorithm
  std::cout<<"Dijkstra's"<<std::endl;
  std::string source_airport("JFK");
  std::string destination_airport("HPN");
  std::cout<<"The shortest path from "<<source_airport<< " to "<<destination_airport<<":"<<std::endl;
  Airport* source = ourmap.IATAsearch(source_airport);
  Airport* destination = ourmap.IATAsearch(destination_airport);
  std::list<Airport*> ourList = ourmap.Air_Dijkstras(source)->getShortestRoute(destination);
  ourmap.printList(ourList);
  std::cout<<std::endl;
  std::cout<<"-----------------------------"<<std::endl;
  std::cout<<std::endl;

  //DFS
  std::cout<<"DFS"<<std::endl;
  std::string dfs_source_airport("ATL");
  Airport* dfs_source = ourmap.IATAsearch(dfs_source_airport);
  DFS * dfs_ptr = NULL;
  if (dfs_source != NULL){ dfs_ptr = ourmap.DepthFirstSearch(dfs_source); }
  //if (dfs_ptr != NULL) { dfs_print(dfs_ptr->begin(), *dfs_ptr); } //Prints all of DFS (Only uncomment if working with short data).
  std::cout<<std::endl;
  std::cout<<"-----------------------------"<<std::endl;
  std::cout<<std::endl;
  
  //Graphic Output
  std::cout<<"Graphic Output"<<std::endl;
  Graph * gr = ourmap.worldMap(7500, 10000);
  if(gr != NULL) { 
    cs225::PNG * png_ptr = gr->makeImage();
    png_ptr->writeToFile("out-ourGraph.png");
    std::cout<< "Image writen to out-ourGraph.png"<<std::endl;
  }
  else {
    std::cout << "Graphical Output Failed."<<std::endl;
  }
  std::cout<<std::endl;
  std::cout<<"-----------------------------"<<std::endl;
  std::cout<<std::endl;

  //QUESTIONS WE CAN ANSWER AS STATED IN OUR PROPOSAL (based on the full dataset)
  Airport * busiestAirport = ourmap.findBusiestAirport();
  if (busiestAirport != NULL) {
    std::cout<<"Busiest Airport: "<<busiestAirport->name<<std::endl;
    std::cout<<std::endl;
  } 
  else {
    std::cout<<"Busiest Airpot: *AirTravel Empty*"<<std::endl;
    std::cout<<std::endl;
  }

  std::string isDirectStart("RUT");
  std::string isDirectEnd("JFK");
  bool answer = ourmap.isDirectFlight(isDirectStart, isDirectEnd);
  std::cout<<"Is there a direct flight from "<<isDirectStart<<" to "<<isDirectEnd<<" ? "<<yesOrNo(answer)<<std::endl;
  std::cout<<std::endl;

  std::string Home = "ORD";
  std::string Vacay = "LYR";
  std::cout<<"Round Trip from "<<Home<<" to "<<Vacay<<" consists of stops to: "<< std::endl;
  ourmap.roundTrip(Home, Vacay);
  std::cout<<std::endl;


  std::string IATA1 = "JFK";
  std::string IATA2 = "RUT";
  bool under3 = ourmap.underThreeFlights(IATA1, IATA2);
  std::cout<<"Can we get from " << IATA1 << " to " << IATA2 << " in under 3 flights? "<<yesOrNo(under3)<<std::endl;
  std::cout<<std::endl;
  
  std::cout << "AirTravel application ended" << std::endl;

  return 0;
}



