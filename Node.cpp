#include "Node.h"

void drawNode(Node circle, cs225::PNG image){
    //if the node is invalid
    if(circle.x > image.width() || circle.y > image.height()){
        return;
    }

    //set color
    int hue = 210 - (circle.size*circle.size);
    if(hue < 0){
        hue = 0;
    }
    cs225::HSLAPixel color(hue, 1, 0.5, 1); //the color will change depending on node size exponentially

    //draw node
    int size_x_max = circle.x + circle.size; 
    int size_y_max = circle.y + circle.size;
    int size_x_min = circle.x - circle.size;
    int size_y_min = circle.y - circle.size;

    for(int i = size_x_min; i <= size_x_max; i++){
        for(int j = size_y_min; j <= size_y_max; j++){
            //calculate euclidean distance
            double dx = (circle.x - i);
            double dy = (circle.y - j);
            double dist = (dx * dx) + (dy * dy);
            if(dist <= circle.size){
                cs225::HSLAPixel& curr_pixel = image.getPixel(i, j);
                curr_pixel = color;
            }
        }
    }
}

void drawEdge(Edge line, cs225::PNG image){

    //if the line is invalid
    if(line.start.x > image.width() || line.end.x > image.width() || 
        line.start.y > image.height() || line.end.y > image.height()){
        return;
    }

    cs225::HSLAPixel color(360, 1, 0, 1);
    double increment = 0.5/line.length; //will increase the lumosity of hsla pixel

    double slope = (line.end.y - line.start.y) / (line.end.x - line.start.x);

    for(unsigned i = line.start.x; i <= line.end.x; i++){
        for(unsigned j = line.start.y; j <= line.end.y; j++){
            double ij_slope = (line.end.y - j) / (line.end.x - i);
            double error = abs(slope - ij_slope);
            if(error <= 0.5){
                cs225::HSLAPixel& curr_pixel = image.getPixel(i, j);
                curr_pixel = color;
                color.l = color.l + increment;
            }
        }
    }

}