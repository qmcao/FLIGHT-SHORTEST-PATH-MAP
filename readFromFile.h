#include <string>
#include <algorithm>
#include "Dijkstras.h"
#include <map>
#include <stack>
#include "Vertex.h"
#include <vector>

class FileReader {
    public:
        ~FileReader();

        /** 
         * Reads a file into a string
         * @param filename The file to read from 
         * @return a string containing filename's contents
         */
        std::string file_to_string(const std::string& filename);

        /** 
         * Reads a file into a vector
         * @param filename The file to read from
         * @return a vector containing filename's contents
         */
        std::vector<std::string> file_to_vector(const std::string& filename);


        /**
         * 
         * Return vector of Vertex* node that contains 
         * @param ID  ID of each airport
         * @param Pair of Latitude and Longitude of current airport
         */ 
        std::vector<Vertex*> getItemFromAirport(std::vector<std::string>& res);


        /**
         * set Adjacancy node from routes.txt file
         */ 
        void setAdjacencyFromRoute(std::vector<std::string>& route);



        void cleanUpNonAdjacency(std::vector<Vertex*>& v);

        Vertex* findAirport(int ID);
    private:
        /**
        * map each Node to it ID so can access the ID faster
        */
        std::map<int, Vertex*> mapVertex;



};



