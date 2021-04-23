#include <iterator>
#include <cmath>
	
#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "DFS.h"

//takes in # of vertices and the starting vertice
DFS::DFS(std::vector<Vertex> v,  Vertex w){
    std::map<std::string, Airport*>::iterator it = AirportList.begin();
     while (it != AirportList.end())
     {
        //Accessing VALUE from element pointed by it.
         Airport* count = it->second;
         _vertice.push_back(count);
         it++;
     }
    adj = std::map<Vertex, std::vector<Vertex>> ();
    visited[i] = true;
}