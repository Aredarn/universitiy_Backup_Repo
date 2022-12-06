#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "telepules.h"
#include "lista.h"
#include "handler.h"

using namespace std;

#define PART1
#define PART2
#define PART3
#define PART4
#define PART5

int main()
{
    cout << "main() eleje!" << endl << endl;

    const string db_hasznalt = "telepulesek.sqlite";
    const string db_eredeti = "tzh-poziciok-eredeti.sqlite";
    {
        ifstream be(db_eredeti, ios::binary);
        if (!be.is_open())
        {
            cout << "Hiba! Nem sikerult megnyitni: " << db_eredeti << endl;
            cout << "(Jo helyre lett masolva a fajl?)" << endl << endl;
            return 1;
        }
        ofstream ki(db_hasznalt, ios::binary);
        if (!ki.is_open())
        {
            cout << "Hiba! Nem sikerult irasra megnyitni: " << db_hasznalt << endl;
            cout << "Az adatbazis igy nem all keszen a munkara." << endl << endl;
            return 1;
        }
        ki << be.rdbuf();
        be.close();
        ki.close();
    }

    Handler h;
    {
        cout << "Adatbazis teszt" << endl << endl;
        Handler::futtatBiztos([&]() {
            h.csatlakozas(db_hasznalt);
            h.teszt();
            });
    }
    // (...egyeb szoveg...)
    // Rekordok szama: 21
    // Jo munkat!
    
#ifdef PART1
    {
        cout << "1. feladat - beolvas() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            Lista proba;
            h.beolvas(proba);
            proba.kiir();
            cout << endl;
        });
    }
    //Tartalom(21 db) :
    //30526 Alsoors N46.9883 E17.9771
    //5838 Balatonalmadi N47.0303 E18.0156
    //2219 Balatonfuzfo N47.062 E18.041
    //14173 Band N47.122 E17.7796
    //33941 Epleny N47.2078 E17.9164
    //24369 Felsoors N47.0151 E17.9526
    //15361 Hajmasker N47.1445 E18.0143
    //25566 Harskut N47.1863 E17.8148
    //23658 Herend N47.1328 E17.7523
    //20756 Hidegkut N47.0012 E17.8285
    //5421 Kiralyszentistvan N47.1093 E18.0437
    //4552 Liter N47.0999 E18.0076
    //5564 Lovas N46.9934 E17.9588
    //32212 Marko N47.1211 E17.8144
    //2194 Nemesvamos N47.0549 E17.8718
    //17011 Paloznak N46.9833 E17.9409
    //3601 Soly N47.1299 E18.0321
    //16267 Szentkiralyszabadja N47.0565 E17.9705
    //11767 Veszprem N47.0934 E17.908
    //21430 Veszpremfajsz N47.0364 E17.8957
    //15705 Vilonya N47.1102 E18.0613
#endif // PART1

#ifdef PART2
    {
        cout << "2. feladat - leker() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            Telepules* t = h.leker(11767);
            cout << "Telepules (id = 11767):" << endl;
            if (t != nullptr) {
                cout << *t << endl;
                delete t;
            }
            else {
                cout << "Nem talalhato!" << endl;
            }
            t = h.leker(100);
            cout << "Telepules (id = 100):" << endl;
            if (t != nullptr) {
                cout << t << endl;
                delete t;
            }
            else {
                cout << "Nem talalhato!" << endl;
            }
            cout << endl;
        });
    }
    //Telepules(id = 11767) :
    //11767 Veszprem N47.0934 E17.908
    //Telepules(id = 100) :
    //Nem talalhato!
#endif // PART2

#ifdef PART3
    {
        cout << "3. feladat - modosit() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            Telepules t(4552, "LITER", Pont(50.000000, 10.000000));
            h.modosit(t);
            Lista proba;
            h.beolvas(proba);
            proba.kiir();
            cout << "(Liter modositott adatokkal szerepel)" << endl << endl;
        });
    }
    //Tartalom(21 db) :
    //30526 Alsoors N46.9883 E17.9771
    //5838 Balatonalmadi N47.0303 E18.0156
    //2219 Balatonfuzfo N47.062 E18.041
    //14173 Band N47.122 E17.7796
    //33941 Epleny N47.2078 E17.9164
    //24369 Felsoors N47.0151 E17.9526
    //15361 Hajmasker N47.1445 E18.0143
    //25566 Harskut N47.1863 E17.8148
    //23658 Herend N47.1328 E17.7523
    //20756 Hidegkut N47.0012 E17.8285
    //5421 Kiralyszentistvan N47.1093 E18.0437
    //4552 LITER N50 E10
    //5564 Lovas N46.9934 E17.9588
    //32212 Marko N47.1211 E17.8144
    //2194 Nemesvamos N47.0549 E17.8718
    //17011 Paloznak N46.9833 E17.9409
    //3601 Soly N47.1299 E18.0321
    //16267 Szentkiralyszabadja N47.0565 E17.9705
    //11767 Veszprem N47.0934 E17.908
    //21430 Veszpremfajsz N47.0364 E17.8957
    //15705 Vilonya N47.1102 E18.0613
    //(Liter modositott adatokkal szerepel)
#endif // PART3

#ifdef PART4
    {
        cout << "4. feladat - torol() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.torol(17.9, 18.0);
            Lista proba;
            h.beolvas(proba);
            proba.kiir();
            cout << endl;
        });
    }
    //Tartalom(14 db) :
    //5838 Balatonalmadi N47.0303 E18.0156
    //2219 Balatonfuzfo N47.062 E18.041
    //14173 Band N47.122 E17.7796
    //15361 Hajmasker N47.1445 E18.0143
    //25566 Harskut N47.1863 E17.8148
    //23658 Herend N47.1328 E17.7523
    //20756 Hidegkut N47.0012 E17.8285
    //5421 Kiralyszentistvan N47.1093 E18.0437
    //4552 LITER N50 E10
    //32212 Marko N47.1211 E17.8144
    //2194 Nemesvamos N47.0549 E17.8718
    //3601 Soly N47.1299 E18.0321
    //21430 Veszpremfajsz N47.0364 E17.8957
    //15705 Vilonya N47.1102 E18.0613
#endif // PART4

#ifdef PART5
    {
        cout << "5. feladat - eszakabbra() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            int db = h.eszakabbra(47.1);
            cout << "47.1 foknal eszakabbra: " << db << endl;
            db = h.eszakabbra(50);
            cout << "50 foknal eszakabbra: " << db << endl;
            cout << endl;
        });
    }
    //47.1 foknal eszakabbra : 9
    //50 foknal eszakabbra : 0
#endif // PART5

    cout << "main() vege!" << endl;
    return 0;
}
