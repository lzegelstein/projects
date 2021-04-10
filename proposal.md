# Project Proposal 
### *Customized Predictive Clothing Algorithm*
####  By: Angela, Jared, Lyla, and Shree

## Leading Statement
UIUC’s student body is made up of a bunch of out-of-state and international students that aren’t used to the unique weather conditions Champaign has to offer. For example, the weather app sometimes reads 70 degrees, but it actually feels cold from the wind, or burning hot from the sun. The current weather app proposes a generic “feels like” temperature to try and give people a better idea of what the weather really is. Yet, this “feels like” temperature isn’t applicable to out-of-state students and internationals, and they are often left not knowing what to wear. 

We propose building a more customized predictive weather algorithm that allows users to have an adjusted “feels like” temperature based off a few questions and will show them based on their wardrobe, what they should consider wearing. 

## Dataset Aquisition and Processing
We look at the weather data for one particular past date (and pretend that it is the current date.) We get the dataset from https://www.isws.illinois.edu/statecli/urbana/urbana-monthly-2020.htm, recording the specific features of temperature, precipitation, and wind speed. 

We will also initialize a basic “catch-all” wardrobe tree in which the user can choose to modify to their own tastes through initial questions when starting the program. These questions are as follows below:
* Do you tend to get cold easily?
* Does your hometown have a warm or cold climate?
* Will you be doing a lot of physical acticity? (influences shoe choices)

Due to the variety in possible trees, we will acquire specific clothing to construct a default tree for each of these possibilities. The clothes that will populate these trees are as follows
* Winter hat, baseball hat, no hat
* Sunglasses, no sunglasses
* Shorts, jeans, pants
* Short-sleeves, long-sleeves, tanktop, sweatshirt, sweater
* Tennis shoes, boots, flip-flops

## Traversals/Algorithms
##### BFS
**OverWorn()**
If something has been worn too many times, suggest removing it from the search

##### DFS
**Add()**
The user can add a new clothing item to the wardrobe tree by specifying features, which will be categorized by the binary search tree going through each node

##### Kruscals Minimum Spanning Tree
**Categorize()**
We will perform k clustering using MST to group the clothes into categories for the user to see what clothes are similar. (k clustering problem can be viewed as finding an MST and deleting the k-1 most)

##### Iterative Deepening Depth First Search
**Remove()**
The user can remove a clothing item from the wardrobe tree by specifying the item’s name. We will use much less memory to perform this delete since we will still be visiting nodes in depth first, but the cumulative order in which nodes are first visited will effectively be breadth search.

#### Find Nearest Neighbors
**OtherOptions()**
Would get called when we generate the outfit, so we don’t generate anything ugly. We use find nearest neighbors to find which clothing items with colors that go well with the other items are closest to each other. 
**ColorMatching()**
If the user does not want to wear the specific clothing, we call find nearest neighbors to find articles of clothing that are similar to the parameters but different than the most effective clothing style. 

## Timeline
Week of: | What we hope to accomplish: | What We Can Demonstrate: | Assignments: 
------------|---------------------------------------|--------------------------------------|------------------
4/12 | Draft a general outline of the wardrobe tree as a Binary Search Tree. Acquire all required data and sort them in the tree. Start writing OverWorn() and Add() functions.| Be able to print the wardrobe tree to the console window, to be able to see the different nodes. | Note Taker: Angela  
4/19 | Finish writing OverWorn() and Add() functions. Start and finish findNearestNeighbors() and implement OtherOptions() and ColorMapping().| OverWorn() returns clothing that is most suggested by our algorithm for the user. Add() function successfully adds a new clothing item to our wardrobe tree.| Note Taker: Shree  
4/26 |Start and finish Kruscals Minimum Spanning Tree for Categorize() and Iterative Deepening Depth First Search for Remove()|Categorize() successfully groups the clothing items into clusters. Delete() successfully removes a clothing item with less runtime.|Note Taker: Jared 
5/3| Debug through test cases and finish any prior functions that weren’t working.|Wardrobe tree successfully updates for each of the functions when called in successive order. Users are able to input commands and communicate with the backend.|Note Taker: Lyla
5/10| Finish debugging and have working test cases|Entire project works, including all individual functions, user accessibility, and test cases to simulate use|Note Taker: Angela
