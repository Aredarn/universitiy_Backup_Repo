#include <iostream>
#include <cmath>
using namespace std;

double roundToPlaces(double value, int decimal_places) {
    const double multiplier = std::pow(10.0, decimal_places);
    return std::round(value * multiplier+0.0000001) / multiplier;
}



/*##SOLUTION##*/
class AlakzatOs{
public:
    virtual ~AlakzatOs();
    virtual unsigned csucsok() const = 0;
    virtual double getKerulet() const = 0;
    virtual double getTerulet() const = 0;

    void keruletEsTerulet() const;

};

AlakzatOs::~AlakzatOs(){

}

void AlakzatOs::keruletEsTerulet() const
{
    cout << "Kerulet: " << roundToPlaces(getKerulet(),2) <<", terulet: " << roundToPlaces(getTerulet(), 2) << endl;
}

/*##SOLUTION##*/

class AlakzatOsTar{
private:
    unsigned meret;
    AlakzatOs **tomb;
public:
    AlakzatOsTar(unsigned alapmeret=10);
    ~AlakzatOsTar();
    unsigned aktualismeret() const;
    void beallit(AlakzatOs *adat, unsigned index);
    void mindentListaz() const;
};

AlakzatOsTar::AlakzatOsTar(unsigned alapmeret):
    meret(alapmeret)
{
    if (alapmeret==0) tomb=nullptr;
    else tomb=new AlakzatOs*[alapmeret];
    for (unsigned i=0; i<meret; i++)
        tomb[i]=nullptr;
}

AlakzatOsTar::~AlakzatOsTar(){
    for (unsigned i=0; i<meret; i++)
        delete tomb[i];
    delete [] tomb;
}

unsigned AlakzatOsTar::aktualismeret() const{
    return meret;
}

void AlakzatOsTar::beallit(AlakzatOs *adat, unsigned index){
    if (index>=meret){
        delete adat;
        return;
    }
    if (tomb[index]) delete tomb[index];
    tomb[index]=adat;
}

void AlakzatOsTar::mindentListaz() const{
    for (unsigned i=0; i<meret; i++){
        cout << "Csucsok szama: " << tomb[i]->csucsok() << endl;
        tomb[i]->keruletEsTerulet();
    }
}

class Kor : public AlakzatOs{
    double sugar;
public:
    Kor(double _sugar):
        sugar(_sugar)
    {}
    ~Kor(){
        cout << "Kor deleted" << endl;
    }
    double getKerulet() const override{
        return 2*sugar*M_PI;
    }
    double getTerulet() const override{
        return sugar*sugar*M_PI;
    }
    unsigned csucsok() const override{
        return 0;
    }
};

class Negyzet : public AlakzatOs{
    double oldalhossz;
public:
    Negyzet(double _oldalhossz):
        oldalhossz(_oldalhossz)
    {}
    ~Negyzet(){
        cout << "Negyzet deleted" << endl;
    }
    double getKerulet() const override{
        return 4*oldalhossz;
    }
    double getTerulet() const override{
        return oldalhossz*oldalhossz;
    }
    unsigned csucsok() const override{
        return 4;
    }
};



int main()
{
    cout << "AlakzatOs osztaly absztrakt? " << (is_abstract<AlakzatOs>::value?"IGEN":"NEM") << endl;

    cout << "Feltoltes" << endl;
    AlakzatOsTar tarolo(10);
    tarolo.beallit(new Kor(2.29), 0);
    tarolo.beallit(new Negyzet(2.63), 1);
    tarolo.beallit(new Kor(3.14), 2);
    tarolo.beallit(new Kor(4.95), 3);
    tarolo.beallit(new Negyzet(2.45), 4);
    tarolo.beallit(new Negyzet(3.77), 5);
    tarolo.beallit(new Kor(2.63), 6);
    tarolo.beallit(new Kor(2.1), 7);
    tarolo.beallit(new Kor(2.39), 8);
    tarolo.beallit(new Negyzet(2.24), 9);

    cout << endl << "Listazas" << endl;
    tarolo.mindentListaz();

    cout << endl << "Felszabaditas" << endl;
    return 0;
}
