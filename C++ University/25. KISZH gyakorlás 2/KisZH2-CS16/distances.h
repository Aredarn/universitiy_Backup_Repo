#ifndef DISTANCES_H
#define DISTANCES_H
#include <iostream>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Distances
{
	string currentCity;
    map<string,int> distanceList;
public:
	Distances(const string &_currentCity);
	string getCurrentCity() const;

    void setDistance(const string vnev, int tav)
    {
        distanceList[vnev]= tav;
    }

    void printAll() const
    {
        cout << "Currect city: " << currentCity << endl;
        for(auto it = distanceList.begin(); it != distanceList.end();it++)
        {
            cout << "\t" << it->first << " - " << it->second << endl;
        }

        //Másik megoldás 'range based loop'
        for(const auto &kvp : distanceList)
        {
            cout << "\t" << kvp.first << " - " << kvp.second << endl;
        }

    }

    int getDistance(const string& city) const
    {
        auto it = distanceList.find(city);
        if(it == distanceList.cend())
            throw "error";
        return(*it).second;
    }

};

#endif // DISTANCES_H
