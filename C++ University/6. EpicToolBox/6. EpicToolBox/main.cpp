#include <iostream>
#include <EpicToolBox.h>

using namespace std;
using namespace Tarolo;


int kisebbTarolo(EpicToolBox elso, EpicToolBox masodik)
{
    if(elso.meret>masodik.meret)
        return 1;
    if(elso.meret<masodik.meret)
        return -1;
    else
        return 0;

}

int main()
{

    EpicToolBox sz4;
    sz4.kiir();
    cout << endl;
    EpicToolBox sz2(75);
    //KIIR FGV
    sz2.kiir();

    //HOZZAAD FGV
    cout << endl << "Adj meg egy uj szamot a tombhoz: ";
    int ujszam;
    cin >> ujszam;
    sz2.hozzaad(ujszam);
    cout <<endl;
    sz2.kiir();

    //ATLAG SZAMITAS
    cout << endl;
    cout << sz2.atlag() << " az atlag";

    //Melyik kisebb:
    cout << endl << kisebbTarolo(sz4,sz2);

    return 0;
}
