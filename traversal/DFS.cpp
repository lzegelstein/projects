#include <iterator>
#include <cmath>
#include <iostream>
	
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include "AirportTraversal.h"
#include "../Airport.h"
#include "DFS.h"



//Copied from mp traversals
/**
 * Initializes a depth-first AirportTraversal on a given `png` image,
 * starting at `start' Airport Node
 * 
 * @param list The map this DFS is going to traverse
 * @param start The start point of this DFS
 */

DFS::DFS(const std::map<std::string, AirTravel::Airport*> list, const AirTravel::Airport & start) 
: list(list), current(start) {
    S.push(start);
}


/**
 * Returns an iterator for the traversal starting at the first Airport
 */
AirportTraversal::Iterator DFS::begin() {
  //Office hours question 
  return AirportTraversal::Iterator(this, list, current);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
AirportTraversal::Iterator DFS::end() {

  return AirportTraversal::Iterator();

}

/**
 * Adds a Airport for the traversal to visit at some point in the future.
 */
void DFS::add(const Airport & node) {

    S.push(node);
}

/**
 * Removes and returns the current Airport in the traversal.
 */
Airport DFS::pop() {
  
  AirTravel::Airport p = S.top();
  S.pop();
  return p;
  
}

/**
 * Returns the current Airport in the traversal.
 */
Airport DFS::peek() const {
  
  return S.top();
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {

  return S.empty();
}
