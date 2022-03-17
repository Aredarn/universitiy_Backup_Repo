#include <iostream>
#include <string>
using namespace std;

namespace dobozok{

struct Doboz
{
    string nev;
    unsigned szelesseg,magassag,hosszusag;
};


void megjelenit(const Doboz *tomb,const unsigned meret)
{
    for(int i=0;i<meret;i++)
    {
     cout << tomb[i].nev << " ";
     cout << tomb[i].szelesseg << " ";
     cout << tomb[i].magassag << " ";
     cout << tomb[i].hosszusag << endl;
    }
}

    void felszinTerfogat(Doboz &d)
    {
        int terfogat = d.hosszusag*d.magassag*d.szelesseg;
        cout <<terfogat;
    }


    void megnovel(Doboz *tomb, unsigned meret, unsigned novel)
    {
        Doboz *uj = new Doboz[meret+novel];
        for(int i=0;i<meret;i++)
        {
            uj[i]=tomb[i];
        }
        delete [] tomb;
        tomb=uj;
        meret+=novel;

    }

    void forgat(Doboz &d)
    {
        unsigned cs=d.szelesseg;
        d.szelesseg = d.magassag;
        d.magassag = d.hosszusag;
        d.hosszusag = cs;
    }

    unsigned belefer(const Doboz &d,const Doboz &d2)
    {
        //...
    }

    unsigned belefer(const Doboz &d, cosnt Doboz &d2, const Doboz &d3, int h)
    {
        //...
    }
}


using namespace dobozok;

int main()
{
    cout << "Mennyi doboz legyen? ";
    int meret;
    cin >> meret;
    Doboz *tomb = new Doboz[meret];


    for(int i=0;i<meret;i++)
    {
        cout << i+1 << ". doboz" <<endl;

        cin >> tomb[i].nev;
        cin >> tomb[i].szelesseg;
        cin >> tomb[i].magassag;
        cin >> tomb[i].hosszusag;
    }

    felszinTerfogat(tomb[0]);

    delete [] tomb;
    return 0;
}
