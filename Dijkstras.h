#pragma once
#include <vector>
#include "Vertex.h"
#include <queue>


class DGraph {

    public:
        /**
         * @brief Construct a new DGraph object
         */
        DGraph();

        /**
         * @brief Construct a new DGraph object
         * @param nodes constructs with a list of nodes
         */
        DGraph(std::vector<Vertex*>& nodes);

        ~DGraph();


        /**
         * @brief Finds the shortest distance between two vertices
         * @param first vertex to compare
         * @param second vertex to compare
         * @return std::vector<Vertex*> returns the shortest distance
         */
        std::vector<Vertex*> findShortest(Vertex * first, Vertex * second);


    private:
        std::vector<Vertex*> _nodes; /*< Vector of vertices */
};