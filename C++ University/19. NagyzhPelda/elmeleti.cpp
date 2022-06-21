#include "elmeleti.h"



int Elmeleti::getFeladatszam() const
{
    return feladatszam;
}

Elmeleti::Elmeleti(string tnev, int pszam, int fszam):Dolgozat(tnev,pszam), feladatszam(fszam)
{

}

Elmeleti::~Elmeleti()
{

}

string Elmeleti::tipus() const
{
    return "elmeleti";
}

int Elmeleti::erdemjegy() const
{
    if(getPontszam()<=10)
        return 1;
    if(getPontszam()<=20)
        return 2;
    if(getPontszam() <= 30)
        return 3;
    if(getPontszam() <= 40)
        return 4;
    else
        return 5;
}
