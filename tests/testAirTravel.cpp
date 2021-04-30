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

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv"); //has a bunch of open failed

    REQUIRE(!AT.AirportList.empty());

    for(auto it: AT.AirportList){
        std::cout<<it.first<<std::endl;
    }
    
    DFS dfs = DFS(AT.AirportList, *(AT.AirportList.at("ATL")));
    
    //bool temp = dfs.empty();
    //dfs.begin();
}
