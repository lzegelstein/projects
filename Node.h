#pragma once

#include <iostream>
#include <sstream>
#include "cs225/PNG.h"

/**
 * @file Graph.h
 * every 2D point of the image is represented by a Node class
 * you need to trverse all the nodes of the graph
 */

/**
 * Simple Node class containing a public unsigned `x` and `y` for representing 2D points on an image.
 */
struct Node {
  unsigned x;
  unsigned y;
  unsigned size; //this is the radius of the circle

  /**
   * Default constructor, set the point to (0, 0): 0
   */
  Node() : Node(0, 0, 0) { }
  /**
   * Constructor
   * @param x coordinate of a point
   * @param y coordinate of a point
   */
  Node(unsigned x, unsigned y, unsigned size) : x(x), y(y), size(size) { }

  /**
   * overload operator <
   * @param other The other point
   * @return True for smaller, false for otherwise
   */
  bool operator<(const Node &other) const {
    return (x < other.x || y < other.y);
  }

  /**
   * overload operator ==
   * @param other The other point
   * @return True for smaller, false for otherwise
   */
  bool operator==(const Node &other) const {
    return (x == other.x && y == other.y);
  }
};

struct Edge {
    Node start, end;
    double length;

    /**
     * Default constructor, set the point to (0, 0): 0
     */
    Edge() : Edge(Node(), Node(), 0) { }
    /**
     * Constructor
     * @param start node
     * @param end node
     * @param length distance 
     */
    Edge(Node start, Node end, double length) : start(start), end(end), length(length) { }
};

  /**
   * overload operator <<
   * print out a Node
   * @param out Output stream
   * @param point The Node to print
   * @return Output stream
   */
inline std::ostream & operator<<(std::ostream & out, Node const & point) {
  out << "(" << point.x << ", " << point.y << "):" << point.size;
  return out;
}

/**
 * Draws the node onto the image PNG
 * 
 * @param circle current node to draw
 * @param image PNG for the node to draw on
 */
void drawNode(Node circle, cs225::PNG &image);

/**
 * Draws the edge line onto the image PNG
 * 
 * @param line current edge (line between two nodes) to draw
 * @param image PNG for the node to draw on
 */
void drawEdge(Edge line, cs225::PNG &image);
