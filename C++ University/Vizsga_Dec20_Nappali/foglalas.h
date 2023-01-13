#ifndef FOGLALAS_H
#define FOGLALAS_H

#include <string>
#include "szoba.h"

using namespace std;

class Foglalas
{
	int id;
	string igazolvanySzam;
	int letszam;
	string mettol, meddig;
	int ejszakak;
	Szoba *szoba;
public:
	Foglalas() = default;
	Foglalas(int id, const string &igazolvanySzam, int letszam, const string &mettol, const string &meddig, int ejszakak);
	int getId() const;
	const string &getIgazolvanySzam() const;
	int getLetszam() const;
	const string &getMettol() const;
	const string &getMeddig() const;
	int getEjszakak() const;
	Szoba *getSzoba() const;
	void setSzoba(Szoba *newSzoba);
};

#endif // FOGLALAS_H
