#ifndef HANDLER_H
#define HANDLER_H

#include <SQLAPI.h>

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <functional>
#include <exception>

#include "szoba.h"
#include "foglalas.h"

class Handler
{
    SAConnection dbcon;
	list<Szoba*> szobak;
	list<Foglalas*> foglalasok;
public:
    Handler()=default;
	~Handler();
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();

    // ezzel nincs teendo!
    // lefuttat egy parancsot, a kiveteleket kezeli
    // 'Trial version exception' eseten ujra probalkozik
    static void futtatBiztos (std::function<void(void)> taszk);

	// ide johetnek a ZH feladatok megoldasai

    void beolvas();

    void szobaListazas() const;
    void foglalasListazas() const;
    void listakTorol();
    int nagyLetszamu();
    int osszesEjszakak(string szigszam);
    list<string> osszesFoglalo();
    map<string,list<Foglalas*>> szemelySzerint();
    void foglalasokSzobahoz(int id);
    list<string> foglaltValamikorra(string kez,string veg);
};

#endif // HANDLER_H
