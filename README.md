# jafrank2-angelaj4-shree2-lrz2


Welcome to our Air Travel Program!
In main.cpp, you will see that there are two datasets to choose from. Right now, everything is based off of the full dataset. 
DFS doesn't print anything unless you uncomment a line, since it will print out all of the airports, we recommend doing that on the shorter data set. The line to uncomment is specified in main.cpp. Additionally, the graph takes about 50 seconds to produce, so sit tight, a beautiful map is coming! It takes longer with a larger dataset and image size. 

A quick overview of the files:
Airport.h - Struct of our graph nodes which are used everywhere
AirTravel.h - The general class for accessing everything in our dataset
dijkstras.cpp - getShortestRoute() and the dijkstra's algorithm happen here
graph.h - Contains drawing nodes, drawing edges, and scaling functions for the graphic
graphs folder - Holds old test cases for printing nodes and lines of the graph
traversals folder - Contains dfs and airport traversal. Airport traversal is an iterator which allows us to iterate through DFS
tests folder - In here, there are 4 different files used for testing the various components of our program

This command must be run once at the beginning assuming you're working on EWS: module load llvm/6.0.1;
To run the main type:  make clean; make; ./AirTravel
To run our test cases type: make clean; make test; ./test

Video Presentation:
https://youtu.be/x1dCkCp-uEw
<img width="1092" alt="airportsWithRoutes" src="https://user-images.githubusercontent.com/77509822/184348182-3a68e337-06d0-4eb7-a5d6-fa4af8d7888c.png">
