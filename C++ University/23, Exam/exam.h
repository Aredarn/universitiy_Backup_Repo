#ifndef EXAM_H
#define EXAM_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include <cmath>

using namespace std;

class Exam
{
    string name, place;
    vector<int> grades;
public:
    Exam(const string &_name, const string &_place);

	const string &getName() const;
	const string &getPlace() const;

    void addGrade(int _grade);
    float avg() const;
    float median() const;
    int modus() const;
    float deviation() const;
};

#endif // EXAM_H
