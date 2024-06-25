#pragma once
#include "Vertex.h"
#include <vector>
#include <queue>
#include <map>

class AStar {
  public:
      AStar(std::vector<Vertex*>& nodes);
      ~AStar();
      std::vector<Vertex*> shortest(Vertex* start, Vertex* destination);
  private:
    std::vector<Vertex*> _nodes;
};