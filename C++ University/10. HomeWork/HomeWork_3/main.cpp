#include <iostream>
using namespace std;

class Jarmu
{
    int ertekeles;
    string gyarto;
    int evjarat;
public:

    Jarmu(int _ertekeles, const string & _gyarto, int _evjarat);
    ~Jarmu();
    int getErtekeles() const;
    string getGyarto() const;
    int getEvjarat() const;
};

Jarmu::Jarmu(int _ertekeles, const string & _gyarto, int _evjarat):
    ertekeles(_ertekeles),
    gyarto(_gyarto),
    evjarat(_evjarat)
{}

Jarmu::~Jarmu(){
    cout << "Deleted Jarmu:" << " " << ertekeles << " " << gyarto << " " << evjarat << endl;
}

int Jarmu::getErtekeles() const{
    return ertekeles;
}
string Jarmu::getGyarto() const{
    return gyarto;
}
int Jarmu::getEvjarat() const{
    return evjarat;
}

class Arus
{
    Jarmu **tomb;
    unsigned int meret;
public:
    Arus(unsigned int _meret);
    ~Arus();
    void indexhezRendel(Jarmu *mutato, unsigned int index);
    int mennyiRosszabb(int _ertek) const;
    int mennyiIdosebb(int ev) const;
};

Arus::Arus(unsigned _meret):
    tomb(new Jarmu*[_meret]),meret(_meret)
{
}

Arus::~Arus()
{
    for(unsigned i=0;i<meret;i++)
    {
        delete tomb[i];
    }

    delete[] tomb;
}

void Arus::indexhezRendel(Jarmu *mutato,unsigned index)
{
    tomb[index] = mutato;
}

int Arus::mennyiRosszabb(int _ertek) const
{
    int darab = 0;

    for(unsigned i = 0;i<meret;i++)
    {
        if(tomb[i]->getErtekeles() < _ertek)
            darab++;
    }
    return darab;
}

int Arus::mennyiIdosebb(int ev) const
{
    int darab = 0;

    for(unsigned i = 0;i<meret;i++)
    {
        if(tomb[i]->getEvjarat() < ev)
            darab++;
    }
    return darab;
}

int main()
{
    Arus autotar(8);
    autotar.indexhezRendel(new Jarmu(43, "Ford", 2019), 0);
    autotar.indexhezRendel(new Jarmu(20, "Audi", 1998), 1);
    autotar.indexhezRendel(new Jarmu(83, "Suzuki", 1989), 2);
    autotar.indexhezRendel(new Jarmu(46, "Audi", 1998), 3);
    autotar.indexhezRendel(new Jarmu(98, "Skoda", 2017), 4);
    autotar.indexhezRendel(new Jarmu(66, "Seat", 1992), 5);
    autotar.indexhezRendel(new Jarmu(58, "Suzuki", 2001), 6);
    autotar.indexhezRendel(new Jarmu(39, "Fiat", 1995), 7);

    cout << "mennyiRosszabb" << endl;
    cout << autotar.mennyiRosszabb(42) << endl;
    cout << endl;
    cout << "mennyiIdosebb" << endl;
    cout << autotar.mennyiIdosebb(2015) << endl;
    cout << endl;

    cout << "Vege" << endl;
    return 0;
}
