#include <iostream>
#include "dolgozat.h"
#include "elmeleti.h"
#include "gyakorlati.h"
#include "hallgato.h"
#include "sablonoselmeleti.h"

using namespace std;

// A feladatokhoz ezek a define-ok kellenek A HEADER FÁJLBAN:
#define PART1
#define PART1a
#define PART1b
#define PART2
#define PART2a
#define PART2b
#define PART3
#define PART3a
#define PART3b
#define PART4
#define PART4a
#define PART4b
#define PART4c
#define PART4d
#define PART4e
#define PART5
//#define PART5a
//#define PART5b
// PART1 kell, ha kész az első feladat és szeretnéd hogy a javító elfogadja, PART2 a 2.-hoz, stb
// Ne itt a main.cpp-be szedd ki a kommentből, hanem másold be valamelyik saját header fájlodba, mondjuk az #include-ok utánra
// (Amit a main.cpp-ben módosítasz, azt a javító úgysem látja)
// Ha valamelyik define nincs a kódban, az ahhoz tartozó tesztelő részt a main-ben nem is nézi a javító, így nem lesz fordítási hiba (de pont sem).

void printPartStart(const string &partname)
{
	cout << endl << "----START OF " << partname << "----" << endl << endl;
}

void printPartEnd(const string &partname)
{
	cout << endl << "----END OF " << partname << "----" << endl << endl;
}

class KedvesPontHatarok;
class SzigoruPontHatarok;

#ifdef PART4b
// Meghívja az elsohelyre függvény, és kiírja a visszaadott indexet. Ha nem sikerült a hozzáadás, akkor gondoskodik a felszabadításról.
void elsohelyreSeged(Hallgato &h, Dolgozat *doga)
{
	int ujindex;
	ujindex = h.elsohelyre(doga);
	cout << ujindex << endl;
	if (ujindex==-1) delete doga;
}
#endif

int main()
{

#ifdef PART1
	printPartStart("PART1");
	{
		// Dolgozat teszt: Nem ír ki semmit, de lefordul
		Dolgozat *d=nullptr;
		if (d)
		{
			string targy=d->getTantargy();
			unsigned int pont=d->getPontszam();
			cout << targy << " " << pont << endl;
		}
	}
	printPartEnd("PART1");
#endif

#ifdef PART1a
	printPartStart("PART1a");
	{
		// Dolgozat teszt: Nem ír ki semmit, de lefordul
		cout << "A Dolgozat osztaly absztrakt: ";
		if (is_abstract<Dolgozat>::value) cout << "IGEN" << endl;
		else cout << "NEM" << endl;
		cout << "Virtualis destruktor: ";
		if (has_virtual_destructor<Dolgozat>::value) cout << "VAN" << endl;
		else cout << "NINCS" << endl;
		Dolgozat *d=nullptr;
		if (d)
		{
			string tipus=d->tipus();
			cout << tipus << endl;
		}
	}
	printPartEnd("PART1a");
#endif

#ifdef PART1b
	printPartStart("PART1b");
	{
		// Dolgozat teszt: Nem ír ki semmit, de lefordul
		Dolgozat *d=nullptr;
		if (d)
		{
			int jegy=d->erdemjegy();
			cout << jegy << endl;
		}
	}
	printPartEnd("PART1b");
#endif

#ifdef PART2
	printPartStart("PART2");
	{
		// Elmeleti teszt: konstruktor, getterek
		Elmeleti e1("Elm1", 20, 5);
		Dolgozat *d1=new Elmeleti("Elm2", 35, 6);
		cout << e1.getTantargy() << " " << e1.getPontszam() << " " << e1.getFeladatszam() << endl; // Elm1 20 5
		cout << d1->getTantargy() << " " << d1->getPontszam() << endl; // Elm2 35
		delete d1;
	}
	printPartEnd("PART2");
#endif

#ifdef PART2a
	printPartStart("PART2a");
	{
		// Elmeleti teszt: tipus
		Elmeleti e1("Elm1", 20, 5);
		Dolgozat *d1=new Elmeleti("Elm2", 35, 6);
		cout << e1.tipus() << endl; // elmeleti
		cout << d1->tipus() << endl; // elmeleti
		delete d1;
	}
	printPartEnd("PART2a");
#endif

#ifdef PART2b
	printPartStart("PART2b");
	{
		// Elmeleti teszt: erdemjegy
		Elmeleti e1("Elm1", 20, 5);
		Dolgozat *d1=new Elmeleti("Elm2", 35, 6);
		cout << e1.erdemjegy() << endl; // 2
		cout << d1->erdemjegy() << endl; // 4
		delete d1;
	}
	printPartEnd("PART2b");
#endif

#ifdef PART3
	printPartStart("PART3");
	{
		// Gyakorlati teszt: konstruktor, getterek
		Gyakorlati g1("Gyak1", 24, 70);
		Dolgozat *d2=new Gyakorlati("Gyak2", 43, 39);
		cout << g1.getTantargy() << " " << g1.getPontszam() << " " << g1.getPonthatar() << endl; // Gyak1 24 70
		cout << d2->getTantargy() << " " << d2->getPontszam() << endl; // Gyak2 43
		delete d2;
	}
	printPartEnd("PART3");
#endif

#ifdef PART3a
	printPartStart("PART3a");
	{
		// Elmeleti teszt: tipus
		Gyakorlati g1("Gyak1", 24, 70);
		Dolgozat *d2=new Gyakorlati("Gyak2", 43, 39);
		cout << g1.tipus() << endl; // gyakorlati
		cout << d2->tipus() << endl; // gyakorlati
		delete d2;
	}
	printPartEnd("PART3a");
#endif

#ifdef PART3b
	printPartStart("PART3b");
	{
		// Elmeleti teszt: erdemjegy
		Gyakorlati g1("Gyak1", 24, 70);
		Dolgozat *d2=new Gyakorlati("Gyak2", 43, 39);
		cout << g1.erdemjegy() << endl; // 1
		cout << d2->erdemjegy() << endl; // 5
		delete d2;
	}
	printPartEnd("PART3b");
#endif

#ifdef PART4
	printPartStart("PART4");
		{
		// Hallgato teszt: konstruktor, getterek
		Hallgato h1("Teszt Szemely", "ABC123");
		cout << h1.getNev() << " " << h1.getNeptun() << endl; // Teszt Szemely ABC123
	}
	printPartEnd("PART4");
#endif

#ifdef PART4a
	printPartStart("PART4a");
	{
		// Hallgato teszt: hozzaad
		Hallgato h1("Teszt Szemely", "ABC123");
		h1.hozzaad(new Elmeleti("Elm3", 31, 4),4);
		h1.hozzaad(new Gyakorlati("Gyak3", 12, 19),1);
		h1.hozzaad(new Elmeleti("Elm4", 9, 3),0);
		h1.hozzaad(new Gyakorlati("Gyak4", 54,23),9);
		h1.hozzaad(new Elmeleti("Elm5", 65, 8),4); // Felul irja az elso hozzaadast
	}
	printPartEnd("PART4a");
#endif

#ifdef PART4b
	printPartStart("PART4b");
	{
		// Hallgato teszt: elsohelyre
		Hallgato h1("Teszt Szemely", "ABC123");
		h1.hozzaad(new Elmeleti("Elm3", 31, 4),4);
		h1.hozzaad(new Gyakorlati("Gyak3", 12, 19),1);
		h1.hozzaad(new Elmeleti("Elm4", 9, 3),0);
		h1.hozzaad(new Gyakorlati("Gyak4", 54,23),9);
		elsohelyreSeged(h1, new Gyakorlati("Gyak5", 43, 71)); // 2
		elsohelyreSeged(h1, new Gyakorlati("Gyak6", 44, 72)); // 3
		elsohelyreSeged(h1, new Gyakorlati("Gyak7", 45, 73)); // 5
		elsohelyreSeged(h1, new Gyakorlati("Gyak8", 46, 74)); // 6
		elsohelyreSeged(h1, new Gyakorlati("Gyak9", 47, 75)); // 7
		elsohelyreSeged(h1, new Gyakorlati("Elm10", 48, 7)); // 8
		elsohelyreSeged(h1, new Gyakorlati("Elm11", 49, 6)); // -1
	}
	printPartEnd("PART4b");
#endif

#ifdef PART4c
	printPartStart("PART4c");
	{
		// Hallgato teszt: memoriakezeles ellenorzes
		Hallgato h1("Teszt Szemely", "ABC123");
		h1.hozzaad(new Elmeleti("Elm3", 31, 4),4);
		h1.hozzaad(new Gyakorlati("Gyak3", 12, 19),1);
		h1.hozzaad(new Elmeleti("Elm4", 9, 3),0);
		h1.hozzaad(new Gyakorlati("Gyak4", 54,23),9);
		h1.hozzaad(new Elmeleti("Elm5", 65, 8),4); // Felul irja az elso hozzaadast
	}
	printPartEnd("PART4c");
#endif

#ifdef PART4d
	printPartStart("PART4d");
	{
		// Hallgato teszt: memoriakezeles ellenorzes
		Hallgato h1("Teszt Szemely", "ABC123");
		h1.hozzaad(new Elmeleti("Elm3", 31, 4),4);
		h1.hozzaad(new Gyakorlati("Gyak3", 12, 19),1);
		h1.hozzaad(new Elmeleti("Elm4", 9, 3),0);
		h1.hozzaad(new Gyakorlati("Gyak4", 54,23),9);
		h1.hozzaad(new Elmeleti("Elm5", 65, 8),4); // Felul irja az elso hozzaadast
		// Hallgato teszt: operator <<
		cout << h1 << endl;
	//	Nev: Teszt Szemely, neptun: ABC123
	//	Dolgozatok:
	//	  Index: 0, targy: Elm4, pont: 9, tipus: elmeleti, erdemjegy: 1
	//	  Index: 1, targy: Gyak3, pont: 12, tipus: gyakorlati, erdemjegy: 3
	//	  Index: 4, targy: Elm5, pont: 65, tipus: elmeleti, erdemjegy: 5
	//	  Index: 9, targy: Gyak4, pont: 54, tipus: gyakorlati, erdemjegy: 5
	}
	printPartEnd("PART4d");
#endif

#ifdef PART4e
	printPartStart("PART4e");
	{
		// Hallgato teszt: memoriakezeles ellenorzes
		Hallgato h1("Teszt Szemely", "ABC123");
		h1.hozzaad(new Elmeleti("Elm3", 31, 4),4);
		h1.hozzaad(new Gyakorlati("Gyak3", 12, 19),1);
		h1.hozzaad(new Elmeleti("Elm4", 9, 3),0);
		h1.hozzaad(new Gyakorlati("Gyak4", 54,23),9);
        cout << (*h1) << endl; // 4
	}
	printPartEnd("PART4e");
#endif

#ifdef PART5
	printPartStart("PART5");
	{
		// SablonosElmeleti teszt
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti1("Kedves1", 4, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti1("Szigoru1", 5, 6);
		Elmeleti *ep1=&kedvesElmeleti1;
		Elmeleti *ep2=&szigoruElmeleti1;
		cout << ep1->getTantargy() << " " << ep1->getPontszam() << " " << ep1->getFeladatszam() << endl; // Kedves1 4 2
		cout << ep2->getTantargy() << " " << ep2->getPontszam() << " " << ep2->getFeladatszam() << endl; // Szigoru1 5 6
	}
	printPartEnd("PART5");
#endif

#ifdef PART5a
	printPartStart("PART5a");
	{
		// SablonosElmeleti teszt: erdemjegy
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti1("Kedves1", 4, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti2("Kedves2", 16, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti3("Kedves3", 26, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti4("Kedves4", 8, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti5("Kedves5", 40, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti6("Kedves6", 35, 2);
		SablonosElmeleti<KedvesPontHatarok> kedvesElmeleti7("Kedves7", 48, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti1("Szigoru1", 4, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti2("Szigoru2", 16, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti3("Szigoru3", 26, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti4("Szigoru4", 8, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti5("Szigoru5", 40, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti6("Szigoru6", 35, 2);
		SablonosElmeleti<SzigoruPontHatarok> szigoruElmeleti7("Szigoru7", 48, 2);
		cout << kedvesElmeleti1.erdemjegy() << endl; // 1
		cout << kedvesElmeleti2.erdemjegy() << endl; // 3
		cout << kedvesElmeleti3.erdemjegy() << endl; // 4
		cout << kedvesElmeleti4.erdemjegy() << endl; // 2
		cout << kedvesElmeleti5.erdemjegy() << endl; // 5
		cout << kedvesElmeleti6.erdemjegy() << endl; // 5
		cout << kedvesElmeleti7.erdemjegy() << endl; // 5
		cout << szigoruElmeleti1.erdemjegy() << endl; // 1
		cout << szigoruElmeleti2.erdemjegy() << endl; // 2
		cout << szigoruElmeleti3.erdemjegy() << endl; // 3
		cout << szigoruElmeleti4.erdemjegy() << endl; // 1
		cout << szigoruElmeleti5.erdemjegy() << endl; // 4
		cout << szigoruElmeleti6.erdemjegy() << endl; // 4
		cout << szigoruElmeleti7.erdemjegy() << endl; // 5
	}
	printPartEnd("PART5a");
#endif

#ifdef PART5b
	printPartStart("PART5b");
	{
		// SablonosElmeleti teszt: legkisebbIntervallum
		cout << SablonosElmeleti<KedvesPontHatarok>::legkisebbIntervallum() << endl; // 1
		cout << SablonosElmeleti<SzigoruPontHatarok>::legkisebbIntervallum() << endl; // 5
	}
	printPartEnd("PART5b");
#endif

	cout << endl << endl;
	return 0;
}

class KedvesPontHatarok
{
public:
	static unsigned int ponthatar(unsigned int jegy)
	{
		switch (jegy) {
		case 1:
			return 0;
		case 2:
			return 5;
		case 3:
			return 12;
		case 4:
			return 20;
		case 5:
			return 34;
		}
		return 0;
	}
};

class SzigoruPontHatarok
{
	static unsigned int pontTomb[5];
public:
	static unsigned int ponthatar(unsigned int jegy)
	{
		return pontTomb[jegy-1];
	}
};

unsigned int SzigoruPontHatarok::pontTomb[5]={0,15,25,34,46};
