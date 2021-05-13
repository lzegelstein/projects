### Reading Data:
Firstly, the Airport structs are populated by reading in two datasets. One that includes airports and another consisting of routes. We took into consideration 9 different cases when doing begining testing in Xcode to account for imperfect lines. These cases included airports missing an IATA code, commas, latitudes and longitudes that were out of range, etc. Towards the end of the project, we realized we still forgot to take into account the case where there's a comma embedded in quotes, like as in "Savalbard Airport, Longyear". Luckily, we found and fixed it. Some tests in VSCode can be seen by doing: make clean; make test; ./test [AirTravel]. The specifics for the test cases can be found in ../tests/testAirTravel.cpp. 

### Traverse Files:
As planned in our GOALS, we used DFS to traverse through our data. Our DFS and AirportTraversal files are based on the DFS and imageTraversal files in mp_traversals. We adapted the files to traverse through the data that we have created through the files listed under reading and writing data. The DFS works as it should and we tested it using our smaller data sets (airports-short.csv and routes-short.csv). We tested whether it started at the right point, whether it visited all of the nodes, if it visited all those nodes in the correct order, if it maintains a depth-first ordering, and if it maintains deepest point on top. The specifics for the test cases can be found in ../tests/testDFS.cpp. This can be tested by doing: make clean; make test; ./test [DFS].

### Dijkstra’s Algorithm:
As planned in our GOALS, we used Dijkstra’s algorithm and used what was taught in lecture as a foundation for the code. Our dijkstras files contain all the code for the algorithm and works properly as it can find the smallest path between all nodes. It was a struggle to determine the proper way to approach this problem. After many redos, we settled on a Path struct to represent edges and a AirportNode struct to represent vertices. One finding was that you can't overwrite a value in a map with a pair. This was handled by doing a delete at a specified area followed by an insert when a new shortest path was found. After researching the std::priority_queue, we realized that we could actualy specify superiority. This was a huge breakthrough and the key to Dijkstra's success. Debugging this algorithm involved stepping through line by line and realizing that our logic was wrong, several times. We have an additional function to find the smallest path between two nodes. The algorithm can be tested by doing: make clean; make test; ./test [Dijkstras]. The test cases use our smaller data sets to check empty paths between nodes and the smallest path between nodes. The specifics for the test cases can be found in ../tests/testDijkstras.cpp.

### Graph:
We originally wanted to do a force directed graph, but it was changed due to us starting a week late on the project. As we did more research, we realized that plotting the x and y coordinates of the nodes is a more useful way to represent our data. The color and size of the nodes depends on the number of outgoing unique airports. The coloring of the nodes takes the size of this airport/size of the busiest airport then multiplies that number by 235 which is the hue, and then subtracts it from 235. This means the larger airports will be red and the less busy airports will be light blue. Our graph output is able to display all the airport nodes as circles in an x-y coordinate system and display lines between airports to represent flights. This graph can be produced by doing: make clean; make; ./AirTravel. 

### Discoveries:
Through the combination of all our code we are able to answer all of the questions in our GOALS. We were able to find that the busiest airport is Frankfurt am Main Airport. Our output successfully showed that there was a direct flight from RUT to JFK, and that there was a route under three stops from JFK to RUT. We also output a round trip from ORD to LYD, and those specific stops are printed in the terminal.


A copy and paste of our terminal:

Busiest Airport: Frankfurt am Main Airport

Is there a direct flight from RUT to JFK ? No

Round Trip from ORD to LYR consists of stops to: 
Chicago O'Hare International Airport
Dublin Airport
Oslo Lufthavn
Svalbard Airport, Longyear
Oslo Lufthavn
Dublin Airport
Chicago O'Hare International Airport

Can we get from JFK to RUT in under 3 flights? Yes

