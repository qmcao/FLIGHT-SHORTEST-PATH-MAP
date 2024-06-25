#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>
#include <numeric>
#include "readFromFile.h"
std::string FileReader::file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> FileReader::file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;
	std::string word;
	if (text.is_open()) {
		 while(getline(text, word)) {
            out.push_back(word);
        }
		
	}

	return out;
}




/**
* Each index of array v store a Vertex, which is our node in the graph
*/ 

std::vector<Vertex*> FileReader::getItemFromAirport(std::vector<std::string>& res) {

	std::vector<Vertex*> v;
	/**
     *  TODO LOADING AIRPORTS.TXT INTO ARRAY
     */ 
    
    /**
     * First array that hold entire airport txt data. Each index is a line in the file
     */ 
    std::stack<char> charStore;

    /**
     * Array that hold 1 line each time from res
     * each index hold a string separate by ","
     */
	std::vector<std::string> store; 
    for (auto& it : res) {
        std::string word = "";
        for (size_t i = 0; i < it.length(); i++) 
        {   
            if (it[i] == '"' && charStore.empty()) {
                charStore.push('"');
                continue;
            } 
            else if (it[i] == '"' && !(charStore.empty())) {
                charStore.pop();
                continue;
            } 
            if (it[i] == ',' && charStore.empty())
            {   
                store.push_back(word);
                word = "";
                
                
            }    
            else {
                word = word + it[i];
            }
        }
        store.push_back(word);
        bool shouldUse= true;
        if (store[6] == "\\N" || store[7] == "\\N" || store[0] == "\\N" || store[1] == "\\N") {
            shouldUse = false;
        }
         
        if (shouldUse) {
            std::pair<double, double> a (std::stod(store[6]),std::stod(store[7]));
            int id = std::stoi(store[0]);
            std::string name = store[1];
            Vertex * vertex = new Vertex(id, a, name);
            mapVertex.insert({id, vertex});
            v.push_back(vertex);
            
            

        }
        store.clear();
    }
    return v;
}


void FileReader::setAdjacencyFromRoute(std::vector<std::string>& route) {
    /**
     * An array that store the adjacent airports of the current airport
     */
    std::vector<Vertex*> currentAdj;


    /**
     * An array that each index hold a string separate by ","
     */ 
    std::vector<std::string> store1;


    int currentId = 2965; //First ID in dataset
    for (auto& it : route) {
        std::string word = "";
        for (char x : it) 
        {   

            if (x == ',')
            {   
                store1.push_back(word);
                word = "";
                
                
            }
            
            else if (x == '"') continue;
            else {
                word = word + x;
            }
        }
        store1.push_back(word);
        bool shouldUse= true;
        if (store1[3] == "\\N" || store1[5] == "\\N") {
             shouldUse = false;
        }

        if (shouldUse) {

            if(currentId != std::stoi(store1[3])) {
                if (!(currentAdj.empty())) {

                    if (mapVertex.count(currentId) > 0 ) {
                        auto current = mapVertex[currentId];
                        current->setAdjacency(currentAdj);
                        currentAdj.clear();
                    }
                }           
                currentId = std::stoi(store1[3]);
            }
            int idOfAdjacentVertex = std::stoi(store1[5]);
            if (mapVertex.count(idOfAdjacentVertex) >0) {
                currentAdj.push_back(mapVertex[idOfAdjacentVertex]);
            }
        }
        store1.clear();
    }
    // Cleans up airports with zero connections
    //cleanUpNonAdjacency();
    
    
}

Vertex* FileReader::findAirport(int ID) {
    auto find = mapVertex.find(ID);
    if (find == mapVertex.end()) {
        return NULL;
    }
    return (find -> second);
}

 /**
     * How to delete an item from a vector by a while loop[]
     * https://www.techiedelight.com/remove-elements-vector-inside-loop-cpp/
 */

void FileReader::cleanUpNonAdjacency(std::vector<Vertex*>& v) {
	auto it = v.begin();
    while (it != v.end()) {
        if ((*it)-> getAdjacency().empty()) {
            it = v.erase(it);
        } else {
            ++it;
        }
    }
}

FileReader::~FileReader() {
	auto it = mapVertex.begin();
    while (it != mapVertex.end()) {
        if ((*it).second != NULL) {
            delete (*it).second;
			it = mapVertex.erase(it);
        } else {
            ++it;
        }
    }
    mapVertex.clear();
}

