#pragma once
#include <map>
#include <string>
#include "Airport.h"
#include "cs225/PNG.h"
#include "Node.h"

class Graph {

public:
    Graph(std::map<std::string, Airport*> list);

private:
    std::vector<Node*> nodes;
    std::vector<Edge*> edges;
    
    //create image PNG
    cs225::PNG * image;
    
    double scaleX(double lon, int width);
    double scaleY(double lat, int width, int height);
    

};
