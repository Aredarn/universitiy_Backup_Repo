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

void Handler::beolvas()
{
    listakTorol();
    SACommand szobak1(&dbcon,"SELECT * FROM szobak");
    szobak1.Execute();
    while (szobak1.FetchNext())
    {
        int id = szobak1["id"].asLong();
        int emelet = szobak1["emelet"].asLong();
        int ajto = szobak1["ajto"].asLong();
        int ferohely = szobak1["ferohelyek"].asLong();

        auto Y = new Szoba(id,emelet,ajto,ferohely);
        szobak.push_back(Y);
    }


    SACommand foglalas(&dbcon,"SELECT * FROM foglalasok");
    foglalas.Execute();
    while (foglalas.FetchNext())
    {
        int id = foglalas["id"].asLong();
        string igazolvanySzam = (string)foglalas["igazolvanySzam"].asString();
        int letszamx = foglalas["letszam"].asLong();
        string mettol = (string)foglalas["mettol"].asString();
        string meddig = (string)foglalas["meddig"].asString();
        int ejszaka = foglalas["ejszakak"].asLong();

        int szobaID = foglalas["szobaId"].asLong();

        auto it = find_if(szobak.begin(),szobak.end(),
                       [&](Szoba* s){ return s->getId() == szobaID;}
        );
        auto X = new  Foglalas(id,igazolvanySzam,letszamx,mettol,meddig,ejszaka);
        if(it != szobak.end())
            X->setSzoba(*it);


        foglalasok.push_back(X);

    }
}

void Handler::szobaListazas() const
{
   cout << "Szobak: " << endl;
   for(auto& szoba : szobak)
   {
        cout << " ID: " << szoba->getId() << " emelet: " << szoba->getEmelet() << " ferohelyek: " << szoba->getFerohelyek() << " emelet: " << szoba->getEmelet()<< endl;
   }
}

void Handler::foglalasListazas() const
{
   cout << "Foglalasok: " << endl;
   for(auto& foglalas: foglalasok)
   {
       cout << " ID: " << foglalas->getId() << " ejszakak: " << foglalas->getEjszakak() << " igszam: " << foglalas->getIgazolvanySzam()
            << " letszam:  " << foglalas->getLetszam() << " mettol: " << foglalas->getMettol() << " meddig: " << foglalas->getMeddig()
            << " szoba: " << foglalas->getSzoba()->getId() << endl;
   }
}

void Handler::listakTorol()
{
    foglalasok.clear();
    szobak.clear();
}

int Handler::nagyLetszamu()
{
    return count_if(foglalasok.begin(),foglalasok.end(),[](Foglalas* f){
        if(f->getLetszam() >= 5)
        return f;
    });
}

int Handler::osszesEjszakak(string szigszam)
{

    return accumulate(foglalasok.begin(),foglalasok.end(),0,[&](int sum,Foglalas* f){
        return (f->getIgazolvanySzam() == szigszam) ? sum + f->getEjszakak() : sum;
    });
}

list<string> Handler::osszesFoglalo()
{
    list<string> foglalok;
    transform(foglalasok.begin(),foglalasok.end(),back_inserter(foglalok), [](Foglalas* f){
            return f->getIgazolvanySzam();

    });
    foglalok.sort();
    foglalok.unique();
    return foglalok;
}

map<string, list<Foglalas *> > Handler::szemelySzerint()
{

    map<string,list<Foglalas*>> eredmeny;

    for (auto& fog : foglalasok)
    {
       eredmeny[fog->getIgazolvanySzam()].push_back(fog);
    }

   return eredmeny;

}

void Handler::foglalasokSzobahoz(int id)
{

    std::list<Foglalas*> idFoglalasok;
    std::copy_if(foglalasok.begin(), foglalasok.end(), std::back_inserter(idFoglalasok), [&id](Foglalas* f){ return f->getSzoba()->getId() == id; });

    idFoglalasok.sort([](Foglalas *f, Foglalas *f2)
    {
        if(f->getMettol() == f2->getMettol())
            return f->getMeddig() < f2->getMeddig();
       return f->getMettol() < f2->getMettol();
    });

    cout << "Szoba: (" << id << ")." << endl;
    for(auto foglalas : idFoglalasok)
    {
       cout <<"  ("<< foglalas->getId() <<")"<< foglalas->getMeddig() << "" << endl;
    }
}

list<string> Handler::foglaltValamikorra(string kez, string veg)
{
    list<string> osszesID;
    list<Foglalas*> fogl;
    copy_if(foglalasok.begin(),foglalasok.end(),back_inserter(fogl),[&kez,&veg](Foglalas *foglalas)
    {
         return kez >= foglalas->getMettol() || veg <= foglalas->getMeddig();
    });

    transform(fogl.begin(),fogl.end(),back_inserter(osszesID),[](Foglalas *foglalas){
       return foglalas->getIgazolvanySzam();
    });

    osszesID.sort();
    osszesID.unique();
    return osszesID;
}







