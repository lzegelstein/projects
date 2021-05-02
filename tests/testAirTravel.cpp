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
//     Airport jfk = *(AT.IATAsearch("JFK"));
//     REQUIRE(jfk.city == "New York");
//     REQUIRE(jfk.country == "United States");
//     REQUIRE(jfk.IATA == "JFK");
//     REQUIRE(jfk.latitude == 40.63980103);
//     REQUIRE(jfk.longitude == -73.77890015);
//     REQUIRE(jfk.name == "John F Kennedy International Airport");
// }


TEST_CASE("Airport List Populated Correctly", "[AirTravel]"){

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    vector<std::string> ans = {"ATL", "CDG", "JFK", "LAX", "LPL", "MAD", "ORD", "PEK"};
    for(auto it: ans){
        REQUIRE(AT.IATAsearch(it) != NULL);
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

    Airport JFK = *(AT.IATAsearch("JFK"));
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

    Airport ATL = *(AT.IATAsearch("ATL"));
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

    Airport ORD = *(AT.IATAsearch("ORD"));
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

    Airport CDG = *(AT.IATAsearch("CDG"));
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

    Airport MAD = *(AT.IATAsearch("MAD"));
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

    Airport PEK = *(AT.IATAsearch("PEK"));
    REQUIRE(PEK.destinations.size() == 5);

    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "ORD"};
    int i = 0;
    for(auto it: PEK.destinations){
        REQUIRE(it.other_airport->IATA == ans[i]);
        i++;
    }
}