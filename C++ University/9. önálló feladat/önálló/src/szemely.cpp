#include "szemely.h"

#include <iostream>

Szemely::Szemely(const string &v, const string &k, unsigned int kor):
	vnev(v),
	knev(k),
	eletkor(kor)
{
}

const string &Szemely::getVezetekNev() const
{
	return vnev;
}

const string &Szemely::getKeresztNev() const
{
	return knev;
}

string Szemely::teljesNev() const
{
	return vnev + " " + knev; // Figyelem: itt a m�velet �j v�ltoz�t hoz l�tre, ami megsz�nik a f�ggv�ny v�g�n. �gy nem lehet referenci�val visszat�rni.
}

unsigned int Szemely::getEletkor() const
{
	return eletkor;
}

void Szemely::kiir() const
{
	cout << vnev << " " << knev << ": " << eletkor << endl;
}
