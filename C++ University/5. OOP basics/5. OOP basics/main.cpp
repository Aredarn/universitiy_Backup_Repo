#include <iostream>
#include <Szamok.h>


using namespace std;


void kiir(const Tarolo::Szamok &sz)
{
    for(unsigned i=0;i<sz.darabLeker();i++)
    {
        cout << sz.ertekLeker(i) << ", ";
    }
    cout << endl;
}

int main()
{
    //Konstruktorok létrehozása:
    Tarolo::Szamok szl(5);
    Tarolo::Szamok sz2(9,3.4);


    cout<< szl.darabLeker() << endl;
    cout << sz2.darabLeker() << endl;

    szl.ertekBeallit(4, 424.22);


    kiir(szl);
    kiir(sz2);


    return 0;
}
