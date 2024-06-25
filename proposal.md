

**Leading Question:** 
I propose to find the shortest route between two cities, also considering the shortest number of connections. I would like to provide an interactive illustration that displays this information using UI/UX.

**Dataset Acquisition and Processing:**
I plan to use the OpenFlights Dataset. The route-based algorithm consists of airline information, including departure and arrival airports, as well as the number of stops. Since this dataset is provided in a *.dat format, in plain text, I will use the `ifstream` method posted on Stack Overflow to read from the data file using `iostream`, and parse it into arrays. I will then plug the arrays into algorithm methods that I write and iterate through the containers. Given the large size of the dataset and the potential for errors, I will disregard any records that do not include all of the necessary fields.

**Graph Algorithms:**
For traversal, I will use a BFS traversal with an iterator. The `++` operator will traverse to the next node of the graph until there are no nodes left to traverse. For the algorithms, I will use Dijkstra’s Algorithm to show individual connections of interest to the user. For the second algorithm, I will project the paths onto a map, aligning with the latitude and longitude of each airport. The shortest path will be displayed on this map.

**Timeline:**
- **April 9:** Submit project proposal and team contract
- **April 12:** Set up initial repository and Makefile
- **April 15:** Finish reading in data into array format and write simple tests to verify correctness
- **April 19:** Convert array format into graph format and pass simple tests
- **April 22:** Write DFS iterator and verify with tests
- **April 29:** Write Dijkstra's and verify with tests
- **May 5:** Write graph projection onto a map and verify with tests
- **May 7:** Finish report
- **May 9:** Sync to record final presentation
- **May 11:** Finish editing presentation and submit