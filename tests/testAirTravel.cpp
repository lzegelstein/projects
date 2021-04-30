#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../AirportTraversal.h"
#include "../DFS.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

/*
AirTravel AirTravelStrings(std::string air_file_in, std::string routes_file_in){

}
*/

TEST_CASE("test", "[AirTravel]"){

    //airports
    std::ifstream air_file("data/airports-short.csv");
    std::string AirportFile = "";
    std::vector<std::string> vec_air;
    while (getline(air_file, AirportFile))
    {
        vec_air.push_back(AirportFile);
    }
    air_file.close();

    for(auto it: vec_air){
        std::cout<<it<<std::endl;
    }

    //routes
    std::ifstream routes_file("data/routes-short.csv");
    std::string RoutesFile = "";
    std::vector<std::string> vec_routes;
    while (getline(routes_file, RoutesFile))
    {
        vec_routes.push_back(RoutesFile);
    }
    routes_file.close();
    for(auto it: vec_routes){
        std::cout<<it<<std::endl;
    }

    //convert vectors into strings
    string air_str = "";
    //air_str = new string[vec_air.size()];
    for(unsigned i=0; i<vec_air.size(); i++){
        air_str.append(vec_air[i]);//Copy the vector to the string
    }

    std::cout<<air_str<<std::endl;


    string routes_str = "";
    //air_str = new string[vec_air.size()];
    for(unsigned i=0; i<vec_routes.size(); i++){
        routes_str.append(vec_routes[i]);//Copy the vector to the string
    }

    std::cout<<routes_str<<std::endl;

    //we have strings for airtravel and routes from the csv files

    AirTravel AT = AirTravel(air_str, routes_str); //has a bunch of open failed


    //REQUIRE(vec_air[0] == );
    //routes
    /*
    std::ifstream route_file("data/airports-short.csv");
    std::string RoutesFile;
    getline(route_file, RoutesFile);
    
    */
    //std::cout<<RoutesFile<<std::endl;

}
