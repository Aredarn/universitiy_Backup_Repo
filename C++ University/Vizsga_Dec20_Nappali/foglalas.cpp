#include "foglalas.h"

Foglalas::Foglalas(int id, const string &igazolvanySzam, int letszam, const string &mettol, const string &meddig, int ejszakak):
	id(id),
	igazolvanySzam(igazolvanySzam),
	letszam(letszam),
	mettol(mettol),
	meddig(meddig),
	ejszakak(ejszakak),
	szoba(nullptr)
{
}

int Foglalas::getId() const
{
	return id;
}

const string &Foglalas::getIgazolvanySzam() const
{
	return igazolvanySzam;
}

int Foglalas::getLetszam() const
{
	return letszam;
}

const string &Foglalas::getMettol() const
{
	return mettol;
}

const string &Foglalas::getMeddig() const
{
	return meddig;
}

int Foglalas::getEjszakak() const
{
	return ejszakak;
}

Szoba *Foglalas::getSzoba() const
{
	return szoba;
}

void Foglalas::setSzoba(Szoba *newSzoba)
{
	szoba = newSzoba;
}
