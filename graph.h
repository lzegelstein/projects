#pragma once
#include <map>
#include <string>
#include <vector>
#include "Airport.h"
#include "cs225/PNG.h"
#include <iostream>
#include <sstream>
#include "cs225/HSLAPixel.h"
#include "Airport.h"

/**
 * Simple Node class containing a public unsigned `x` and `y` for representing 2D points on an image.
 */
struct Node {
    double x;
    double y;
    unsigned size; //this is the radius of the circle
    Airport * airport;
    std::vector<Node *> edges;
    
  /**
   * Default constructor, set the point to (0, 0): 0
   */
    Node() : x(0), y(0), size(0), airport(NULL) { }
  /**
   * Constructor
   * @param x coordinate of a point
   * @param y coordinate of a point
   */
    Node(double x, double y, unsigned int size, Airport * airport) : x(x), y(y), size(size), airport(airport) {}

  /**
   * overload operator ==
   * @param other The other point
   * @return True for smaller, false for otherwise
   */
  bool operator==(const Node &other) const {
    return (x == other.x && y == other.y);
  }

 };

/**
 * Draws the node onto the image PNG
 *
 * @param circle current node to draw
 * @param image PNG for the node to draw on
 */
void drawNode(Node circle, cs225::PNG &image);

/**
 * Draws the edge line onto the image PNG
 *
 * @param line current edge (line between two nodes) to draw
 * @param image PNG for the node to draw on
 */
void drawEdge(Node* start, Node* end, cs225::PNG &image);

class Graph {
public:
    /**
     * Constructor for graph class
     * Populates nodes and edges using the map
     * passed in
     * 
     * @param list a map of airport pointers with their IATA codes
     * being the key
     */
    Graph(std::map<std::string, Airport*> list);
    
    void addNewEdge(Airport* source, Airport* end);

    void removeEdge(Airport* source, Airport* end);

    /**
     * function that finds nodes given
     * an IATA code in a string
     * 
     * @param IATA string of code to look for
     * 
     * @returns a poitner to the node found
     */
    Node* getNode(std::string IATA);

    /**
     * Draws edges and nodes on to PNG
     * 
     * @returns pointer to PNG
     */
    cs225::PNG* makeImage();

private:
    std::map<Airport *, Node *> nodeMap;
    cs225::PNG * image;
    
    /**
     * scales the longitude to the image width using a
     * Mercator projection
     * 
     * @param lon Longitude of airport
     * @param width width of PNG
     * 
     * @returns x-coordinate after scaling
     */
    double scaleX(double lon, int width);

    /**
     * scales the latitude to the image height and width
     * using a Mercator projection
     * 
     * @param lat Latitude of airport
     * @param width width of PNG
     * @param hegiht height of PNG
     * 
     * @returns y-coordinatre after scaling
     */
    double scaleY(double lat, int width, int height);

};
