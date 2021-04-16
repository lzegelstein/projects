# Project Proposal 
### **
####  By: Angela, Jared, Lyla, and Shree

## Leading Statement
Hearing the same artist repeatedly can get old even if they are your favorite. So, it would be nice to listen to other singers of a similar genre. We plan to use data from Spotify or Billboard to create recommendations of other artists to explore based on genre similarity. Our algorithm will take into account one or more artists that a user likes and will output recommendations of other artists.

To add more complexity to our project we will add one or more of the following if we have enough time:
* Number of collaborations the artists have with each other
* Use Finding Nearest Neighbor to find a polar opposite genre and recommend that  as well
* Adjust the weight of the lines connecting the nodes to be more specific to create a more concise list of artist recommendations


## Dataset Aquisition and Processing
For our project we will be analyzing data taken from Spotify or Billboard and creating a graph with nodes representing artists that are connected by edges representing genre similarity. We would take the inverse of the number of genres they share and this will create a representation of genre ‘distance;’ the more genres shared, the closer two artists are. This graph can recommend similar artists based on a chosen starting artist or potentially a couple artist and finding a happy medium. 

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
