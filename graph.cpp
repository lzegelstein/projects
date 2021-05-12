
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include "graph.h"
#include <math.h>

Graph::Graph(std::map<std::string, Airport*> list, unsigned int height, unsigned int width, Airport* busy) {
   
    busiest = busy;
    image = new cs225::PNG(width,height);
    
    for (auto it : list) {
        double x = it.second->longitude;
        double y = it.second->latitude;

        x = scaleX(x, image->width());
        y = scaleY(y, image->width(), image->height());
        
        Node* node = new Node(x, y, (unsigned int) it.second->destinations.size(), it.second);
        nodeMap[it.second] = node;
    }
    
    for (auto i : nodeMap) {
        for (auto j : i.first->destinations) {
            i.second->edges.push_back(nodeMap[j.other_airport]);
        }
    }

}

cs225::PNG* Graph::makeImage() {

    for (auto i : nodeMap) {
        for (auto j : i.second->edges) {  
            drawEdge(i.second, j, * image);
        }
    }

    for (auto i : nodeMap) {
        drawNode(*i.second, * image);
    }
    return image;
    }

void Graph::drawNode(Node circle, cs225::PNG &image){
    //if the node is invalid
    if (circle.x > image.width() || circle.y > image.height()) {
        return;
    }
    
    double max_color = (double) busiest->destinations.size();
    double percent_color = ((double) circle.size) / max_color;

    //set color
    double hue = 235 - (235 * percent_color);
    
    if (hue < 0) {
        hue = 0;
    }
    
    circle.size = sqrt(int(circle.size)) * (image.width() / image.height()) + image.width()/2000;

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
            
            if (dist <= circle.size && dx < image.width() && dy < image.height() && dx > 0 && dy > 0) {
                cs225::HSLAPixel& curr_pixel = image.getPixel(dx, dy);
                curr_pixel = color;
            }
        }
    }
}

void Graph::drawEdge(Node* start, Node* end, cs225::PNG &image){

    //if the line is invalid
    if (start->x >= image.width() || end->x >= image.width() ||
       start->y >= image.height() || end->y >= image.height()) {
        return;
    }

    cs225::HSLAPixel color(360, 1, 0, 1);

    double slope = (end->y - start->y) / (end->x - start->x);

    unsigned i_start, i_end, j_start, j_end;

    if (start->x <= end->x) {
        i_start = start->x;
        i_end = end->x;
    } 
    else {
        i_start = end->x;
        i_end = start->x;
    }

    if (start->y <= end->y) {
        j_start = start->y;
        j_end = end->y;
    } 
    else {
        j_start = end->y;
        j_end = start->y;
    }

    double num = j_end - j_start;
    double den = i_end - i_start;
    double diff_1 = j_end - i_start;
    double diff_2 = i_end - j_start;


    if (den < 1) {
        //case if the slope is vertical facing
        for(unsigned j = j_start; j <= j_end; j++){
            cs225::HSLAPixel& curr_pixel = image.getPixel(start->x, j);
            curr_pixel = color;
            color.l = color.l; //increasing lumosity of line

        }
        return;
    }

    // if(num < 1){
    //     //case if slope is horizontally facing
    //     for(unsigned i = i_start; i <= i_end; i++){
    //         cs225::HSLAPixel& curr_pixel = image.getPixel(i, start->y);
    //         curr_pixel = color;
    //         color.l = color.l; //increasing lumosity of line

    //     }
    //     return;
    // }

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

//Source for scaleX and scaleY:
//https://stackoverflow.com/questions/16080225/convert-lat-long-to-x-y-coordinates-c

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
