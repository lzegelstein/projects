
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "graph.h"
#include <math.h>


void drawNode(Node circle, cs225::PNG &image){
    //if the node is invalid
    if (circle.x > image.width() || circle.y > image.height()) {
        return;
    }

    //set color
    int hue = 210 - (circle.size * circle.size);
    
    if (hue < 0) {
        hue = 0;
    }
    
    cs225::HSLAPixel color(hue, 1, 0.5, 1); //the color will change depending on node size exponentially

    //draw node
    int size_x_max = circle.x + circle.size;
    int size_y_max = circle.y + circle.size;
    int size_x_min = circle.x - circle.size;
    int size_y_min = circle.y - circle.size;

    int distx = size_x_max - size_x_min;
    int disty = size_y_max - size_y_min;

    for (int i = 0; i <= distx; i++) {
        for (int j = 0; j <= disty; j++) {
            //calculate euclidean distance
            double dx = (size_x_max - i);
            double dy = (size_y_max - j);
            double dist = sqrt(((circle.x-dx) * (circle.x-dx)) + ((circle.y-dy) * (circle.y-dy)));
            
            if (dist <= circle.size) {
                
                cs225::HSLAPixel& curr_pixel = image.getPixel(dx, dy);
                curr_pixel = color;
            }
        }
    }
}

void drawEdge(Node* start, Node* end, cs225::PNG &image){

    //if the line is invalid
    if (start->x > image.width() || end->x > image.width() ||
       start->y > image.height() || end->y > image.height()) {
        return;
    }

    cs225::HSLAPixel color(360, 1, 0, 1);

    double slope = (end->y - start->y) / (end->x - start->x);

    unsigned i_start, i_end, j_start, j_end;

    if(start->x <= end->x){
        i_start = start->x;
        i_end = end->x;
    } else {
        i_start = end->x;
        i_end = start->x;
    }

    if(start->y <= end->y){
        j_start = start->y;
        j_end = end->y;
    } else {
        j_start = end->y;
        j_end = start->y;
    }

    double num = j_end - j_start;
    double den = i_end - i_start;
    double diff_1 = j_end - i_start;
    double diff_2 = i_end - j_start;


    if(den < 3){
        //case if the slope is vertical facing
        for(unsigned j = j_start; j <= j_end; j++){
            cs225::HSLAPixel& curr_pixel = image.getPixel(start->x, j);
            curr_pixel = color;
            color.l = color.l; //increasing lumosity of line

        }
        return;
    }

    if(num < 3){
        //case if slope is horizontally facing
        for(unsigned i = i_start; i <= i_end; i++){
            cs225::HSLAPixel& curr_pixel = image.getPixel(i, start->y);
            curr_pixel = color;
            color.l = color.l; //increasing lumosity of line

        }
        return;
    }

    //hey this doesn't work if end->x is less than the start->x
    for (unsigned i = i_start; i <= i_end; i++) {
        for (unsigned j = j_start; j <= j_end; j++) {

            double ij_slope = (end->y - j) / (end->x - i);
            double error = abs(float(slope - ij_slope)); //need error to account for pixel slopes not being perfect
            
            if (error <= 0.0197) {
                cs225::HSLAPixel& curr_pixel = image.getPixel(i, j);
                curr_pixel = color;
                color.l = color.l; //increasing lumosity of line
                break;
            }
        }
    }

}

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
    }

    
}


// don't forget to cite this!!

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

// void Graph::addEdge(Node* source, Node* dest, double distance) {
//     bool done;
//     Edge* current = new Edge(source, dest, distance);
//     for (int i = 0; i < (int) edges.size(); i++) {
//         if(current == edges[i]){
//             done = true;
//             delete current;
//             return;
//         }
//     }
//     edges.push_back(current);
// }

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
