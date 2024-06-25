#include <iostream>
#include <vector>
#include "readFromFile.h"
#include "Dijkstras.h"
#include <map>
#include <stack>
#include "AStar.h"
#include "BFS.h"
#include "Vertex.h"
int main(int argc, char **argv) {
    FileReader * test = new FileReader();
    std::vector<std::string> testAirplane = test->file_to_vector("tests/airports.txt");
    std::vector<std::string> testRoute = test->file_to_vector("tests/routes.txt");
    std::vector<Vertex*> returnVertex = test->getItemFromAirport(testAirplane);
    test->setAdjacencyFromRoute(testRoute);
    test->cleanUpNonAdjacency(returnVertex);
    if (argc != 4) {
        std::cout << "Not enough arguments" << std::endl;
        return 0;
    }
    std::string arg1(argv[1]);
    if (arg1 == "D") {
        DGraph * graph1 = new DGraph(returnVertex);
        Vertex* a = test -> findAirport(std::stoi(argv[2]));
        Vertex* b = test -> findAirport(std::stoi(argv[3]));
        if (a == NULL || b == NULL) {
            std::cout << "Invalid ID" << std::endl;
        } else {
            std::vector<Vertex*> returner = graph1 -> findShortest(a, b);
            for (size_t i = 0; i < returner.size(); i++) {
                std::cout << "Stop " << i + 1 << ": " <<
                    returner[i] -> getName()<< " ID: "<< returner[i] -> getID()<< std::endl;
            }
        }
        delete graph1;
    } else if (arg1 == "A") {
        AStar * graph2 = new AStar(returnVertex);
        Vertex* a = test -> findAirport(std::stoi(argv[2]));
        Vertex* b = test -> findAirport(std::stoi(argv[3]));
        if (a == NULL || b == NULL) {
            std::cout << "Invalid ID" << std::endl;
        } else {
            std::vector<Vertex*> returner = graph2 -> shortest(a, b);
            for (size_t i = 0; i < returner.size(); i++) {
                std::cout << "Stop " << i + 1 << ": " <<
                    returner[i] -> getName()<< " ID: "<< returner[i] -> getID()<< std::endl;
            }
        }
        delete graph2;
    } else if (arg1 == "B") {
        BFS * graph3 = new BFS(returnVertex);
        Vertex* a = test -> findAirport(std::stoi(argv[2]));
        Vertex* b = test -> findAirport(std::stoi(argv[3]));
        if (a == NULL || b == NULL) {
            std::cout << "Invalid ID" << std::endl;
        } else {
            std::vector<Vertex*> returner = graph3 -> shortestPath(a, b);
            for (size_t i = 0; i < returner.size(); i++) {
                std::cout << "Stop " << i + 1 << ": " <<
                    returner[i] -> getName()<< " ID: "<< returner[i] -> getID()<< std::endl;
            }
        }
        delete graph3;
    } else if (arg1 == "BFull") {
        BFS * graph4 = new BFS(returnVertex);
        Vertex* a = test -> findAirport(std::stoi(argv[2]));
        if (a == NULL) {
            std::cout << "Invalid ID" << std::endl;
        } else {
            std::vector<Vertex*> returner = graph4 -> fullTraversal(a);
            for (size_t i = 0; i < returner.size(); i++) {
                std::cout << "Airport " << i + 1 << ": " <<
                    returner[i] -> getName()<< " ID: "<< returner[i] -> getID()<< std::endl;
            }
        }
        delete graph4;
    } else {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << argv[1] << std::endl;
    }
    //delete test;
    //2438 - 2974

    return 0;
}
