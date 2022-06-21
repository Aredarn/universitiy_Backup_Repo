#include <iostream>
using namespace std;

class Dolgozo{
    int fizetes;
    int mikorKezdett;
public:
    Dolgozo();
    Dolgozo(int _fizetes, int _mikorKezdett);
    int getFizetes() const;
    int getMikorKezdett() const;
};

Dolgozo::Dolgozo():
    fizetes(0),
    mikorKezdett(0)
{}

Dolgozo::Dolgozo(int _fizetes, int _mikorKezdett):
    fizetes(_fizetes),
    mikorKezdett(_mikorKezdett)
{}

int Dolgozo::getFizetes() const{
    return fizetes;
}
int Dolgozo::getMikorKezdett() const{
    return mikorKezdett;
}

class Munkahely{
private:
    unsigned darab;
    Dolgozo *tomb;
protected:
    void megnovel(unsigned mennyivel);
public:
    Munkahely(unsigned alapmeret=10);
    ~Munkahely();
    unsigned aktualisdarab() const;
    Dolgozo getDolgozo(unsigned index) const;
    void beallit(const Dolgozo &adat, unsigned index);
};

Munkahely::Munkahely(unsigned alapmeret):
    darab(alapmeret)
{
    cout << "Munkahely letrejott " << alapmeret << " merettel" << endl;
    if (alapmeret==0) tomb=nullptr;
    else tomb=new Dolgozo[alapmeret];
}

Munkahely::~Munkahely(){
    delete [] tomb;
}

unsigned Munkahely::aktualisdarab() const{
    return darab;
}

void Munkahely::megnovel(unsigned mennyivel){
    cout << "Hozzaadunk " << mennyivel << " uj elemet (" << darab;
    Dolgozo *ujtomb=new Dolgozo[darab+mennyivel];
    for (unsigned i=0; i<darab; i++)
        ujtomb[i]=tomb[i];
    delete [] tomb;
    tomb=ujtomb;
    darab+=mennyivel;
    cout << "->" << darab << ")" << endl;
}

Dolgozo Munkahely::getDolgozo(unsigned index) const{
    if (index>=darab) return Dolgozo();
    else return tomb[index];
}

void Munkahely::beallit(const Dolgozo &adat, unsigned index){
    if (index<darab) tomb[index]=adat;
}


class SajatMunkahely :public Munkahely {
public:
    SajatMunkahely(unsigned n=0);
    void beallit(const Dolgozo& adat, unsigned index);
    void kevesebbetKeresoketListaz(int fiz);
    void ujabbakatListaz (int a);
};

SajatMunkahely::SajatMunkahely(unsigned n) :
    Munkahely(n)
{

}

void SajatMunkahely::beallit(const Dolgozo& adat, unsigned index) {
    if (index < aktualisdarab())
        Munkahely::beallit(adat, index);
    else {
        megnovel(index - aktualisdarab() + 1);
        beallit(adat, index);
    }
}

void SajatMunkahely::kevesebbetKeresoketListaz (int fiz) {

    for (unsigned i = 0; i < aktualisdarab(); i++) {
        if (getDolgozo(i).getFizetes() < fiz) {
            cout << getDolgozo(i).getFizetes() << " " << getDolgozo(i).getMikorKezdett() << endl;
        }
    }

}

void SajatMunkahely::ujabbakatListaz (int a) {

    for (unsigned i = 0; i < aktualisdarab(); i++) {
        if (getDolgozo(i).getMikorKezdett() < a) {
            cout << getDolgozo(i).getFizetes() << " " << getDolgozo(i).getMikorKezdett() << endl;
        }
    }

}


int main()
{
    cout << "Feltoltes" << endl;
    SajatMunkahely sajatceg;
    sajatceg.beallit(Dolgozo(210988, 1991), 2);
    sajatceg.beallit(Dolgozo(222670, 1982), 7);
    sajatceg.beallit(Dolgozo(207585, 1990), 6);
    sajatceg.beallit(Dolgozo(268039, 2016), 5);
    sajatceg.beallit(Dolgozo(299470, 1996), 1);
    sajatceg.beallit(Dolgozo(187684, 2012), 4);
    sajatceg.beallit(Dolgozo(338289, 2003), 3);
    sajatceg.beallit(Dolgozo(239658, 2006), 0);

    cout << endl << "Listazas" << endl;
    for (unsigned i=0; i<sajatceg.aktualisdarab(); i++)
    {
        Dolgozo aktualis=sajatceg.getDolgozo(i);
        cout << aktualis.getFizetes()<< " " << aktualis.getMikorKezdett() << endl;
    }

    cout << endl << "Statisztikak" << endl;
    cout << "ujabbakatListaz" << endl;
    sajatceg.ujabbakatListaz(2008);
    cout << endl;
    cout << "kevesebbetKeresoketListaz" << endl;
    sajatceg.kevesebbetKeresoketListaz(307524);
    cout << endl;

    cout << "Vege" << endl;
    return 0;
}
