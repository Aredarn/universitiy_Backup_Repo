#include "szoba.h"

Szoba::Szoba(int id, int emelet, int ajto, int ferohelyek):
	id(id),
	emelet(emelet),
	ajto(ajto),
	ferohelyek(ferohelyek)
{
}

int Szoba::getId() const
{
	return id;
}

int Szoba::getEmelet() const
{
	return emelet;
}

int Szoba::getAjto() const
{
	return ajto;
}

int Szoba::getFerohelyek() const
{
	return ferohelyek;
}
