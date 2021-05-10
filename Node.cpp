#include "Node.h"
#include <math.h>

bool Edge::operator==(const Edge& other) {
    bool oneway = (start == other.start && end == other.end);
    bool another = (start == other.end && end == other.start);
    return (oneway || another);
}

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

void drawEdge(Edge line, cs225::PNG &image){

    //if the line is invalid
    if (line.start->x > image.width() || line.end->x > image.width() ||
       line.start->y > image.height() || line.end->y > image.height()) {
        return;
    }

    cs225::HSLAPixel color(360, 1, 0, 1);
    double increment = 0.5/line.length; //will increase the lumosity of hsla pixel

    double slope = (line.end->y - line.start->y) / (line.end->x - line.start->x);

    unsigned i_start, i_end, j_start, j_end;

    if(line.start->x <= line.end->x){
        i_start = line.start->x;
        i_end = line.end->x;
    } else {
        i_start = line.end->x;
        i_end = line.start->x;
    }

    if(line.start->y <= line.end->y){
        j_start = line.start->y;
        j_end = line.end->y;
    } else {
        j_start = line.end->y;
        j_end = line.start->y;
    }

    double num = j_end - j_start;
    double den = i_end - i_start;
    double diff_1 = j_end - i_start;
    double diff_2 = i_end - j_start;


    if(den < 3){
        //case if the slope is vertical facing
        for(unsigned j = j_start; j <= j_end; j++){
            cs225::HSLAPixel& curr_pixel = image.getPixel(line.start->x, j);
            curr_pixel = color;
            color.l = color.l + increment; //increasing lumosity of line

        }
        return;
    }

    if(num < 3){
        //case if slope is horizontally facing
        for(unsigned i = i_start; i <= i_end; i++){
            cs225::HSLAPixel& curr_pixel = image.getPixel(i, line.start->y);
            curr_pixel = color;
            color.l = color.l + increment; //increasing lumosity of line

        }
        return;
    }

    //hey this doesn't work if line.end->x is less than the line.start->x
    for (unsigned i = i_start; i <= i_end; i++) {
        for (unsigned j = j_start; j <= j_end; j++) {

            double ij_slope = (line.end->y - j) / (line.end->x - i);
            double error = abs(float(slope - ij_slope)); //need error to account for pixel slopes not being perfect
            
            if (error <= 0.0197) {
                cs225::HSLAPixel& curr_pixel = image.getPixel(i, j);
                curr_pixel = color;
                color.l = color.l + increment; //increasing lumosity of line
                break;
            }
        }
    }

}
