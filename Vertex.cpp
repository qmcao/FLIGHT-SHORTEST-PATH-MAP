#include "Vertex.h"

Vertex::Vertex() {
    _airportID = 0;
    std::pair<double, double> coords(0.0, 0.0);
    _coords = coords;
    _name = "";
}

Vertex::Vertex(int airportID, std::pair<double, double> coords) {
    _airportID = airportID;
    _coords = coords;
    _name = "";
}

Vertex::Vertex(int airportID, std::pair<double, double> coords, std::string name) {
    _airportID = airportID;
    _coords = coords;
    _name = name;
}

Vertex::Vertex(int airportID, std::string name) {
    _airportID = airportID;
    std::pair<double, double> p(0.0, 0.0);
    _coords = p;
    _name = name;
}

int Vertex::getID() {
    return _airportID;
}

void Vertex::setID(int airportID) {
    _airportID = airportID;
}
void Vertex::setCoords(std::pair<double, double> coords) {
    _coords = coords;
}

std::pair<double, double> Vertex::getCoords() {
    return _coords;
}

void Vertex::_copy(const Vertex& other) {
    this -> _airportID = other._airportID;
    this -> _coords = other._coords;
    this -> _adjacent = other._adjacent;
}

bool Vertex::operator!=(const Vertex& other) const{
    if (this -> _airportID == other._airportID) {
        return false;
    }
    return true;
}
bool Vertex::operator<( const Vertex& other) const {
    return (this->_weight < other._weight);
}
bool Vertex::operator==(const Vertex& other) const {
    return (this -> _airportID == other._airportID);
}

void Vertex::setAdjacency(std::vector<Vertex*>& adj) {
    if (adj.empty()) return;
    for (auto & it: adj) {
        _adjacent.push_back(it);
    }
    _weight = (double) (1.0 / _adjacent.size());
}
std::vector<Vertex*> Vertex::getAdjacency() {
    return _adjacent;
}

double Vertex::getWeight() {
    return _weight;
}

std::string Vertex::getName() {
    return _name;
}