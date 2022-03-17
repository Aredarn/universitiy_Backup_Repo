#include "Szamok.h"


namespace Tarolo{

Szamok::Szamok(unsigned _meret, double _ertek):meret(_meret)
{
    tomb = new double[_meret];

    for(unsigned i=0;i<meret;i++)
    {
        tomb[i]=_ertek;
    }
}

Szamok::~Szamok()
{
    delete [] tomb;
}


unsigned Szamok::darabLeker() const
{

    return meret;
}

void Szamok::ertekBeallit(unsigned index, double ertek)
{
    if(index<meret)
    {
        tomb[index] = ertek;
    }
}

double Szamok::ertekLeker(unsigned index) const
{
    if(index<meret)
        return tomb[index];
    else
        return -1e8;
}

}
