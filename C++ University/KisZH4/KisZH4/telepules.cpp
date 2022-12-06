#include "telepules.h"

Telepules::Telepules():
    id(0),
    nev("URES")
{
}

Telepules::Telepules(int id, const string& nev,
                     const Pont& koordinatak):
	id(id),
    nev(nev),
	koordinatak(koordinatak)
{
}

void Telepules::setMind(int id, const string& nev,
                        const Pont& koordinatak)
{
	this->id = id;
    this->nev = nev;
	this->koordinatak = koordinatak;
}

void Telepules::setId(int id)
{
	this->id = id;
}

void Telepules::setNev(const string& nev)
{
	this->nev = nev;
}

void Telepules::setKoordinatak(const Pont& koordinatak)
{
	this->koordinatak = koordinatak;
}

void Telepules::setEszakiSzelesseg(double esz)
{
	this->koordinatak.esz = esz;
}

void Telepules::setKeletiHosszusag(double kh)
{
	this->koordinatak.kh = kh;
}

int Telepules::getId() const
{
	return id;
}

const string& Telepules::getNev() const
{
	return nev;
}

const Pont& Telepules::getKoordinatak() const
{
	return koordinatak;
}

double Telepules::getEszakiSzelesseg() const
{
	return koordinatak.esz;
}

double Telepules::getKeletiHosszusag() const
{
	return koordinatak.kh;
}


ostream& operator<<(ostream& os, const Telepules& t)
{
	os << t.getId() << " ";
	os << t.getNev() << " ";
	Pont p = t.getKoordinatak();
	os << "N" << p.esz << " ";
	os << "E" << p.kh;
	return os;
}
