#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <list>

#include "telepules.h"

using namespace std;

class Lista
{
	list<Telepules> ls;
public:
    Lista()=default;
    void hozzaad (const Telepules& t);
    const list<Telepules>& getTartalom () const;
    void kiir() const;
};

#endif // LISTA_H
