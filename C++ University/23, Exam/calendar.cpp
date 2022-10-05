#include "calendar.h"
#include <iostream>

Calendar::Calendar()
{
}

void Calendar::addExam(const Date &date, const Exam &exam)
{
//	exams[date]=exam; <-- Nem működk, mert magától létrehozna egy Exam példányt, amit aztán átírna.
					  // Ehhez kellene az Exam-be paraméter nélküli konstruktor.
    exams.insert(pair<Date,Exam>(date,exam) );
}

void Calendar::print() const
{
	map<Date, Exam>::const_iterator it=exams.begin();
	for (; it!=exams.end(); ++it)
	{
		cout<<it->first.getYear()<<"-"<<it->first.getMonth()<<"-"<<it->first.getDay()<<": ";
		cout<<it->second.getName()<<", "<<it->second.getPlace()<<" (";
		cout<<it->second.avg()<<", "<<it->second.median()<<", "<<it->second.modus()<<", "<<it->second.deviation()<<")"<<endl;
	}
}

bool operator < (const map<Date, Exam>::const_iterator &it1, const map<Date, Exam>::const_iterator &it2)
{
	return it1->second.avg() < it2->second.avg();
}

void Calendar::printAvgOrder() const
{
	list< map<Date, Exam>::const_iterator > avg_list;

	// feltöltjük a listát
	map<Date, Exam>::const_iterator it=exams.begin();
	for (; it!=exams.end(); ++it)
	{
		avg_list.push_back(it);
	}

	// sorba rendezzük
	avg_list.sort();

	// kiírjuk, figyeljük a típusokra
	list< map<Date, Exam>::const_iterator >::iterator list_it=avg_list.begin();
	for (; list_it!=avg_list.end(); ++list_it)
	{
		map<Date, Exam>::const_iterator map_it=*list_it;
		cout<<map_it->first.getYear()<<"-"<<map_it->first.getMonth()<<"-"<<map_it->first.getDay()<<": ";
		cout<<map_it->second.getName()<<", "<<map_it->second.getPlace()<<" (";
		cout<<map_it->second.avg()<<", "<<map_it->second.median()<<", "<<map_it->second.modus()<<", "<<map_it->second.deviation()<<")"<<endl;
	}
}
