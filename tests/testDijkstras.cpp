#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../Airport.h"

TEST_CASE("Check empty smallestDestination", "[Dijkstras]"){
    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    Dijkstras* D = AT.Air_Dijkstras(AT.IATAsearch("CDG"));
    std::list<Airport*> list = D->getShortestRoute(AT.IATAsearch("ATL"));

    REQUIRE(list.back() == NULL);
}

TEST_CASE("Check CDG to LAX smallestDestination", "[Dijkstras]"){
    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    Dijkstras* D = AT.Air_Dijkstras(AT.IATAsearch("CDG"));
    std::list<Airport*> list = D->getShortestRoute(AT.IATAsearch("LAX"));

    std::string curr = list.back()->IATA;
    list.pop_back();
    REQUIRE( curr == "LAX");
    curr = list.back()->IATA;
    list.pop_back();
    REQUIRE( curr == "JFK");
    curr = list.back()->IATA;
    list.pop_back();
    REQUIRE( curr == "CDG");
}