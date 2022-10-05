#include <iostream>
#include "exam.h"
#include "calendar.h"

using namespace std;

int main()
{
	Exam e1("korszprog", "PC0");
	e1.addGrade(4);
	e1.addGrade(5);
	e1.addGrade(5);
	e1.addGrade(4);
	e1.addGrade(3);
	e1.addGrade(4);
	e1.addGrade(4);
	e1.addGrade(4);
	e1.addGrade(3);
	e1.addGrade(5);
	e1.addGrade(4);
	e1.addGrade(5);
	e1.addGrade(4);
	e1.addGrade(4);
	Exam e2("prog1", "I2");
	e2.addGrade(5);
	e2.addGrade(5);
	e2.addGrade(5);
	e2.addGrade(5);
	e2.addGrade(5);
	e2.addGrade(5);
	e2.addGrade(4);
	e2.addGrade(3);
	e2.addGrade(5);
	e2.addGrade(4);
	e2.addGrade(2);
	e2.addGrade(4);
	e2.addGrade(4);
	e2.addGrade(2);
	Exam e3("prog2", "I3");
	e3.addGrade(5);
	e3.addGrade(5);
	e3.addGrade(5);
	e3.addGrade(5);
	e3.addGrade(4);
	e3.addGrade(5);
	e3.addGrade(4);
	e3.addGrade(3);
	e3.addGrade(4);
	e3.addGrade(3);
	e3.addGrade(4);
	e3.addGrade(3);
	e3.addGrade(2);


	cout<<e1.avg()<<", "<<e1.median()<<", "<<e1.modus()<<", "<<e1.deviation()<<endl; // 4.14286, 4, 4, 0.662994
	cout<<e2.avg()<<", "<<e2.median()<<", "<<e2.modus()<<", "<<e2.deviation()<<endl; // 4.14286, 4.5, 5, 1.09945
	cout<<e3.avg()<<", "<<e3.median()<<", "<<e3.modus()<<", "<<e3.deviation()<<endl; // 4, 4, 5, 1

	Calendar c;
	c.addExam(Date(2016,9,26), e1);
	c.addExam(Date(2016,4,12), e2);
	c.addExam(Date(2016,9,28), e3);

	cout<<endl<<endl;
	c.print();
//	2016-4-12: prog1, I2 (4.14286, 4.5, 5, 1.09945)
//	2016-9-26: korszprog, PC0 (4.14286, 4, 4, 0.662994)
//	2016-9-28: prog2, I3 (4, 4, 5, 1)

	cout<<endl<<endl;
	c.printAvgOrder();
//	2016-9-28: prog2, I3 (4, 4, 5, 1)
//	2016-9-26: korszprog, PC0 (4.14286, 4, 4, 0.662994)
//	2016-4-12: prog1, I2 (4.14286, 4.5, 5, 1.09945)

	return 0;
}
