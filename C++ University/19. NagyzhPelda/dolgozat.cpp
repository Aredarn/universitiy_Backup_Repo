#include "dolgozat.h"


int Dolgozat::getPontszam() const
{
    return pontszam;
}

Dolgozat::~Dolgozat()
{

}

Dolgozat::Dolgozat(string tnev, int pszam):targyneve(tnev), pontszam(pszam)
{
}


const string &Dolgozat::getTantargy() const
{
    return targyneve;
}


