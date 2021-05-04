/*#include <sstream>
#include <string>
#include <iostream>
#include "dijkstras.h"
#include <map>
#include "Airport.h"
#include <sstream>
*/
//#include <iostream>
#include <queue>
#include "dijkstras.h"
//#include "dijkstras.hpp"
#include "Airport.h"
//#include "airport.hpp"

/*
 struct Airport_Node {
     Airport* data;
     Vertex* path;
     bool visited;
     
     Airport_Node(Airport* o_data) : data(o_data), path(NULL), visited(false) {}
     Airport_Node(Airport* o_data, Vertex* vertex) : data(o_data), path(vertex), visited(false) {}
 };

 struct Vertex{
     double source_distance = DBL_MAX;
     // double path_distance = DBL_MAX;
     Vertex * previous = NULL;
     Airport * data = NULL; //i think this should be a Vertex * and the source needs a previous to point at itself
     bool visited = false;
     
     bool operator < (const Vertex & other) { return (source_distance < other.source_distance); }
 };

 */

struct Vertex {
    Airport * start;
    Airport * end;
    double weight;
};

int Dijkstras(std::map<std::string, Airport*> airportList, Airport* source) {
/*
    //building the graph seen in lecture
    std::map<std::string, Airport *>::iterator it;
    
    for (it = airportList.begin(); it != airportList.end(); it ++) {
        unsigned long num_destinations = it->second->destinations.size();
        for (unsigned long i = 0; i < num_destinations; i ++) {
            Vertex vertex;
            vertex.start = it->second;
            vertex.end = it->second->destinations[i].other_airport;
            vertex.weight = it->second->destinations[i].distance;
        }
    }
    */
    return 0;
}



/*
 
 for (it = airportList.begin(); it != airportList.end(); it ++) {
     Vertex vertex;
     vertex.data = it->second;

     if (vertex.data == source) {
         vertex.source_distance = 0;
         vertex.previous = &vertex;
         pq.push(vertex);
     }
 }
 
 while (!pq.empty()) {
     current = pq.top();
     pq.pop();

     if (current.visited == false) {
         current.visited = true;
         current.source_distance = current.previous->source_distance + current.data//got to get the distance from here
     }
     
     
     
     double distance = current.data->destinations[i].distance + current.previous->source_distance;
     
     //        unsigned long num_destinations = current.data->destinations.size();
     if (current.visited == false) {            //this means we haven't seen this node before
         current.visited = true;
         //mark it as visited, find the distance to the source
         current.source_distance = current.data->destinations[i].distance + current.previous->source_distance;
     }
     for (auto i = 0; i < num_destinations; i ++) {
         
     }
 }
 
 */


/*
 Need to make sure this is not a multi edge graph.
 Must take every unique path and sort it by distance using a priority queue.
 Need a visisted vector or something
 */






