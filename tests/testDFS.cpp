
#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../Airport.h"
#include "../traversal/AirportTraversal.h"
#include "../traversal/DFS.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

TEST_CASE("DFS iterator starts at the start Airport", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    Airport startNode("Los Angeles International Airport","Los Angeles","United States","LAX",33.94250107,-118.4079971);
    DFS *dfs = AT.DepthFirstSearch(&startNode);
    REQUIRE(*(dfs->begin()) == startNode);

}

TEST_CASE("DFS visits the correct Airport first", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS *dfs = AT.DepthFirstSearch(AT.IATAsearch("ATL"));
    AirportTraversal::Iterator it = dfs->begin();
    ++it;
    Airport nextNode("Chicago O'Hare International Airport","Chicago","United States","ORD",41.9786,-87.9048);
    REQUIRE( *it == nextNode );
    
}

/** CDG DFS Traversal Explanation:
 * 
 * Evry line is the stack for every iteration
 * 
 * CDG
 * pop CDG -> visited
 * JFK, ORD
 * pop ORD -> visited
 * JFK, LAX, MAD, PEK
 * pop PEK -> visited
 * JFK, LAX, MAD, JFK, LAX, MAD
 * pop MAD -> visited
 * JFK, LAX, MAD, JFK, LAX, JFK, LAX
 * pop LAX -> visited
 * JFK, LAX, MAD, JFK, LAX, JFK
 * pop JFK -> visited
 * 
 * rest of stack is popped since already visisted
 * Order is CDG, ORD, PEK, MAD, LAX, JFK
 */

TEST_CASE("DFS visits all points for an Airport (CDG)", "[DFS]]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS dfs = *(AT.DepthFirstSearch(AT.IATAsearch("CDG")));
    unsigned count = 0;
    for (const Airport & p : dfs) {
        count++;
    }
    REQUIRE( count == 6 );
}

TEST_CASE("DFS iterator visits all points in the correct order", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS dfs = *(AT.DepthFirstSearch(AT.IATAsearch("CDG")));
    vector<std::string> ans = {"CDG", "ORD", "PEK", "MAD", "LAX", "JFK"};
    AirportTraversal::Iterator it = dfs.begin();

    REQUIRE( *it == *(AT.IATAsearch(ans[0])) ); ++it;
    REQUIRE( *it == *(AT.IATAsearch(ans[1])) ); ++it;
    REQUIRE( *it == *(AT.IATAsearch(ans[2])) ); ++it;
    REQUIRE( *it == *(AT.IATAsearch(ans[3])) ); ++it;
    REQUIRE( *it == *(AT.IATAsearch(ans[4])) ); ++it;
    REQUIRE( *it == *(AT.IATAsearch(ans[5])) ); ++it;
}

TEST_CASE("DFS maintains a depth-first ordering", "[DFS]") {
    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    Airport node0 = *(AT.IATAsearch("ATL"));
    DFS dfs = *(AT.DepthFirstSearch(&node0));
    
    Airport node1("Liverpool John Lennon Airport","Liverpool","United Kingdom","LPL",53.33359909057617,-2.849720001220703);
    Airport node2("Charles de Gaulle International Airport","Paris","France","CDG",49.012798,2.55);
    Airport node3("Adolfo Su??rez Madrid???Barajas Airport","Madrid","Spain","MAD",40.471926,-3.56264);

  dfs.add( node1 );
  dfs.add( node2 );
  dfs.add( node3 );

  REQUIRE( dfs.pop() == node3 );
  REQUIRE( dfs.pop() == node2 );
  REQUIRE( dfs.pop() == node1 );
  REQUIRE( dfs.pop() == node0);
}

TEST_CASE("DFS maintains the deepest point on top", "[DFS]") {
    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    Airport startNode("Adolfo Su??rez Madrid???Barajas Airport","Madrid","Spain","MAD",40.471926,-3.56264);

    DFS dfs = *(AT.DepthFirstSearch(&startNode));
    Airport node1("Liverpool John Lennon Airport","Liverpool","United Kingdom","LPL",53.33359909057617,-2.849720001220703);
    Airport node2("Charles de Gaulle International Airport","Paris","France","CDG",49.012798,2.55);
    Airport node3("Chicago O'Hare International Airport","Chicago","United States","ORD",41.9786,-87.9048);

    dfs.add( node1 );
    dfs.add( node2 );
    dfs.add( node3 );

    REQUIRE( dfs.peek() == node3 );
}