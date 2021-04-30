#include <cmath>
#include <iterator>
#include <iostream>
#include <vector>

#include "AirportTraversal.h"

/**
 * Default iterator constructor.
 */
AirportTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal=NULL;
}

AirportTraversal::Iterator::Iterator(AirportTraversal* traversal, std::map<std::string, AirTravel::Airport*> list,
                                   AirTravel::Airport& start)
    : list(list), traversal(traversal), start(start){
  /*initialize the current iterator to top Node of the stack*/
  current = start;
  //initialize vector to have all Airport 3 code and all false
  for(auto it: list){
      visited.insert({it.first, false});
  }

}

//This is to check if it's visited or not
//Possible error; we don't know if this should be taking in Airport or Airport*, so it might 
//error out the way we are passing nodes in
bool AirportTraversal::Iterator::isValid(AirTravel::Airport node){
    //valid if it is not visited
    return !(visited.at(node.IATA));
}

/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the graph.
 */
AirportTraversal::Iterator & AirportTraversal::Iterator::operator++() {
  if(traversal->empty()){
    return *this;
  } 
  traversal->pop();
  visited.at(current.IATA) = true; //we have visisted this point

  //we should look at every Airport destination
  int count = current.destinations.size();

  //std::cout<<"count: "<<count<<std::endl;

  //while stack is not empty and we have already visited the point, pop and move to the next point
  while(!traversal->empty() && !isValid(traversal->peek())){
    current = traversal->pop();
  }


  for(int i = 0; i < count; i++){
      AirTravel::Airport curr = *(current.destinations[i].other_airport);
      //std::cout<<"curr: "<<curr.IATA<<std::endl;
      if(isValid(curr)){
          traversal->add(curr);
      }
  }

  if(!traversal->empty()){
    current = traversal->peek();
  }

  //std::cout<<"current: "<<current.IATA<<std::endl;

  return *this;

}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the AirportTraversal.
 */
AirTravel::Airport AirportTraversal::Iterator::operator*() {

  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool AirportTraversal::Iterator::operator!=(const AirportTraversal::Iterator &other) {
 //Hey, probably don't change this rn, this was copy/pasted from another iterator checker in another mp
 //pretty sure it works   
  bool thisEmpty = false; 
  bool otherEmpty = false;

  if (traversal == NULL) { thisEmpty = true; }
  if (other.traversal == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = traversal->empty(); }
  if (!otherEmpty) { otherEmpty = other.traversal->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return false
  else if ((!thisEmpty)&&(!otherEmpty)) return (traversal != other.traversal); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
}
