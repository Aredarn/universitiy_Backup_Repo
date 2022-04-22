#ifndef RENDEZMENY_H
#define RENDEZMENY_H
#include "szamsor.h"

class rendezmeny: public szamsor
{

    Szamsor::tomb = 7;
    Szemely *szemely;

    public:
        rendezmeny();
        virtual ~rendezmeny();

    protected:

    private:
};

#endif // RENDEZMENY_H
