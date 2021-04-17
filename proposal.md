# Project Proposal 
### *Airport Travel Analysis*
####  By: Angela, Jared, Lyla, and Shree

## Leading Statement
We are going to create a visual representation of different airline flights to specific airports. From this data, we will be analyzing which airport hubs are the most popular, the shortest airtime from specific starting locations to destinations, and most effective trip travel with several destinations looping back to the original starting location. 

## Dataset Aquisition and Processing
We will be using the website [OpenFlights.org](https://openflights.org/data.html) to get our data. They use some third party sources as well as their own data to compile .dat files organized in a csv format (seperated by commas and lines).

Our nodes will be created using data from [airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat). This file is organized in the order below (example data given):

Airport ID | Name | City | Country | IATA| ICAO | Latitude | Longitude | Altitude | Timezone | DST | Tz database time zone | Type | Source
---|---|---|---|---|---|---|---|---|---|---|---|---|---
507|"London Heathrow Airport"|"London"|"United Kingdom"|"LHR"|"EGLL"|51.4706|-0.461941|83|0|"E"|"Europe/London"|"airport"|"OurAirports"

Explaination from website:

**Airport ID** Unique OpenFlights identifier for this airport.
**Name** Name of airport. May or may not contain the City name.
**City** Main city served by airport. May be spelled differently from Name.
**Country** Country or territory where airport is located. See Countries to cross-reference to ISO 3166-1 codes.
**IATA** 3-letter IATA code. Null if not assigned/unknown.
**ICAO** 4-letter ICAO code. Null if not assigned.
**Latitude** Decimal degrees, usually to six significant digits. Negative is South, positive is North.
**Longitude** Decimal degrees, usually to six significant digits. Negative is West, positive is East.
**Altitude** In feet.
**Timezone** Hours offset from UTC. Fractional hours are expressed as decimals, eg. India is 5.5.
DST	Daylight savings time. One of E (Europe), A (US/Canada), S (South America), O (Australia), Z (New Zealand), N (None) or U (Unknown). See also: Help: Time
**Tz database time zone** Timezone in "tz" (Olson) format, eg. "America/Los_Angeles".
**Type** Type of the airport. Value "airport" for air terminals, "station" for train stations, "port" for ferry terminals and "unknown" if not known. In airports.csv, only type=airport is included.

We will be using the 3-letter IATA codes to reference the airports as it is the most compatable with our other data set below. Within our nodes we will also be including the latitude and longitude coordinates so that we can calculated direct distance between airports.

We will analyze the data given in [routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) to create our graph. The file is organized in the order below (example data given):

Airline | Airline ID | Source Airport | Source Airport ID | Destination Airport | Destination Airport ID | Codeshare | Stops| Equipment. 
---|---|---|---|---|---|---|---|---
 2B | 410 | AER | 2965 | KZN | 2990 | | 0 | CR2

 Explaination from website:

**Airline** 2-letter or 3- letter Unique OpenFlights identifier for this airport
**Airline ID** Unique OpenFlights identifier for airline (see Airline).
**Source airport** 3-letter (IATA) or 4-letter (ICAO) code of the source airport.
**Source airport ID** Unique OpenFlights identifier for source airport (see Airport)
**Destination airport** 3-letter (IATA) or 4-letter (ICAO) code of the destination airport.
**Destination airport ID** Unique OpenFlights identifier for destination airport (see Airport)
**Codeshare** "Y" if this flight is a codeshare (that is, not operated by Airline, but another carrier), empty otherwise.
**Stops** Number of stops on this flight ("0" for direct)
**Equipment** 3-letter codes for plane type(s) generally used on this flight, separated by spaces

When two airports are connected by a flight, an edge will be created between the two airport nodes. The edge will be weighted based on calculation disatance using a simple distance formula. If a data entry is incomplete (i.e. the Source or Destination airport is missing) the entry will be ignored. 

If time permits, we would like to be able to analyze the cycles in the graph to show how you could go gallivanting and end back where you started. Almost like a simplified traveling salesmen problem.

## Traversals/Algorithms
#### DFS
We will perform a conditional DFS because we don’t want to end up in an infinite loop. Cycles will be present in this graph. The DFS can be used to answer question 4. The complexity of DFS is O(n).

#### Dijkstra's Algorithm
**Categorize()**
We will perform k clustering using MST to group the genres for the user to see the artist recommendations. (k clustering problem can be viewed as finding an MST and deleting the k-1 most)

#### Iterative Deepening Depth First Search
We will use Dijkstra's algorithm to find the shortest path and answer question 3. The complexity of this algorithm is  O(ElogV) where: V is the number of vertices. E is the total number of edges.

#### Visual Output of Graph
We will use a force-directed graph drawing in order to visually display the airport hubs and flight connections. The force will come from the distance that is set to the weight of the edges. The complexity of this algorithm is O(n). [Wikipedia](https://en.wikipedia.org/wiki/Force-directed_graph_drawing)

## Questions We Can Answer Based Off of Our Graph
1. What is the busiest airport?
2. Is there a non-stop flight between destination 'a' and 'b'?
3. What is the shortest path between multiple stops, looping to the original starting point ('a' to 'b' to 'c' to 'a')?
4. Can we get from point 'a' to point 'b' in under 3 stops? 

## Timeline
Week of: | What we hope to accomplish: | What We Can Demonstrate: | Assignments: 
------------|---------------------------------------|--------------------------------------|------------------
4/12 |Propose a valid project.| Get approval from project mentor
| Note Taker: Angela  
4/19 | Have an algorithm implemented. Import data from the website so that the algorithm creates nodes and edges based on the data. Be able to output the graph that it has created. | We will be able to show that our program has received the data correctly and has populated the edges and nodes. We also will be able to output our graph as a visual force directed graph. | Note Taker: Shree  
4/26 |Implement and test BFS and Dijkstra’s Algorithm on our current dataset using test cases. |We should be able to receive the shortest distance path from any two or more airport nodes by naming starting airport “a” and stops/destination airports through the 3-digit codes.|Note Taker: Jared 
5/3| Finish debugging and have working test cases for the second half of the week.
|Entire project works, including all individual functions and test cases to simulate use. New functionality will include calculating the busiest airport.|Note Taker: Lyla
5/10|Finish report and video | Have all the components of the final project done. The code, test cases, report, and video | Note Taker: Angela
