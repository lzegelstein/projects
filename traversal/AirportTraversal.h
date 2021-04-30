/**
 * @file AirportTraversal.h
 */
#pragma once

#include <cmath>
#include <list>
#include <stack>
#include <vector>
#include <map>

#include <iterator>
#include "../AirTravel.h"


//using namespace AirTravel;
/**
 * A base class for traversal algorithms on images.
 *
 * BFS and DFS will inherit from this class
 * 
 * Each derived class must maintain an ordering of points on an image,
 * through calls to the virtual member functions `add` and `pop`.
 * 
 * A derived class provides a traversal by returning instances of
 * AirportTraversal::Iterator.
 */
class AirportTraversal {
public:
  /**
   * A forward iterator through an AirportTraversal.
   */
  class Iterator : std::iterator<std::forward_iterator_tag, AirTravel::Airport> {
  public:
    /**
     * Default iterator constructor
     */
    Iterator();

    /**
     * Iterator operations
     */
    Iterator & operator++();
    AirTravel::Airport operator*();
    bool operator!=(const Iterator &other);

    /**
     * Iterator constructor
     */
    Iterator(AirportTraversal* traversal, std::map<std::string, AirTravel::Airport*> list, AirTravel::Airport& start);

    /**
     * @returns true if node has not been visisted yet
     */
    bool isValid(AirTravel::Airport node);
    
  private:
    std::map<std::string, bool> visited;
    std::map<std::string, AirTravel::Airport*> list;
    AirTravel::Airport current;
    AirportTraversal* traversal;
    AirTravel::Airport start;
  };

  /**
   * The begining of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator begin() = 0;

  /**
   * The end of an iterator
   * Virtual function. Derived class need to implement this
   */
  virtual Iterator end() = 0;

  /**
   * Add new point to the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual void add(const AirTravel::Airport & t) = 0;
  /**
   * Remove and return the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual AirTravel::Airport pop() = 0;
  /**
   * Return but not remove the next point of the traversal
   * Virtual function. Derived class need to implement this
   */
  virtual AirTravel::Airport peek() const = 0;
  /**
   * To see if the traversal has no points left
   * Virtual function. Derived class need to implement this
   */
  virtual bool empty() const = 0;

private:
};
