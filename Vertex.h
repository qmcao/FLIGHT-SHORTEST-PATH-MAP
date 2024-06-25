#pragma once
#include <vector>
#include <string>

class Vertex {
    public:
        /**
         * @brief Construct a new Vertex object
         */
        Vertex();

        /**
         * @brief Construct a new Vertex object
         * @param airportID 
         * @param coords 
         */
        Vertex(int airportID, std::pair<double, double> coords, std::string name);
        Vertex(int airportID, std::pair<double, double> coords);


        Vertex(int airportID, std::string name);

        /**
         * @brief Get the ID object
         * @return int 
         */
        int getID();

        /**
         * @brief Set the ID object
         * @param airportID 
         */
        void setID(int airportID);

        /**
         * @brief Set the Adjacency object
         * @param adj 
         */
        void setAdjacency(std::vector<Vertex*>& adj);

        /**
         * @brief Get the Adjacency object
         * @return std::vector<int> 
         */
        std::vector<Vertex*> getAdjacency();

        /**
         * @brief Set the Coords object
         * @param coords 
         */
        void setCoords(std::pair<double, double> coords);

        /**
         * @brief Get the Coords object
         * @return std::pair<double, double> 
         */
        std::pair<double, double> getCoords();

        /**
         * @brief Get the Weight object
         * @return double 
         */
        double getWeight();

        std::string getName();

        /**
         * @brief overload operator =
         * @param other 
         * @return Vertex& 
         */

        bool operator!=(const Vertex& other) const;
        bool operator<(const Vertex& other) const;
        bool operator==(const Vertex& other) const;



    private:

        int _airportID; /*< ID of the vertex */
        std::vector<Vertex*> _adjacent; /*< vector of adjacent vertices of the vertex */

        std::pair<double, double> _coords; /*< coordinates of the vertex */

        std::string _name;

        double _weight; /*< weight of the vertex */

        /**
         * @brief Copy vertex
         * @param other 
         */
        void _copy(const Vertex& other);
};