
## Table of contents
* [General info](#general-info)
* [Technologies](#technologies)
* [Setup](#setup)
* [Linkage, Location of major code, data, results](#linkage-and-location)
* [Testing](#testing)

## General info
This project uses the OpenFlights dataset to find the shortest route between two cities, 
while considering the shortest number of connections

## Technologies
This project is created using C++.

## Setup
To run this project, download it, open a remote ssh terminal for the project, then run:
```
$ make
$ ./finalproj A 2 10
```

The executable can change depending on what algorithm you want to use. Substitute "A" above with either: A, B, D or BFull. A runs A* star algorithm. B runs BFS and D runs Dikstras. BFull does a full traversal. The first number is the ID of the start airport and the second is the ID of the finish airport. When running BFull, only the start airport is required, but it requries 0 to be input into the last argument to run.

The data set is in:
```
$ tests/airports.txt
```
If a different dataset is desired, change this file.

## Linkage and location
### Linkage
* All files are linked in main.cpp and are instantiated in main.

### Locations
* BFS.h and .cpp is the Breadth-First Search Implementation
* Djikstras.h and .cpp is the Djikstra's Algorithm Implementation
* readFromFile.hpp and .cpp reads data from the dataset and parses 
* Vertex.h and .cpp represents a vertex object of each airport and its data

## Testing
### Notable methods tested
#### BFS Methods
* shortestPath(Vertex* start, Vertex* destination)
* fullTraversal(Vertex* start)

#### Djikstra's Methods
* findShortest(Vertex* first, Vertex* second)

#### Read from File Methods
* getItemFromAirport(std::vector<std::string> res)
* setAdjacencyFromRoute(std::vector<std::string> route, std::vector<Vertex*> v)

#### Vertex Methods
* None
# FlightShortestMap
