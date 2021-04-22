#pragma once
	
#include <vector>
#include <algorithm>
#include <string>

	
class Dijkstras {
    public:
        //Constructor that creates a graph from the data from airplane/routes
        Dijkstras(std::vector<std::vector<std::string>> data);
	
        //Constructor creates vector of edges (shortest path)
        std::vector<Edge> edges(Vertex a, Vertex b);
	
        //Main Dijkstras function, has all the helper functions
        std::vector<Edge> mainDijkstras(std::vector<std::vector<std::string>> data, Vertex a, Vertex b);

    private:
};