#pragma once
	
#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include <map>
#include "../AirTravel.h"
#include "AirportTraversal.h"

/**
 * A depth-first AirportTraversal.
 * Derived from base class AirportTraversal
 */
class DFS : public AirportTraversal{
public:
  /**
   * Constructor for DFS
   */
  DFS(const std::map<std::string, Airport*> list, const Airport & start);

  /**
   * Returns the iterator position for the beginning Airport
   */
  AirportTraversal::Iterator begin();

  /**
   * Returns iterator position for one after the end of the Airport traversal
   */
  AirportTraversal::Iterator end();

  /**
   * Function for adding an airport node to the traversal
   * 
   * @param node Airport
   */
  void add(const Airport& node);

  /**
   * Popping and returning the current Airport in the traversal
   */
  Airport pop();

  /**
   * Peeking at the current Airport in the traversal
   */
  Airport peek() const;

  /**
   * @returns true if traversal is empty
   */
  bool empty() const;

private:
  /**
   * The current DFS stack of Airports
   */
  std::stack<Airport> S;

  /**
   * All Airport IATA codes mapped to Airport nodes
   * @param list map
   */
  std::map<std::string, Airport*> list;

  //Should this be a pointer?
  /**
   * Current airport node
   */
  Airport current;
};
