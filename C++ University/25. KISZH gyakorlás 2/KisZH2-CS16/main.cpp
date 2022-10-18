#include <iostream>
#include "distances.h"

using namespace std;

int main()
{
	cout << "main() eleje!" << endl << endl;
	list<pair<string,int>> distanceListVeszprem{{"Budapest",111},{"Szolnok",214},{"Tatabanya",102},{"Szekesfehervar",45},
												{"Nyiregyhaza",341},{"Pecs",154},{"Zalaegerszeg",126},{"Debrecen",338}};
	list<pair<string,int>> distanceListBudapest{{"Veszprem",111},{"Szolnok",108},{"Tatabanya",62},{"Szekesfehervar",67},
												{"Nyiregyhaza",234},{"Pecs",205},{"Zalaegerszeg",233},{"Debrecen",231}};
	list<pair<string,int>> distanceListDebrecen{{"Budapest",231},{"Szolnok",132},{"Tatabanya",290},{"Szekesfehervar",295},
												{"Nyiregyhaza",49},{"Pecs",353},{"Zalaegerszeg",460},{"Veszprem",338}};
	list<pair<string,int>> distanceListPecs{{"Budapest",205},{"Szolnok",228},{"Tatabanya",237},{"Szekesfehervar",158},
											{"Nyiregyhaza",435},{"Veszprem",154},{"Zalaegerszeg",186},{"Debrecen",353}};

    {
        cout << endl << endl << "setDistance()" << " teszt" << endl << endl;
        Distances distVeszprem("Veszprem");
        for (const auto &dist : distanceListVeszprem)
            distVeszprem.setDistance(dist.first, dist.second);
    }

    {
        cout << endl << endl << "printAll()" << " teszt" << endl << endl;
        Distances distVeszprem("Veszprem");
        for (const auto &dist : distanceListVeszprem)
            distVeszprem.setDistance(dist.first, dist.second);
        distVeszprem.printAll();
    }

    {
        cout << endl << endl << "getDistance()" << " teszt" << endl << endl;
        Distances distVeszprem("Veszprem");
        for (const auto &dist : distanceListVeszprem)
            distVeszprem.setDistance(dist.first, dist.second);
        for (const string &city : {"Budapest", "Kaposvar", "Nyiregyhaza", "Szolnok", "Miskolc", "Pecs"})
        {
            try {
                int distance=distVeszprem.getDistance(city);
                cout << "Distance from " << distVeszprem.getCurrentCity() << " to " << city << " is " << distance << endl;
            } catch (...) {
                cout << "ERROR: No stored distance from " << distVeszprem.getCurrentCity() << " to " << city << endl;
            }
        }
    }

//	{
//		cout << endl << endl << "average()" << " teszt" << endl << endl;
//		Distances distVeszprem("Veszprem");
//		for (const auto &dist : distanceListVeszprem)
//			distVeszprem.setDistance(dist.first, dist.second);
//		cout << "Average distance: " << distVeszprem.average() << endl;
//	}

//	{
//		cout << endl << endl << "closerThan()" << " teszt" << endl << endl;
//		Distances distVeszprem("Veszprem");
//		for (const auto &dist : distanceListVeszprem)
//			distVeszprem.setDistance(dist.first, dist.second);
//		auto closeCities=distVeszprem.closerThan(200);
//		cout << "Close than 200 km:" << endl;
//		for (const auto &city : closeCities)
//			cout << city << "(" << distVeszprem.getDistance(city) << ")" << endl;
//	}

//	{
//		cout << endl << endl << "sortMany()" << " teszt" << endl << endl;
//		Distances distVeszprem("Veszprem");
//		for (const auto &dist : distanceListVeszprem)
//			distVeszprem.setDistance(dist.first, dist.second);
//		Distances distBudapest("Budapest");
//		for (const auto &dist : distanceListBudapest)
//			distBudapest.setDistance(dist.first, dist.second);
//		Distances distDebrecen("Debrecen");
//		for (const auto &dist : distanceListDebrecen)
//			distDebrecen.setDistance(dist.first, dist.second);
//		Distances distPecs("Pecs");
//		for (const auto &dist : distanceListPecs)
//			distPecs.setDistance(dist.first, dist.second);

//		// Itt válaszd ki a kettőből azt, ahogy megoldottad a feladatot
////		list<Distances*> distObjs{&distVeszprem,&distBudapest,&distDebrecen,&distPecs};
////		vector<Distances*> distObjs{&distVeszprem,&distBudapest,&distDebrecen,&distPecs};
//		Distances::sortMany(distObjs, "Szolnok");
//		cout << "Sorted based on distance from Szolnok:" << endl;
//		for (Distances *dist : distObjs)
//			cout << dist->getCurrentCity() << "(" << dist->getDistance("Szolnok") << ")" << endl;
//	}

//	{
//		cout << endl << endl << "printByDistance()" << " teszt" << endl << endl;
//		Distances distVeszprem("Veszprem");
//		for (const auto &dist : distanceListVeszprem)
//			distVeszprem.setDistance(dist.first, dist.second);
//		distVeszprem.printByDistance();
//	}

	cout << endl << endl << "main() vege!" << endl;


	return 0;
}
