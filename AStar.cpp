#include "AStar.h"


AStar::AStar(std::vector<Vertex*>& nodes) {
    _nodes = nodes;
}


std::vector<Vertex*> AStar::shortest(Vertex* start, Vertex* destination) {
    std::priority_queue<std::pair<double, Vertex*>> airportQueue;
    std::vector<bool> visited(14110);
    std::map<Vertex*, Vertex*> path;
    std::map<Vertex*, int> dist;
    //vector<std::pair<Vertex*, int>> dist;

    //airports initially all marked as not visited.
    for (auto i = 0; i < 14110; i++) {
        visited[i] = false;
    }

    //initializes distances associated with each airport to -1
    // for (size_t i = 0; i < _nodes.size(); i++) {
    //     dist.insert({_nodes[i], -1});
    // }

    //initialize first airport as visited.
    visited[start->getID()] = true;
    dist[start] = 0;
    //add in first airport to the airport queue
    std::pair<double, Vertex*> p(dist[start] + start -> getWeight(), start);
    airportQueue.push(p);

    while (!airportQueue.empty()) {
        Vertex * currentAirport = airportQueue.top().second;
        airportQueue.pop();
        std::vector<Vertex*> currentAdjacency = currentAirport->getAdjacency();
        for (auto it = currentAdjacency.begin(); it != currentAdjacency.end(); it++) {
            Vertex * tmp = *it;
            if (!visited[tmp->getID()]) {
                visited[tmp->getID()] = true;
                dist[tmp] = dist[currentAirport] + 1;
                path.insert({tmp, currentAirport});
                std::pair<double, Vertex*> p1(dist[tmp] + tmp -> getWeight() , tmp);
                airportQueue.push(p1);
            }
        }
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

AStar::~AStar() {
    for (size_t i = 0; i < _nodes.size(); i++) {
        if (_nodes[i] != NULL) {
            delete _nodes[i];
            _nodes[i] = NULL;
        }
    }
    _nodes.clear();
}