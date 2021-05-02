#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../traversal/AirportTraversal.h"
#include "../traversal/DFS.h"
#include "../Airport.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

// TEST_CASE("AirportParseLine Works Correctly", "[AirTravel]"){
//     std::string JFK = "3797,\"John F Kennedy International Airport\",\"New York\",\"United States\",\"JFK\",\"KJFK\",40.63980103,-73.77890015,13,-5,\"A\",\"America/New_York\",\"airport\",\"OurAirports\"";
//     AirTravel AT = AirTravel();
//     AT.AirportParseLine(JFK);
//     AirTravel::Airport jfk = *(AT.AirportList.at("JFK"));
//     REQUIRE(jfk.city == "New York");
//     REQUIRE(jfk.country == "United States");
//     REQUIRE(jfk.IATA == "JFK");
//     REQUIRE(jfk.latitude == 40.63980103);
//     REQUIRE(jfk.longitude == -73.77890015);
//     REQUIRE(jfk.name == "John F Kennedy International Airport");
// }


TEST_CASE("Airport List Populated Correctly", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    REQUIRE(!AT.AirportList.empty());

    vector<std::string> ans = {"ATL", "CDG", "JFK", "LAX", "LPL", "MAD", "ORD", "PEK"};
    int i = 0;
    for(auto it: AT.AirportList){
        REQUIRE(it.first == ans[i]);
        i++;
    }
}

TEST_CASE("LAX Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    Airport LAX = *(AT.IATAsearch("LAX"));
    REQUIRE(LAX.destinations.size() == 3);

    vector<std::string> ans = {"JFK", "MAD", "ORD"};
    int i = 0;
    for(auto it: LAX.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}

TEST_CASE("JFK Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport JFK = *(AT.AirportList.at("JFK"));
    REQUIRE(JFK.destinations.size() == 4);

    vector<std::string> ans = {"CDG", "LAX", "MAD", "ORD"};
    int i = 0;
    for(auto it: JFK.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}

TEST_CASE("ATL Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport ATL = *(AT.AirportList.at("ATL"));
    REQUIRE(ATL.destinations.size() == 5);

    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "ORD"};
    int i = 0;
    for(auto it: ATL.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}


TEST_CASE("ORD Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport ORD = *(AT.AirportList.at("ORD"));
    REQUIRE(ORD.destinations.size() == 5);

    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "PEK"};
    int i = 0;
    for(auto it: ORD.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}

TEST_CASE("CDG Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport CDG = *(AT.AirportList.at("CDG"));
    REQUIRE(CDG.destinations.size() == 2);

    vector<std::string> ans = {"JFK", "ORD"};
    int i = 0;
    for(auto it: CDG.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}

TEST_CASE("MAD Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport MAD = *(AT.AirportList.at("MAD"));
    REQUIRE(MAD.destinations.size() == 4);

    vector<std::string> ans = {"JFK", "LAX", "ORD", "PEK"};
    int i = 0;
    for(auto it: MAD.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}

TEST_CASE("PEK Destinations", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport PEK = *(AT.AirportList.at("PEK"));
    REQUIRE(PEK.destinations.size() == 5);

    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "ORD"};
    int i = 0;
    for(auto it: PEK.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}