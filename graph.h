#pragma once
#include <map>
#include <string>
#include "Airport.h"
#include "cs225/PNG.h"
#include "Node.h"

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
    cs225::PNG* getPNG();

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
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    

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

    /**
     * creates and adds edge to the edges vector
     * helper function to the constructor
     * 
     * Makes sure not to have repeat lines
     * 
     * @param source begining node
     * @param destination ending node
     * @param distance distance on the image
     */
    void addEdge(Node* source, Node* destination, double distance);
};
