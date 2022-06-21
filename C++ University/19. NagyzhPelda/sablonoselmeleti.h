#ifndef SABLONOSELMELETI_H
#define SABLONOSELMELETI_H
#include "dolgozat.h"
#include "elmeleti.h"
#include <iostream>
#include <string.h>

using namespace std;

template <class T> class SablonosElmeleti : public Elmeleti
{

public:
    SablonosElmeleti(const string &tnev,const int &pszam,const int &fszam);
};

#endif // SABLONOSELMELETI_H
