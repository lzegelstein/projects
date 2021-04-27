#pragma once
	
#include <iterator>
#include <cmath>
#include <list>
#include <stack>

class DFS {
    public:
        DFS::DFS(std::vector<Vertex> v, Vertex n)
    private:
        std::vector<Vertex> _vertice;
}

//copied from mp traversals
using namespace cs225;

/**
 * A depth-first ImageTraversal.
 * Derived from base class ImageTraversal
 */
class DFS : public AirTravel {
public:
  DFS(const PNG & png, const Point & start, double tolerance);

  ImageTraversal::Iterator begin();
  ImageTraversal::Iterator end();

  void add(const Point & point);
  Point pop();
  Point peek() const;
  bool empty() const;

private:
	/** @todo [Part 1] */
	/** add private members here*/
  std::stack<Point> S;
  PNG image;
  Point current;
  double tolerance;
};
