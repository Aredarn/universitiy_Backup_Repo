#include "EpicToolBox.h"
#include <iostream>

namespace Tarolo{

EpicToolBox::EpicToolBox()
{
    std::cin >> meret;

    tomb = new int[meret];

    for(unsigned i = 0; i< meret;i++)
    {
        tomb[i] = i+1;
    }
}

EpicToolBox::EpicToolBox(unsigned meret):meret(meret)
{
    tomb = new int[meret];

    for(unsigned i = 0; i< meret;i++)
    {
        tomb[i] = i+1;
    }
}

EpicToolBox::~EpicToolBox()
{
    //dtor
    delete [] tomb;
}

void EpicToolBox::kiir() const
{
    for(unsigned i = 0; i< meret;i++)
    {
        std::cout << tomb[i] <<", ";
    }
}

void EpicToolBox::hozzaad(int szam)
{
    meret = meret+ 1;
    tomb[meret-1] = szam;
}

int EpicToolBox::atlag()
{
    int darab = 0;
    int osszeg = 0;


    for(int i=0;i<meret;i++)
    {
        osszeg += tomb[i];
        darab++;
    }
    int atlag = osszeg/darab;

    return atlag;

}

}
