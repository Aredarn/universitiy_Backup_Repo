#ifndef VEKTOR_H
#define VEKTOR_H

#include <cmath>

class Vektor
{
	unsigned int darab;
	double *elemek;
public:
	Vektor(unsigned int db);
	Vektor(const Vektor &masik);
	~Vektor();

	unsigned int getDarab() const;
	double getElem(unsigned int index) const;
	void setElem(unsigned int index, double elem);

   //Vektor operator + (const Vektor &jobb);
   Vektor &operator +=(const Vektor &jobb);

   //Megengedi egy adott fgv-nek hogy használja a class privát adattagjait.
   friend Vektor operator+(double bal, const Vektor &jobb);

    //Másoló
   Vektor &operator =(const Vektor &jobb);

   Vektor &operator --();
   Vektor operator --(int);

};

//Vektor osszead(const Vektor &v1, const Vektor &v2);
//Vektor operator +(const Vektor &v1, const Vektor &v2);

Vektor operator+(double bal, const Vektor &jobb);

#endif // VEKTOR_H
