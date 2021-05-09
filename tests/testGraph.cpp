#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../traversal/AirportTraversal.h"
#include "../traversal/DFS.h"
#include "../Node.h"
#include "../cs225/PNG.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

TEST_CASE("PNG output of a Node", "[Graph]") {
    Node curr(100,100,15);
    cs225::PNG image;
    //image.readFromFile("graphs/out-1.png");
    image.resize(200,200);
    drawNode(curr, image);
    image.writeToFile("graphs/out-2.png");
}