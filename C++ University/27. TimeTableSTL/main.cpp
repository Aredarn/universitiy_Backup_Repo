#include <iostream>
#include <fstream>
#include "worker.h"
//#include "company.h"

using namespace std;

int main()
{
//	list<Worker> workers;
//	readWorkers(workers); // ERROR: shift for 2016.11.04. already saved (2x)
//	cout << workers.size() << " worker loaded" << endl; //2 worker loaded
//	Worker w1 = workers.front();
//	Worker w2 = workers.back();

//	cout<<"Shifts of "<<w1.getId()<<" "<<w1.getPosition()<<" :"<<endl; // Shifts of 34 developer :
//	w1.printTable();
//	cout<<endl;
	/*
	2016.04.14.: 7-17
	2016.05.23.: 8-16
	2016.10.30.: 8-16
	2016.10.31.: 8-16
	2016.11.03.: 12-20
	2016.11.04.: 6-14
	*/

//	cout<<"Shifts of "<<w2.getId()<<" "<<w2.getPosition()<<" :"<<endl; // Shifts of 45 manager :
//	w2.printTable();
//	cout<<endl;
	/*
	2016.05.12.: 8-16
	2016.08.24.: 10-18
	2016.10.30.: 5-14
	2016.11.06.: 9-15
	*/

//	cout<<w1.isFree("2016.10.30.")<<endl; // 0
//	cout<<w1.isFree("2016.11.06.")<<endl; // 1
//	cout<<w1.isFree("2016.04.14.")<<endl; // 0

//	cout<<w2.isFree("2016.10.30.")<<endl; // 0
//	cout<<w2.isFree("2016.11.06.")<<endl; // 0
//	cout<<w2.isFree("2016.04.14.")<<endl; // 1

//	cout<<endl<<endl;
//	Company c("SzoftTech Kft.");

//	c.addWorker(10, "developer");
//	c.addWorker(11, "senior developer");
//	c.addWorker(12, "manager");

//	Worker *cw1=c.getWorker(10);
//	Worker *cw2=c.getWorker(11);
//	Worker *cw3=c.getWorker(12);
//	Worker *cw4=c.getWorker(13);
//	cout<<cw1<<endl;
//	cout<<cw2<<endl;
//	cout<<cw3<<endl;
//	cout<<cw4<<endl; // 0 az eredmény (nullptr), mert ilyen azonosító nem létezik.

//	cw1->addShift("2016.10.30.", 8, 16);
//	cw1->addShift("2016.10.31.", 8, 16);
//	cw1->addShift("2016.11.04.", 6, 14);
//	cw1->addShift("2016.11.03.", 12, 20);
//	cw1->addShift("2016.05.23.", 8, 16);
//	cw1->addShift("2016.04.14.", 7, 17);

//	cw2->addShift("2016.09.03.", 12, 20);
//	cw2->addShift("2016.08.12.", 8, 16);
//	cw2->addShift("2016.11.07.", 9, 15);

//	cw3->addShift("2016.10.30.", 5, 14);
//	cw3->addShift("2016.05.12.", 8, 16);
//	cw3->addShift("2016.08.24.", 10, 18);
//	cw3->addShift("2016.11.06.", 9, 15);

//	c.print();
	/*
	SzoftTech Kft.
	Worker id: 10, position: developer, shifts:
	2016.04.14.: 7-17
	2016.05.23.: 8-16
	2016.10.30.: 8-16
	2016.10.31.: 8-16
	2016.11.03.: 12-20
	2016.11.04.: 6-14
	Worker id: 11, position: senior developer, shifts:
	2016.08.12.: 8-16
	2016.09.03.: 12-20
	2016.11.07.: 9-15
	Worker id: 12, position: manager, shifts:
	2016.05.12.: 8-16
	2016.08.24.: 10-18
	2016.10.30.: 5-14
	2016.11.06.: 9-15
	*/

//	cout<<endl<<endl;
//	c.sort();
//	c.print();
	/*
	SzoftTech Kft.
	Worker id: 11, position: senior developer, shifts:
	2016.08.12.: 8-16
	2016.09.03.: 12-20
	2016.11.07.: 9-15
	Worker id: 12, position: manager, shifts:
	2016.05.12.: 8-16
	2016.08.24.: 10-18
	2016.10.30.: 5-14
	2016.11.06.: 9-15
	Worker id: 10, position: developer, shifts:
	2016.04.14.: 7-17
	2016.05.23.: 8-16
	2016.10.30.: 8-16
	2016.10.31.: 8-16
	2016.11.03.: 12-20
	2016.11.04.: 6-14
	*/

	cout<<endl<<endl;
	// Itt a függvényt úgy kell meghívni, hogy a 2016.08.24., 2016.04.14., és 2016.04.15. dátumok legyenek benne.
	// Itt ki kell írni a megtalált dolgozók adatait.
	/*
	Worker id: 11, position: senior developer, shifts:
	2016.08.12.: 8-16
	2016.09.03.: 12-20
	2016.11.07.: 9-15
	*/

	cout<<endl<<endl;
	//Mutatóval
	// Meg kell hívni mégegyszer a 2016.09.03. és 2016.09.04. dátumokkal.
	// Itt ki kell írni a megtalált dolgozók adatait.
	/*
	Worker id: 12, position: manager, shifts:
	2016.05.12.: 8-16
	2016.08.24.: 10-18
	2016.10.30.: 5-14
	2016.11.06.: 9-15
	Worker id: 10, position: developer, shifts:
	2016.04.14.: 7-17
	2016.05.23.: 8-16
	2016.10.30.: 8-16
	2016.10.31.: 8-16
	2016.11.03.: 12-20
	2016.11.04.: 6-14
	*/
return 0;
}
