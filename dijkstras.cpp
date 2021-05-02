#include <sstream>
#include <string>
#include <iostream>
#include "dijkstras.h"
#include <map>
#include "Airport.h"
//#include "dijstrika.hpp"
//Dijkstra's is correct spelling -> I messed it up in the file name in xCode, my bad

int Dijkstras(std::map<std::string, Airport*> airportList, Airport* source) { //TODO
    struct Vertex {
        double source_distance = DBL_MAX;
        Vertex * previous = NULL;
        Airport * data = NULL; //i think this should be a Vertex * and the source needs a previous to point at itself
        bool visited = false;
    };
    
    std::priority_queue<Vertex, std::vector<Vertex>, std::greater<double> > pq;
//we need a vector of verticies
    
    std::map<std::string, Airport *>::iterator it;
    Vertex * current;

    for (it = airportList.begin(); it != airportList.end(); it ++) {
        Vertex vertex;
        vertex.data = it->second;

        if (vertex.data == source) {
            vertex.source_distance = 0;
            vertex.previous = &vertex;
            pq.push(vertex);
        }
    }
    
    Vertex* start;
    start->source_distance = 0;
    start->previous = start;
    start->data = source;
    pq.push(start);
    
    while (!pq.empty()) {
        current = pq.top();
        pq.pop();
        unsigned long num_destinations = current->data->destinations.size();
        for (auto i = 0; i < num_destinations; i ++) {
            if (current->visited == false) {            //this means we haven't seen this node before
                current->visited = true;
                //mark it as visited, find the distance to the source
                current->source_distance = current->data->destinations[i].distance + current->previous->source_distance;
                //Now, need to see where else you can get to, and push those vertices to the pq
                unsigned long other_vertices_inreach = current->data->destinations.size();
                for (auto j = 0; j < other_vertices_inreach; j ++) {
                    
                }
            }
        }
    }
    return 0;
}

/*
 Need to make sure this is not a multi edge graph.
 Must take every unique path and sort it by distance using a priority queue.
 Need a visisted vector or something
 */

/*
 Algorithm: I will be calculating the relative distance based on a starting point
 
 1. Mark every node as unvisited and set the distance to 0 for current node and infinity for the rest.
Where to I want to keep track of what is visited and what isn't?
 Could do this as a boolean private member variable and the default is unvisited. Maybe need a more systematic way like a vector? Nope, we probably won't be going to every node.
 
 2. Look at the univisted airports in the destinations vector of the current and those will have the distance already calculated. Add it to the AVL Tree representing the Min Priority Queue. If the node was already visited, then compare the new distance and update it if the new distance is smaller
 
 3. You only mark the current cell as visited, not the neighbors!
 
 Don't have to visit every airport, just the ones you can get to.
 
 start at the start, and then look at only the airports you can get to, then start going through each of those and add all of the airports that they can get to and visit all of those
 
 make a queue and start keeping track of the other airports that you need to visit
 
 Keep track of the running paths. Maybe in an uptree? If we just keep visiting other nodes, the uptree will help find the shortest path. That way you find the shortest, you know the path to it and don't need to refind that.
 */



/*
Dijkstras::Dijkstras(std::vector<std::vector<std::string>> data) {

}
    
std::vector<Edge> Dijkstras::Dijkstras_Helper(Vertex a, Vertex b) {

}
    
std::vector<Edge> mainDijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b) {

}
*/
