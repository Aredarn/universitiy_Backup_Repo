#ifndef EXAM_H
#define EXAM_H
#include <string>
#include <vector>
#include <iostream>
#include <list>
using namespace std;


class Exam{
private:
    string name;
    string place;
    vector<int> grades;


public:

    Exam(const string& n, const string& p): name(n), place(p){}

    const string &getName() const;
    const string &getPlace() const;

    void addGrade(int grade)
    {
        grades.push_back(grade);
    }

    void print() const{
        cout << name << " "<< place <<endl;
        cout << "\t";

        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << endl;
    }
    //----------------------------------//
    double avg () const{
        double osszeg;
        for(int grade : grades)
            osszeg = osszeg + grade;
        return osszeg / grades.size();
    }

    double median() const
    {
          list<int> ordered(grades.cbegin(), grades.cend());
          ordered.sort();
          vector<int> orderedGrades(ordered.cbegin(),ordered.cend());

          if(orderedGrades.size() % 2 == 0)
              return (orderedGrades[orderedGrades.size()/2] + orderedGrades[orderedGrades.size()/-1]) /2.0;
          else
            return orderedGrades[orderedGrades.size()/2];
    }

};

inline const string &Exam::getName() const
{
    return name;
}

inline const string &Exam::getPlace() const
{
    return place;
}


#endif // EXAM_H
