#ifndef HALLGATO_H
#define HALLGATO_H
#include "dolgozat.h"
#include <iostream>
#include <string.h>

using namespace std;

class Hallgato
{
    string nev;
    string neptun;
    Dolgozat* dolgozat[10];


public:

    Hallgato(string nev, string neptun);
    const string &getNev() const;
    const string &getNeptun() const;
    void hozzaad(Dolgozat *doga, int index);
    int elsohelyre(Dolgozat *doga);
    ~Hallgato();

    friend ostream &operator<<(ostream& os,const Hallgato& h)
    {
        os <<"Nev: "<< h.nev <<", " <<"neptun: "<< h.neptun;

        os <<endl << "Dolgozatok:" <<endl;
        for (int i = 0; i < 10; ++i) {
            if(h.dolgozat[i] != nullptr)
            {
                os <<"Index: "<< i << ", targy: "<< h.dolgozat[i]->getTantargy()
                << ", pont: "<< h.dolgozat[i]->getPontszam() <<
                ", tipus: "<<   h.dolgozat[i]->tipus()
                << ", erdemjegy: " <<  h.dolgozat[i]->erdemjegy() << endl;
            }

        }
        return os;
    }

    friend int operator *(Hallgato& h){
        int db = 0;
        for (int i = 0; i < 10; ++i) {
            if(h.dolgozat[i] != nullptr)
            {
                db++;
            }
        }
        return db;
    }

};

#endif // HALLGATO_H
