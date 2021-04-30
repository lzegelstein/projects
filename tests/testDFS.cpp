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

TEST_CASE("DFS iterator starts at the start Airport", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    AirTravel::Airport startNode("Los Angeles International Airport","Los Angeles","United States","LAX",33.94250107,-118.4079971);
    DFS dfs(AT.AirportList, startNode);
    REQUIRE(*(dfs.begin()) == startNode);

}

TEST_CASE("DFS visits the correct Airport first", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS dfs(AT.AirportList, *(AT.AirportList.at("ATL")));
    AirportTraversal::Iterator it = dfs.begin();
    ++it;
    AirTravel::Airport nextNode("Chicago O'Hare International Airport","Chicago","United States","ORD",41.9786,-87.9048);
    REQUIRE( *it == nextNode );
    
}

/** CDG DFS Traversal Explanation:
 * 
 * CDG -> JFK +2
 * 
 * JFK -> CDG -> stop
 * JFK -> LAX +3
 * 
 * LAX -> JFK -> stop
 * LAX -> MAD +4
 * 
 * MAD -> JFK -> stop
 * MAD -> LAX -> stop
 * MAD -> ORD +5
 * 
 * ORD -> CDG -> stop
 * ORD -> JFK -> stop
 * ORD -> LAX -> stop
 * ORD -> MAD -> stop
 * ORD -> PEK +6
 * 
 * PEK -> CDG -> stop
 * PEK -> JFK -> stop
 * PEK -> LAX -> stop
 * PEK -> MAD -> stop
 * PEK -> ORD -> stop
 * 
 * MAD -> PEK -> stop
 * LAX -> ORD -> stop
 * JFK -> MAD -> stop
 * JFK -> ORD -> stop
 * CDG -> ORD -> stop
 */

TEST_CASE("DFS visits all points for an Airport (CDG)", "[DFS]]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS dfs(AT.AirportList, *(AT.AirportList.at("CDG")));
    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "ORD", "PEK"};

    unsigned count = 0;
    for (const AirTravel::Airport & p : dfs) {
        REQUIRE(p.IATA == ans[count]);
        count++;
    }
    REQUIRE( count == 6 );
}

TEST_CASE("DFS iterator visits all points in the correct order", "[DFS]") {

    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");
    DFS dfs(AT.AirportList, *(AT.AirportList.at("CDG")));
    vector<std::string> ans = {"CDG", "JFK", "LAX", "MAD", "ORD", "PEK"};
    AirportTraversal::Iterator it = dfs.begin();

    REQUIRE( *it == *(AT.AirportList.at(ans[0])) ); ++it;
    REQUIRE( *it == *(AT.AirportList.at(ans[1])) ); ++it;
    REQUIRE( *it == *(AT.AirportList.at(ans[2])) ); ++it;
    REQUIRE( *it == *(AT.AirportList.at(ans[3])) ); ++it;
    REQUIRE( *it == *(AT.AirportList.at(ans[4])) ); ++it;
    REQUIRE( *it == *(AT.AirportList.at(ans[5])) ); ++it;
}

TEST_CASE("DFS maintains a depth-first ordering", "[weight=0][part=1][part=1a]") {
    AirTravel AT = AirTravel("data/airports-short.csv", "data/routes-short.csv");

    AirTravel::Airport node0 = *(AT.AirportList.at("ATL"));
    DFS dfs(AT.AirportList, node0);
    
    AirTravel::Airport node1("Liverpool John Lennon Airport","Liverpool","United Kingdom","LPL",53.33359909057617,-2.849720001220703);
    AirTravel::Airport node2("Charles de Gaulle International Airport","Paris","France","CDG",49.012798,2.55);
    AirTravel::Airport node3("Adolfo Suárez Madrid–Barajas Airport","Madrid","Spain","MAD",40.471926,-3.56264);

  dfs.add( node1 );
  dfs.add( node2 );
  dfs.add( node3 );

  REQUIRE( dfs.pop() == node3 );
  REQUIRE( dfs.pop() == node2 );
  REQUIRE( dfs.pop() == node1 );
  REQUIRE( dfs.pop() == node0);
}


//Extra test cases, not really required since they are pretty repetitive


// TEST_CASE("DFS visits all points within a tolerance (includes pixels on image edge)", "[weight=1][part=1]") {
//   PNG png = getTestPNG();
//   Point startPoint(0, 0);
  
//   DFS t(png, startPoint, 0.2);
//   unsigned count = 0;
//   for (const Point & p : t) { count++; }

//   REQUIRE( count == 12 );
// }

// TEST_CASE("DFS iterator visits all points in the correct order (7x4 image)", "[weight=1][part=1]") {
//   PNG png = getTestPNG_8x4();
//   Point startPoint(2, 2);
  
//   DFS t(png, startPoint, 0.2);
//   ImageTraversal::Iterator it = t.begin();

//   REQUIRE( *it == Point(2, 2) ); ++it; 
//   REQUIRE( *it == Point(2, 1) ); ++it;

//   REQUIRE( *it == Point(1, 1) ); ++it;
//   REQUIRE( *it == Point(1, 2) ); ++it;

//   REQUIRE( *it == Point(3, 1) ); ++it;
//   REQUIRE( *it == Point(3, 2) ); ++it;

//   REQUIRE( *it == Point(4, 2) ); ++it;
//   REQUIRE( *it == Point(4, 1) ); ++it;

//   REQUIRE( *it == Point(5, 1) ); ++it;

//   REQUIRE( *it == Point(6, 1) ); ++it;
//   REQUIRE( *it == Point(6, 2) ); ++it;
// }

// TEST_CASE("DFS maintains the deepest point on top", "[weight=0][part=1][part=1a]") {
//   PNG png(40, 40);
//   Point startPoint(20, 20);
//   DFS dfs(png, startPoint, 0.2);

//   dfs.add( Point(2, 2) );
//   dfs.add( Point(2, 3) );
//   dfs.add( Point(2, 4) );

//   REQUIRE( dfs.peek() == Point(2, 4) );
// }
