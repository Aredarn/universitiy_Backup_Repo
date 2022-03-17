#include <iostream>
#include <string>
using namespace std;

namespace tantargyak
{
    struct orak
    {
        string Targy;
        unsigned JegyekSzama;
        int *Jegyek;
    };


    void beker( const orak &d, int e)
    {
        cout <<"Targy neve:  " << d[e].Targy <<endl;
        cout << "Jegyek szama: " << orak[e].JegyekSzama << endl;
        cout << "Jegyek: " << orak[e].Jegyek;
    }

}

using namespace tantargyak;

int main()
{
    orak *tomb = new orak[3];

    for(int i=0;i<3;i++)
    {
        cout <<"Kerem a " << i+1 <<". targy nevet";
        cin >> tomb[i].Targy;
        cout << endl;
        cout << "Kerem a " << i+1 << ". tantargy jegyeinek szamat ";
        cin >> tomb[i].JegyekSzama;
        cout << endl;
        tomb[i].Jegyek = new int[tomb[i].JegyekSzama];

        cout << "Kerem a " << i+1 << ". tantargyhoz tartozo jegyeket";

        for(int j=0;j<tomb[i].JegyekSzama;j++)
        {
            cout << endl;
            cout << "Kerem a " << j+1<<". jegyet";
            cin >> tomb[i].Jegyek[j];
        }


    }
    return 0;
}
