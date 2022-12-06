#ifndef HANDLER_H
#define HANDLER_H

#include <iostream>
#include <list>
#include <functional>

#include "telepules.h"
#include "lista.h"

#ifdef _W64 || _WIN32
#define WIN32_LEAN_AND_MEAN
#endif // _W64 || _WIN32

#include <SQLAPI.h>

using namespace std;

class Handler
{
    SAConnection dbcon;
public:
    Handler()=default;
    void csatlakozas (const string& sqlite_fajl);
    void teszt ();


    // ezzel nincs teendo!
    // lefuttat egy parancsot, a kiveteleket kezeli
    // 'Trial version exception' eseten ujra probalkozik
    static void futtatBiztos (function<void(void)> taszk);

    // ide johetnek a ZH feladatok megoldasai
    
    void beolvas(Lista& lista);
    Telepules* leker(int idx);
    void torol(double kezd, double veg);
    int eszakabbra(double szk);
    void modosit(Telepules &telep);

};

#endif // HANDLER_H
