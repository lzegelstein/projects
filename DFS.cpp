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

//Copied from mp traversals
/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * 
 * @param png The image this DFS is going to traverse
 * @param start The start point of this DFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this DFS
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) 
: image(png), current(start), tolerance(tolerance){  
  /** @todo [Part 1] */
 S.push(start);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this, image, current, tolerance);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();

}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
    S.push(point);
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  
  Point p = S.top();
  S.pop();
  return p;
  
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return S.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return S.empty();
}
