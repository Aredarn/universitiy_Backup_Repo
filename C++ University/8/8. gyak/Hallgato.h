#ifndef HALLGATO_H
#define HALLGATO_H
#include "szemely.h"

class Hallgato : public Szemely
{
    string neptunkKod;
    unsigned felevek;

    public:
        Hallgato(const string &v, const string &k, unsigned int kor, const string &neptun, unsigned felev =1);
        void kiir() const;

};

#endif // HALLGATO_H
