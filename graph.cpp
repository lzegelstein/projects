
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "graph.h"

/**
 * TODO: Rework to work with new class definition
 */
Graph::Graph(std::map<std::string, Airport*> list){
   
   // image->resize(600,600); //TODO: make it an input later :)
    image = new cs225::PNG(600,600);
    
    for (auto it : list){
        double x = it.second->longitude;
        double y = it.second->latitude;

        x = scaleX(x, image->width());
        y = scaleY(y, image->width(), image->height());
        
        Node* node = new Node(x, y, (unsigned int) it.second->destinations.size(), it.second);
        nodes.push_back(node);
        
//        unsigned long size_ = it.second->destinations.size();
//        for (unsigned long i = 0; i < size_; i ++) {
//            //add in edges here
//        }
    }
    
    
}

double Graph::scaleX(double lon, int width) {
    double x = fmod((width*(180+lon)/360), (width +(width/2)));

    return x;
}

double Graph::scaleY(double lat, int width, int height) {
    
    double PI = 3.14159265359;
    double latRad = lat*PI/180;
    // get y value
    double mercN = log(tan((PI/4)+(latRad/2)));
    double y     = (height/2)-(width*mercN/(2*PI));
    
    return y;
}

/*
 
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

 image->resize((distx_max - distx_min), (disty_max - disty_min));

 //populate nodes and edges
 for(auto it: list){
     Airport air_curr = *(it.second);
     int x = air_curr.latitude - distx_min;
     int y = air_curr.longitude - disty_min;
     Node node_curr(x, y, air_curr.destinations.size(), & air_curr);
     nodes.push_back(node_curr);

     for(auto j : air_curr.destinations){
         int x = j.other_airport->latitude - distx_min;
         int y = j.other_airport->longitude - disty_min;
         Node other(x, y, j.other_airport->destinations.size(), & air_curr.destinations[j]);
         Edge edge_curr(node_curr, other, j.distance);
         edges.push_back(edge_curr);
     }
 }


//    for(auto it: nodes){
//        drawNode(it, image);
//    }
//
//    for(auto it: edges){
//        drawEdge(it, image);
//    }


 */
