#include "distances.h"
#include <iostream>
#include <algorithm>
#include <numeric>

Distances::Distances(const string &_currentCity):
	currentCity(_currentCity)
{
}

string Distances::getCurrentCity() const
{
    return currentCity;
}

void Distances::setDistance(const string &city, int distance)
{
    distances[city] = distance;
}

void Distances::printAll() const
{
    cout << currentCity << endl;
    for(auto kvp : distances)
    {
        cout << "\t" << kvp.first << " -> " << kvp.second << endl;
    }
    cout << endl;
}

int Distances::getDistance(const string &c) const
{
    auto it = distances.find(c);
    if(it == distances.cend())
    {
        throw "error";
    }
    return (*it).second;
}

double Distances::average() const
{
    double osszeg = accumulate(distances.cbegin(), distances.cend(), 0.0, [&](double tav, const pair<string, int>& kvp){
        return tav + kvp.second;    //parameterben azt a valtozot kapja amit osszeadunk, valamint ami benne van a taroloban
    });
    return osszeg/distances.size();

}

list<string> Distances::closerThan(int tavolsag) const
{
    list<string> kozelebb;
    list<pair<string, int>> tmp;

    copy_if(distances.begin(), distances.end(), back_inserter(tmp), [tavolsag](const pair<string, int>& kvp){
        return kvp.second < tavolsag;
    });
    transform(tmp.begin(), tmp.end(), back_inserter(kozelebb), [](const pair<string, int>& kvp){
        return kvp.first;
    });
    return kozelebb;
}
