#ifndef ELMELETI_H
#define ELMELETI_H
#include "dolgozat.h"
#include <iostream>
#include <string.h>

using namespace std;


class Elmeleti : public Dolgozat
{
    int feladatszam;
public:
    Elmeleti(string tnev, int pszam, int fszam);
    ~Elmeleti();

    virtual string tipus()const;
    virtual int erdemjegy() const;
    int getFeladatszam() const;



};

#endif // ELMELETI_H
