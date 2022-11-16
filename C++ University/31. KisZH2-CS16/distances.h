#ifndef DISTANCES_H
#define DISTANCES_H

#include <numeric>
#include <string>
#include <map>
#include <list>
#include <vector>
using namespace std;

class Distances
{
    map<string, int> distances;
	string currentCity;
public:
	Distances(const string &_currentCity);
	string getCurrentCity() const;

    // ...
    void setDistance(string a, int b)
    {
        distances[a] = b;
    };

    double average()
    {
        double x = accumulate(distances.begin(),distances.end(),0.0, [](double acc, const pair<string, int>& kvp){
            return acc + kvp.second;
        }) / distances.size();
        return x;
    };

   list<string> closerThan(int tav)
   {
       list<string> temp;

       find_if(distances.begin(),distances.end(),[&temp, tav]()
       {
           if(this->])
       }
       );

   }


};

#endif // DISTANCES_H
