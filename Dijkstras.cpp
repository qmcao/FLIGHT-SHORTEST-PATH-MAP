#include "Dijkstras.h"
#include <map>
#include <vector>
#include <queue>
#include "Vertex.h"
#include <iostream>
DGraph::DGraph() {

}
DGraph::DGraph(std::vector<Vertex*>& nodes) {
     _nodes = nodes;
}


// Return shortest path in sequence between two nodes
std::vector<Vertex*> DGraph::findShortest(Vertex* start, Vertex* destination) {
    std::priority_queue<Vertex*> airportQueue;
    std::vector<bool> visited(14110);
    std::map<Vertex*, Vertex*> path;
   // std::map<Vertex*, int> dist;

    //airports initially all marked as not visited.
    for (auto i = 0; i < 14110; i++) {
        visited[i] = false;
    }

    //initialize first airport as visited.
    visited[start -> getID()] = true;

    //add in first airport to the airport queue
    airportQueue.push(start);
    
    while (!(airportQueue.empty())) {
        Vertex * currentAirport = airportQueue.top();
        airportQueue.pop();
        std::vector<Vertex*> currentAdjacency = currentAirport -> getAdjacency();
        for (auto it = currentAdjacency.begin(); it != currentAdjacency.end(); it++) {
            Vertex * tmp = *it;  
            if (!visited[tmp -> getID()]) {
                path.insert({tmp, currentAirport});
                airportQueue.push(tmp);
                visited[tmp -> getID()] = true;
            }
        }
        if (currentAirport == destination) {
            break;
        }

    }
    Vertex * current = destination;
    std::vector<Vertex*> solution;
    while (current != start) {
        solution.push_back(current);
        current = path[current];
    }
    
    std::reverse(solution.begin(), solution.end());
    return solution;

}


DGraph::~DGraph() {
    for (size_t i = 0; i < _nodes.size(); i++) {
        if (_nodes[i] != NULL) {
             delete _nodes[i];
             _nodes[i] = NULL;
        }
    }
    _nodes.clear();
}