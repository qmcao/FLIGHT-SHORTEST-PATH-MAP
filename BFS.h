/**
* @file BFS.h
*/
 
#pragma once
 
#include <iterator>
#include <cmath>
#include "Vertex.h"
#include <list>

class BFS {
  public:
      BFS(std::vector<Vertex*>& nodes);
      ~BFS();
      std::vector<Vertex*> shortestPath(Vertex* start, Vertex* destination);
      std::vector<Vertex*> fullTraversal(Vertex* start);

  private:
   std::vector<Vertex*> airport;
};