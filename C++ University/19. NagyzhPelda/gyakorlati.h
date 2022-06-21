#ifndef GYAKORLATI_H
#define GYAKORLATI_H
#include "dolgozat.h"
#include <iostream>
#include <string.h>

using namespace std;

class Gyakorlati : public Dolgozat
{
    int ponthatar;
public:
    Gyakorlati(string tnev, int pszam, int ponthat);
    ~Gyakorlati();

    int getPonthatar() const;
    virtual string tipus()const;
    virtual int erdemjegy() const;
};

#endif // GYAKORLATI_H
