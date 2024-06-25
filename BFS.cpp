
#include <queue>
#include <vector>
#include <map>

 
#include "BFS.h"

//constructor
BFS::BFS(std::vector<Vertex*>& nodes) {
  airport = nodes;
}


//Finding the distance from start to destination 
//weights of each edge is 
std::vector<Vertex*> BFS::shortestPath(Vertex* start, Vertex* destination) {
  std::queue<Vertex*> airportQueue;
  std::vector<bool> visited(14110);
  std::map<Vertex*, Vertex*> path;
  std::map<Vertex*, int> dist;
  //vector<std::pair<Vertex*, int>> dist; 

  //airports initially all marked as not visited.
  for (int i = 0; i < 14110; i++) {
    visited[i] = false;
  }

  //initialize first airport as visited.
  visited[start->getID()] = true;
  dist[start] = 0;
  //add in first airport to the airport queue
  airportQueue.push(start);

  while (airportQueue.empty() == false) {
    Vertex * currentAirport = airportQueue.front();
    std::vector<Vertex*> currentAdjacency = currentAirport->getAdjacency();
    for (auto it = currentAdjacency.begin(); it != currentAdjacency.end(); it++) {
      Vertex * tmp = *it;
      if (!visited[tmp->getID()]) {
        visited[tmp->getID()] = true;
        dist[tmp] = dist[currentAirport] + 1;
        path.insert({tmp, currentAirport});
        airportQueue.push(tmp);
      }
    }
    airportQueue.pop();
    if (currentAirport == destination) {
      break;
    }
  }
  Vertex * current = destination;
  std::vector<Vertex*> solution;
  while (current != start) {//!= not implemented yet
    solution.push_back(current);
    current = path[current];
  }
  
  std::reverse(solution.begin(), solution.end());
  return solution;
}



std::vector<Vertex*> BFS::fullTraversal(Vertex * start) {
  std::queue<Vertex*> airportQueue;
  std::queue<Vertex*> solutionQueue;
  std::vector<bool> visited(14110);
  std::map<Vertex*, Vertex*> path;
  std::map<Vertex*, int> dist;
  //vector<std::pair<Vertex*, int>> dist; 

  //airports initially all marked as not visited.
  for (auto i = 0; i < 14110; i++) {
    visited[i] = false;
  }
  //initialize first airport as visited.
  visited[start->getID()] = true;
  dist[start] = 0;
  //add in first airport to the airport queue
  airportQueue.push(start);

  while (airportQueue.empty() == false) {
    Vertex * currentAirport = airportQueue.front();
    std::vector<Vertex*> currentAdjacency = currentAirport->getAdjacency();
    for (auto it = currentAdjacency.begin(); it != currentAdjacency.end(); it++) {
      Vertex * tmp = *it;
      if (!visited[tmp->getID()]) {
        visited[tmp->getID()] = true;
        dist[tmp] = dist[currentAirport] + 1;
        path.insert({tmp, currentAirport});
        airportQueue.push(tmp);
        solutionQueue.push(tmp);
      }
    }
    airportQueue.pop();
  }
  std::vector<Vertex*> solution;
  while (!solutionQueue.empty()) {
    solution.push_back(solutionQueue.front());
    solutionQueue.pop();
  }
  return solution;
}

BFS::~BFS() {
    for (size_t i = 0; i < airport.size(); i++) {
        if (airport[i] != NULL) {
            delete airport[i];
            airport[i] = NULL;
        }
    }
    airport.clear();
}




    