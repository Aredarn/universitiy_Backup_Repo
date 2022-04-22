#include "vektor.h"

Vektor::Vektor(unsigned int db):
	darab(db)
{
	elemek=new double[darab];
}

Vektor::Vektor(const Vektor &masik):
	darab(masik.darab)
{
	elemek=new double[darab];
	for (unsigned int i=0; i<darab; i++)
		elemek[i]=masik.elemek[i];
}

Vektor::~Vektor()
{
	delete [] elemek;
}

unsigned int Vektor::getDarab() const
{
	return darab;
}

double Vektor::getElem(unsigned int index) const
{
	return elemek[index];
}

void Vektor::setElem(unsigned int index, double elem)
{
	elemek[index]=elem;
}


//Vektor operator +(const Vektor &v1, const Vektor &v2)
//{
//    Vektor eredmeny(v1.getDarab());

//    for(unsigned i=0;i<v1.getDarab();i++)
//    {
//        double tmp = v1.getElem(i) + v2.getElem(i);
//        eredmeny.setElem(i,tmp);
//    }

//    return eredmeny;

//}

Vektor &Vektor::operator+=(const Vektor &jobb)
{

    for(unsigned i=0;i<this->darab;i++)
    {
        this->elemek[i] = this->elemek[i] + jobb.elemek[i];
    }
    return *this;
}


Vektor operator+(double bal, const Vektor &jobb)
{
    Vektor eredmeny(jobb.darab);
    for(unsigned i=0;i<jobb.darab;i++)
    {
        eredmeny.elemek[i] = bal + jobb.elemek[i];
    }
    return eredmeny;
}


Vektor &Vektor::operator =(const Vektor &jobb)
{
    if(this == &jobb)
        return *this;


    if(this->darab!=jobb.darab)
    {
       delete [] this->elemek;
       this->darab = jobb.darab;
       this->elemek = new double[this->darab];
    }
    for(unsigned i=0;i<jobb.darab;i++)
    {
        this->elemek[i] = jobb.elemek[i];
    }

    return *this;
}



Vektor &Vektor::operator--()
{
    for(unsigned i=0; i<darab;i++)
    {
        --elemek[i];
    }
    return *this;
}

Vektor Vektor::operator --(int)
{
    Vektor masolat(*this);

    for(unsigned i=0; i<darab;i++)
    {
        --elemek[i];
    }
    return masolat;
}
