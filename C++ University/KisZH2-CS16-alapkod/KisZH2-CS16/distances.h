#ifndef DISTANCES_H
#define DISTANCES_H

#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Distances
{
	string currentCity;
    map<string, int> distances;
public:
	Distances(const string &_currentCity);
	string getCurrentCity() const;

    void setDistance(const string &city, int distance);
    void printAll() const;
    int getDistance(const string &c) const; // nem lehet []-t hasznalni mert akkor uj kulcsot hozna letre es nem lehetne const a fgv
    double average() const;
    list<string> closerThan(int tavolsag) const;
};

#endif // DISTANCES_H
