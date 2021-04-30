#pragma once
	
#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include "AirTravel.h"
#include "AirportTraversal.h"
//copied from mp traversals

/**
 * A depth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class DFS  {
public:
  DFS(const std::map<std::string, AirTravel::Airport*> list, const AirTravel::Airport & start);

  AirportTraversal::Iterator begin();
  AirportTraversal::Iterator end();

  void add(const AirTravel::Airport & node);
  AirTravel::Airport pop();
  AirTravel::Airport peek() const;
  bool empty() const;

private:
	/** @todo [Part 1] */
	/** add private members here*/
  std::stack<AirTravel::Airport> S;
  std::map<std::string, AirTravel::Airport*> list;
  AirTravel::Airport current;
  double tolerance;
};
