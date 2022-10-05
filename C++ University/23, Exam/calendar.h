#ifndef CALENDAR_H
#define CALENDAR_H

#include "date.h"
#include "exam.h"

class Calendar
{
    map<Date, Exam> exams;
public:
    Calendar();

    void addExam(const Date &date, const Exam &exam);
    void print() const;
    void printAvgOrder() const;
};

#endif // CALENDAR_H
