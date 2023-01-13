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
    void betoltes();
    void listazSzobak();
    void listazFoglalasok();
    void mindentTorol();
    Foglalas* maxletszam();
    Foglalas *getElement(int id);
    int foglalasokSzama(int id);
    map<Szoba*,list<Foglalas*>> szobakSzerint();
    void szobaFoglaltsag();
    void idorendben();
    list<Szoba* > szabadSzobak(string mettol, string meddig,int ferohelyszam=0);
    void ujFoglalas(string igazolvanySzam, int letszam, string mettol, string meddig, int ejszakak, int szobaId);
    // create costum exception class which shows the szobaId of the error in the what() function
    class SzobaNemLetezik : public exception
    {
        int szobaId;
    public:
        SzobaNemLetezik(int szobaId) : szobaId(szobaId) {}
        const char* what() const noexcept override
        {
            return ("Szoba nem letezik: " + to_string(szobaId)).c_str();
        }
    };
};

#endif // HANDLER_H
