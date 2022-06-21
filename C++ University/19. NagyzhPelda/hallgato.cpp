#include "hallgato.h"

const string &Hallgato::getNev() const
{
    return nev;
}

const string &Hallgato::getNeptun() const
{
    return neptun;
}

void Hallgato::hozzaad(Dolgozat* doga, int index)
{
    if(dolgozat[index] != nullptr)
        delete dolgozat[index];

    dolgozat[index] = doga;

}

int Hallgato::elsohelyre(Dolgozat *doga)
{
    for (int i = 0; i < 10; ++i) {
        if(dolgozat[i] == nullptr)
        {
            dolgozat[i] = doga;
            return i;
        }
    }
    return -1;
}

Hallgato::~Hallgato()
{
    for (int var = 0; var < 10; ++var) {
        delete dolgozat[var];
    }
}




Hallgato::Hallgato(string nev, string neptun):nev(nev),neptun(neptun)
{
    for (int var = 0; var < 10; ++var) {
        dolgozat[var] = nullptr;
    }
}
