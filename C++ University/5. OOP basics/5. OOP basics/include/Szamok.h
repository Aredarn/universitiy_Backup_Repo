#ifndef SZAMOK_H
#define SZAMOK_H

namespace Tarolo{


class Szamok
{
    unsigned meret;
    double *tomb;

public:
    Szamok(unsigned _meret, double _ertek = 0);
    ~Szamok();
    unsigned darabLeker() const;
    void ertekBeallit(unsigned index, double ertek);
    double ertekLeker(unsigned index) const;

};

#endif // SZAMOK_H

}//end of namespcae
