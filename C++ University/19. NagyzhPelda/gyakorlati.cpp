#include "gyakorlati.h"

Gyakorlati::Gyakorlati(string tnev, int pszam, int ponthat):Dolgozat(tnev,pszam),ponthatar(ponthat)
{

}

Gyakorlati::~Gyakorlati()
{

}

int Gyakorlati::getPonthatar() const
{
    return ponthatar;
}

string Gyakorlati::tipus() const
{
    return "gyakorlati";
}

int Gyakorlati::erdemjegy() const
{
    if(getPontszam()>ponthatar)
        return 5;
    if(ponthatar/2 < getPontszam())
        return 3;
    else
        return 1;
}

