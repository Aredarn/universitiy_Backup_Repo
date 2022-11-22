#include "szemely.h"

Szemely::Szemely(const string &nev, int eletkor):
    nev(nev),
    eletkor(eletkor)
{
}

const string &Szemely::getNev() const
{
    return nev;
}

int Szemely::getEletkor() const
{
    return eletkor;
}

void Szemely::setEletkor(int newEletkor)
{
    eletkor = newEletkor;
}

bool Szemely::operator <(const Szemely &masik) const
{
    return nev<masik.nev || (nev==masik.nev && eletkor<masik.eletkor);
}
