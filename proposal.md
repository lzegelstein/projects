# Project Proposal 
### *Airport Travel Analysis*
####  By: Angela, Jared, Lyla, and Shree

## Leading Statement
We are going to create a visual representation of different airline flights to specific airports. From this data, we will be analyzing which airport hubs are the most popular, the shortest airtime from specific starting locations to destinations, and most effective trip travel with several destinations looping back to the original starting location. 

## Dataset Aquisition and Processing
Our nodes will be created using data from [airports.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/airports.dat). This file is organized in the order below (example data given):
Airport ID | Name | City | Country | IATA| ICAO | Latitude | Longitude | Altitude | Timezone | DST | Tz database time zone | Type | Source
---|---|---|---|---|---|---|---|---|---|---|---|---|---

507|"London Heathrow Airport"|"London"|"United Kingdom"|"LHR"|"EGLL"|51.4706|-0.461941|83|0|"E"|"Europe/London"|"airport"|"OurAirports"
We will analyze the data given in [routes.dat](https://raw.githubusercontent.com/jpatokal/openflights/master/data/routes.dat) to create our graph. The file is organized in the order below (example data given):
Airline | Airline ID | Source Airport| Source Airport ID| Destination Airport||Destination Airport ID|Codeshare| Stops|Equipment. 
---|---|---|---|---|---|---|---|---
 2B | 410 | AER | 2965 |KZN |2990| | 0 | CR2


## Traversals/Algorithms
##### BFS & DFS
Used to sift through data, doesn't have meaningful order. We may add a 'tolerance' to only look for artists with 

##### Kruscals Minimum Spanning Tree
**Categorize()**
We will perform k clustering using MST to group the genres for the user to see the artist recommendations. (k clustering problem can be viewed as finding an MST and deleting the k-1 most)

##### Iterative Deepening Depth First Search
**Remove()**
The user can remove an artist from the tree by specifying the artist’s name after the recommendations are generated. We will use much less memory to perform this delete since we will still be visiting nodes in depth first, but the cumulative order in which nodes are first visited will effectively be breadth search.

#### Find Nearest Neighbors
**GenerateList()** 
Looks through connected nodes and finds the ones wiht the distance. Tie breakers will be decided within this function.

## Timeline
Week of: | What we hope to accomplish: | What We Can Demonstrate: | Assignments: 
------------|---------------------------------------|--------------------------------------|------------------
4/12 |Propose a valid project.| Get approval from project mentor
| Note Taker: Angela  
4/19 | Pull data off of websites and have a constructor skeleton to start organizing data.| We will be able to print a portion of the data we retrieved from a website. | Note Taker: Shree  
4/26 |We would like to have a method to weigh the nodes between artists. With these weighted nodes, we will be able to start our recomendation functions. |We can write a print method to print out the weighted nodes.|Note Taker: Jared 
5/3| Finish everything from the previous week. Finish debugging and have working test cases
|Entire project works, including all individual functions, user accessibility, and test cases to simulate use |Note Taker: Lyla
5/10|Finish report and video | Have all the components of the final project done. The code, test cases, report, and video |Note Taker: Angela
