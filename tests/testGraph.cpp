#include "../cs225/catch/catch.hpp"
#include "../AirTravel.h"
#include "../traversal/AirportTraversal.h"
#include "../traversal/DFS.h"
#include "../graph.h"
#include "../cs225/PNG.h"

using namespace std;
#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

TEST_CASE("PNG output of a Node", "[Graph]") {
    Node curr(100,100,15, NULL);
    cs225::PNG image;
    //image.readFromFile("graphs/out-1.png");
    image.resize(200,200);
    drawNode(curr, image);
    image.writeToFile("graphs/out-2.png");
}

TEST_CASE("PNG output of two Nodes and edge (Northwest)", "[Graph]") {
    Node one(50, 50, 2, NULL);
    Node two(100,100, 4, NULL);
    //Edge line(&one, &two, 70.71);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-3.png");
}

TEST_CASE("PNG output of two Nodes and edge (Southeast)", "[Graph]") {
    Node one(100, 100, 2, NULL);
    Node two(50, 50, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-4.png");
}

TEST_CASE("PNG output of two Nodes and edge (Horizontal)", "[Graph]") {
    Node one(50, 100, 2, NULL);
    Node two(100, 100, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-5.png");
}

TEST_CASE("PNG output of two Nodes and edge (Vertical)", "[Graph]") {
    Node one(100, 100, 2, NULL);
    Node two(100, 50, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-6.png");
}

TEST_CASE("PNG output of two Nodes and edge (Northeast)", "[Graph]") {
    Node one(100, 50, 2, NULL);
    Node two(50, 100, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-7.png");
}

TEST_CASE("PNG output of two Nodes and edge (Southwest)", "[Graph]") {
    Node one(50, 100, 2, NULL);
    Node two(100, 50, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-8.png");
}

TEST_CASE("PNG output of two Nodes and edge (Edge case: not quite horizontal)", "[Graph]") {
    Node one(50, 100, 2, NULL);
    Node two(100, 99, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-9.png");
}

TEST_CASE("PNG output of two Nodes and edge (Edge case: not quite vertical)", "[Graph]") {
    Node one(50, 100, 2, NULL);
    Node two(49, 50, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-10.png");
}

TEST_CASE("PNG output of two Nodes and edge (Edge case: not quite Northeast)", "[Graph]") {
    Node one(100, 50, 2, NULL);
    Node two(49, 100, 4, NULL);
    cs225::PNG image;
    image.resize(500, 500);
    drawNode(one, image);
    drawNode(two, image);

    drawEdge(&one, &two, image);
    image.writeToFile("graphs/out-11.png");
}