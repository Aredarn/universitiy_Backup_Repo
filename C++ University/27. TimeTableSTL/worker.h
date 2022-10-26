#ifndef WORKER_H
#define WORKER_H
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Worker
{
    int id;
    string title;
    map<string, pair<int, int>> shifts;
public:
    Worker(int id, const string& title):id(id),title(title){}

    void addShift(const string& date, int start, int end)
    {
        auto result = shifts.insert({date, {start,end}});

        if(!result.second)
        {
            cout << "ERROR: shift for" << date <<" already saved (2x)" << endl;
        }
    }

    void printTable() const
    {
        for(auto& kvp : shifts)
        {
            cout << kvp.first << ": " << kvp.second.first <<" - " << kvp.second.second << endl;
        }
    }

    bool isFree(const string& date) const
    {
        return shifts.find(date) == shifts.cend();
    }


    int getID() const
    {
        return id;
    }

    string getTitle() const
    {
        return title;
    }

};

#endif // WORKER_H
