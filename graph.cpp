#include <map>
#include <vector>
#include <string>
#include "graph.h"
#include "cs225/PNG.h"
#include "Node.h"
#include "Airport.h"

/**
 * TODO: Rework to work with new class definition
 */
graph::graph(std::map<std::string, Airport*> list){
    std::vector<Node> nodes;
    std::vector<Edge> edges;

    int distx_max = 0;
    int distx_min = 0;
    int disty_max = 0;
    int disty_min = 0;

    //find current max/min size of image
    for(auto it: list){
        Airport air_curr = *(it.second);
        if(air_curr.latitude > distx_max){
            distx_max = air_curr.latitude;
        }
        if(air_curr.latitude < distx_min){
            distx_min = air_curr.latitude;
        }
        if(air_curr.longitude > disty_max){
            disty_max = air_curr.longitude;
        }
        if(air_curr.longitude < disty_min){
            disty_min = air_curr.longitude;
        }
    }

    //create image PNG
    cs225::PNG image((distx_max - distx_min), (disty_max - disty_min));

    //populate nodes and edges
    for(auto it: list){
        Airport air_curr = *(it.second);
        int x = air_curr.latitude - distx_min;
        int y = air_curr.longitude - disty_min;
        Node node_curr(x, y, air_curr.destinations.size());
        nodes.push_back(node_curr);

        for(auto j : air_curr.destinations){
            int x = j.other_airport->latitude - distx_min;
            int y = j.other_airport->longitude - disty_min;
            Node other(x, y, j.other_airport->destinations.size());
            Edge edge_curr(node_curr, other, j.distance);
            edges.push_back(edge_curr);
        }  
    }

    for(auto it: nodes){
        drawNode(it, image);
    }

    for(auto it: edges){
        drawEdge(it, image);
    }

    return image;
}