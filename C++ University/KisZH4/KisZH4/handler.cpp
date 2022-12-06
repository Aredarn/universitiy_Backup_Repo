#include "handler.h"

void Handler::csatlakozas(const string &fajl)
{
    dbcon.Connect(fajl.c_str(),"","",SA_SQLite_Client);
}

void Handler::teszt()
{
    SACommand szamol(&dbcon,"SELECT count(id) FROM telepulesek");
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
void Handler::futtatBiztos(function<void()> taszk)
{
    mt19937_64 rgen(12345678);
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
                this_thread::sleep_for(chrono::milliseconds(k));
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
            cout << "Egyeb (nem SAException) tipusu exception!" << endl;
        }
        break;
    }
}



void Handler::beolvas(Lista &lista)
{
    SACommand select(&dbcon,"SELECT * FROM telepulesek ORDER BY nev ASC");
    select.Execute();
    while (select.FetchNext())
    {
        int id;
        string nev;
        Pont koordinatak;
        id = select[1].asLong();
        nev = (string)select[2].asString();
        koordinatak.esz = select[3].asDouble();
        koordinatak.kh = select[4].asDouble();
        Telepules t(id,nev,koordinatak);
        lista.hozzaad(t);
    }
}

Telepules* Handler::leker(int idx)
{
    Telepules* telepul = nullptr;

    SACommand getIndex(&dbcon, "SELECT * FROM telepulesek WHERE id=:1");
    getIndex<<(long)idx;
    getIndex.Execute();
    while(getIndex.FetchNext()) {
        Pont *ujPont = new Pont(getIndex["eszaki_szelesseg"].asDouble(),
        getIndex["keleti_hosszusag"].asDouble());

        Telepules *ujTelep = new Telepules(getIndex["id"].asLong(),
        (string)getIndex["nev"].asString(), *ujPont);

        telepul = ujTelep;
    }

    return telepul;
}


void Handler::torol(double kezd, double veg)
{
    SACommand del(
                &dbcon,
   "DELETE FROM telepulesek WHERE"
    " keleti_hosszusag>:1 AND keleti_hosszusag <:2");

    del << kezd;
    del << veg;

    del.Execute();
}


int Handler::eszakabbra(double szk)
{


    SACommand select_eszak(&dbcon,
    "SELECT eszaki_szelesseg FROM telepulesek WHERE eszaki_szelesseg > :1");
    select_eszak << szk;

    select_eszak.Execute();

    std::vector<double> v;
    while (select_eszak.FetchNext())
        v.push_back(select_eszak["eszaki_szelesseg"].asDouble());

    int darab = v.size();

    return darab;
}


void Handler::modosit(Telepules &telep)
{
    SACommand modositas
    (&dbcon,
     "UPDATE telepulesek "
     "SET nev=:1, "
     "eszaki_szelesseg=:2, "
     "keleti_hosszusag=:3"
     " WHERE id=:4");

    modositas << telep.getNev().c_str() << (double)telep.getEszakiSzelesseg() << (double)telep.getKeletiHosszusag() << (long)telep.getId();
    modositas.Execute();
}

















