#pragma once
	
#include <iterator>
#include <cmath>
#include <list>
#include <stack>
#include "AirTravel.h"
#include "AirportTraversal.h"

/**
 * A depth-first AirportTraversal.
 * Derived from base class AirportTraversal
 */
class DFS : public AirportTraversal{
public:
  DFS(const std::map<std::string, AirTravel::Airport*> list, const AirTravel::Airport & start);

  AirportTraversal::Iterator begin();
  AirportTraversal::Iterator end();

  void add(const AirTravel::Airport & node);
  AirTravel::Airport pop();
  AirTravel::Airport peek() const;
  bool empty() const;

  std::stack<AirTravel::Airport> S;
private:
  
  std::map<std::string, AirTravel::Airport*> list;
  AirTravel::Airport current;
};
