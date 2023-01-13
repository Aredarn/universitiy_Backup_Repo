#include "handler.h"
#include <algorithm>
#include <numeric>

Handler::~Handler()
{
	for (Szoba *sz : szobak)
		delete sz;
	for (Foglalas *f : foglalasok)
		delete f;
}

void Handler::csatlakozas(const string &fajl)
{
    dbcon.Connect(fajl.c_str(),"","",SA_SQLite_Client);
}

void Handler::teszt()
{
	SACommand szamol(&dbcon,"SELECT count(id) FROM szobak");
    szamol.Execute();
    szamol.FetchNext();
    int cnt = szamol[1].asLong();
    cout << "Rekordok szama: " << cnt << endl;
    cout << "Jo munkat!" << endl << endl;
}

// ezzel nincs teendo!
// lefuttat egy parancsot, a kiveteleket kezeli
// 'Trial version exception' eseten ujra probalkozik
#include <thread>
#include <chrono>
#include <random>
void Handler::futtatBiztos(std::function<void()> taszk)
{
    std::mt19937_64 rgen(12345678);
    while (true)
    {
        try {
            taszk();
        }
        catch (const SAException& exc)
        {
            string msg = exc.ErrText().GetMultiByteChars();
            if (msg.find("Trial version exception") != string::npos)
            {
                cout << "'Trial version exception' hiba tortent!" << endl;
                int k = 1000+rgen()%200;
                cout << "Ujraprobalkozas " << k << " ms mulva..." << endl;
                std::this_thread::sleep_for(std::chrono::milliseconds(k));
                continue;
            }
            else
            {
                cout << "SAException:" << endl;
                cout << msg << endl;
            }
		}
        catch (...)
        {
			cout << "Egyeb (nem SAException) exception!" << endl;
        }
        break;
    }
}

void Handler::betoltes()
{
    mindentTorol();
    SACommand szobaLoad(&dbcon,("SELECT * FROM szobak"));
    szobaLoad.Execute();
    while(szobaLoad.FetchNext()){
        szobak.push_back(new Szoba(szobaLoad[1].asLong(),szobaLoad[2].asLong(),szobaLoad[3].asLong(),szobaLoad[4].asLong()));
    }
    SACommand foglalasLoad(&dbcon,("SELECT * FROM foglalasok"));
    foglalasLoad.Execute();

    while(foglalasLoad.FetchNext()){
            Foglalas *f = new Foglalas(foglalasLoad[1].asLong(),foglalasLoad[2].asString().GetMultiByteChars(),
                    foglalasLoad[3].asLong(),foglalasLoad[4].asString().GetMultiByteChars(),foglalasLoad[5].asString().GetMultiByteChars(),
                    foglalasLoad[6].asLong());
            foglalasok.push_back(f);
            for(Szoba *sz : szobak){
                if(sz->getId() == foglalasLoad[7].asLong()){
                    f->setSzoba(sz);
                    break;
                }
            }
        }
}

void Handler::listazSzobak() {
    cout << "Szobak listazasa:" << endl;
//		  (1) 0. emelet, 1. ajto, 5 ferohely
    for_each(szobak.begin(),szobak.end(),[](Szoba* sz){
        cout << "(" << sz->getId() << ") " << sz->getEmelet() << ". emelet" << sz->getAjto() << ". ajto " <<
                sz->getFerohelyek() << " ferohely"<< endl;
    });
}

void Handler::listazFoglalasok() {
    cout << "Foglalasok listazasa:" << endl;
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
    for_each(foglalasok.begin(),foglalasok.end(),[](Foglalas* f){
        cout << "(" << f->getId() << ") foglalo: " << f->getIgazolvanySzam() << ", idotartam:" << f->getMettol() << " - " << f->getMeddig()
             << ", letszam: " << f->getLetszam() << ", szobaszam: " << f->getSzoba()->getId() << endl;
    });
}

void Handler::mindentTorol() {
    foglalasok.clear();
    szobak.clear();
}

Foglalas *Handler::maxletszam()
{
    return *max_element(foglalasok.begin(),foglalasok.end(),[](Foglalas* f1, Foglalas* f2){
         return f1->getLetszam() < f2->getLetszam();
    });

}

int Handler::foglalasokSzama(int id) {
    return count_if(foglalasok.begin(),foglalasok.end(),[id](Foglalas* f){
        return f->getSzoba()->getId() == id;
    });
}



// TODO
void Handler::szobaFoglaltsag() {
    for_each(szobak.begin(),szobak.end(),[this](Szoba* sz){
        int sum = 0;
        for_each(foglalasok.begin(),foglalasok.end(),[&sum,sz](Foglalas* f){
            if(f->getSzoba()->getId() == sz->getId()){
                sum += f->getEjszakak();
            }
        });
        cout << sz->getId() << " szobaszam: " << sum << " ejszaka" << endl;
    });
}

map<Szoba *, list<Foglalas *>> Handler::szobakSzerint() {
    map<Szoba *, list<Foglalas *>> m;
    for_each(foglalasok.begin(),foglalasok.end(),[&m](Foglalas* f){
        m[f->getSzoba()].push_back(f);
    });
    return m;
}

void Handler::idorendben() {
    list<Foglalas*> sortedFoglalasok(foglalasok);
    sortedFoglalasok.sort([](Foglalas* f1, Foglalas* f2){
        if(f1->getMettol() == f2->getMettol()){
            return f1->getMeddig() < f2->getMeddig();
        }
        return f1->getMettol() < f2->getMettol();
    });
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
    for_each(sortedFoglalasok.begin(),sortedFoglalasok.end(),[](Foglalas* f){
        cout << "(" << f->getId() << ") foglalo: " << f->getIgazolvanySzam() << ", idotartam:" << f->getMettol() << " - " << f->getMeddig()
             << ", letszam: " << f->getLetszam() << ", szobaszam: " << f->getSzoba()->getId() << endl;
    });
}

list<Szoba*> Handler::szabadSzobak(string mettol, string meddig, int ferohelyszam)
{
    list<Szoba*> freeRooms;
    for_each(szobak.begin(),szobak.end(),[&freeRooms,mettol,meddig,ferohelyszam, this](Szoba* sz){
        if(sz->getFerohelyek() >= ferohelyszam){
            bool found = false;
            for_each(foglalasok.begin(),foglalasok.end(),[&found,sz,mettol,meddig](Foglalas* f){
                if(f->getSzoba()->getId() == sz->getId() &&
                   (f->getMettol() < meddig && f->getMeddig() > mettol)){
                    found = true;
                }
            });
            if(!found){
                freeRooms.push_back(sz);
            }
        }
    });
    return freeRooms;
}

void Handler::ujFoglalas(string igazolvanySzam, int letszam, string mettol, string meddig, int ejszakak, int szobaId) {
try{
    if(count_if(szobak.begin(),szobak.end(),[szobaId](Szoba* sz){
        return sz->getId() == szobaId;
    }) > 0){
        SACommand insertFoglalas(&dbcon, "INSERT INTO foglalasok (igazolvanySzam, letszam, mettol, meddig, ejszakak, szobaId) VALUES (:1, :2, :3, :4, :5, :6)");
        insertFoglalas << igazolvanySzam.c_str() << (long)letszam << mettol.c_str() << meddig.c_str() << (long)ejszakak << (long)szobaId;
        insertFoglalas.Execute();
    } else {
        throw SzobaNemLetezik(szobaId);
    }} catch (SzobaNemLetezik &e) {
        cout << e.what() << endl;
    }
}

