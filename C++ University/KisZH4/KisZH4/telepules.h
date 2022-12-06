#ifndef TELEPULES_H
#define TELEPULES_H

#include <string>
#include <iostream>

#include "pont.h"

using namespace std;

// Tarolja egy telepules minden adatat.
class Telepules
{
	int id;
    string nev;
	Pont koordinatak;
public:
    Telepules();
    Telepules(int id, const string& nev, const Pont& koordinatak);

    void setMind (int id, const string& nev, const Pont& koordinatak);

	void setId (int id);
    void setNev (const string& nev);
	void setKoordinatak (const Pont& koordinatak);
	void setEszakiSzelesseg (double esz);
	void setKeletiHosszusag (double kh);

	int getId () const;
    const string& getNev() const;
	const Pont& getKoordinatak() const;
	double getEszakiSzelesseg () const;
    double getKeletiHosszusag () const;

	friend ostream& operator<<(ostream& os, const Telepules& t);
};

#endif // TELEPULES_H
