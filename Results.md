

**Project Overview:**
Using the open-source OpenFlights dataset, I developed a project that allows the use of three different algorithms to find the shortest path between two airports.

**Algorithms Used:**

1. **Breadth-First Search (BFS):**
   - **Traversal:** The BFS traversal enables traversing the graph from node to node, with each node keeping track of its neighbors.
   - **Shortest Path:** The BFS algorithm can also be used to find the shortest path between two airports when weights are unneeded or irrelevant.

2. **Dijkstra's Algorithm:**
   - **Weighted Shortest Path:** Dijkstra's algorithm finds the shortest path between two airports by considering the connections (nodes) as weighted. 
   - **Weighting Method:** Airports with fewer connections are less desirable, making them less convenient for travelers. The weight method used was \( \frac{1}{n} \), where \( n \) is the number of adjacent airports.

3. **A* Algorithm:**
   - **Heuristic Implementation:** The heuristic implemented for the A* algorithm considers the number of jumps or distance, with fewer jumps being more desirable. 
   - **Weight Calculation:** The heuristic was calculated by inverting the number of jumps and subtracting it from 1, then adding it to the weights previously calculated for Dijkstra's algorithm. This made weights easier to compare and ensured that an excessive number of connections did not significantly impact the path selection, as the number of jumps would not be excessively high.

