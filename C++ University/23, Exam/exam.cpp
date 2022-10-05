#include "exam.h"
#include <iostream>
using namespace std;
Exam::Exam(const string &_name, const string &_place):
    name(_name),
    place(_place)
{
}

const string &Exam::getName() const
{
	return name;
}

const string &Exam::getPlace() const
{
	return place;
}

void Exam::addGrade(int _grade)
{
    grades.push_back(_grade);
}

float Exam::avg() const
{
    float sum=0;
    for (unsigned int i=0; i<grades.size(); i++)
    {
        sum+=grades[i];
    }
    return sum/grades.size();
}

float Exam::median() const
{
    list<int> tmp(grades.begin(), grades.end());
    tmp.sort();
    vector<int> sorted(tmp.begin(), tmp.end());
    unsigned int size=sorted.size();
    if (size%2==1)
    {
        return sorted[size/2];
    }
    else
    {
        return (sorted[size/2-1] + sorted[size/2])/2.0;
    }
}

int Exam::modus() const
{
    map <int, int> freq;

    for(int grade: grades)
    {
        freq[grade]++;

    }

    int max_key  = 1;
    int max_value = -1;

    for(pair<int, int> kvp: freq)
    {
        //cout << kvp.first << " ->" << kvp.second << endl;
        if(kvp.second > max_value)
        {
            max_value = kvp.second;
            max_key = kvp.first;
        }
    }
    return max_key;
}

float Exam::deviation() const
{
	float average=avg();
	float sum=0;
	for (unsigned int i=0; i<grades.size(); i++)
	{
		sum+=(grades[i]-average)*(grades[i]-average);
	}
	sum/=(grades.size()-1);
	return sqrt(sum);
}
