#pragma once
	
#include <iterator>
#include <cmath>
#include <list>
#include <stack>
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
  DFS(const std::map<std::string, AirTravel::Airport*> list, const AirTravel::Airport & start);

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
  void add(const AirTravel::Airport & node);

  /**
   * Popping and returning the current Airport in the traversal
   */
  AirTravel::Airport pop();

  /**
   * Peeking at the current Airport in the traversal
   */
  AirTravel::Airport peek() const;

  /**
   * @returns true if traversal is empty
   */
  bool empty() const;

  /**
   * The current DFS stack of Airports
   */
  std::stack<AirTravel::Airport> S;
  
private:
  /**
   * All Airport IATA codes mapped to Airport nodes
   * @param list map
   */
  std::map<std::string, AirTravel::Airport*> list;

  /**
   * Current airport node
   */
  AirTravel::Airport current;
};
