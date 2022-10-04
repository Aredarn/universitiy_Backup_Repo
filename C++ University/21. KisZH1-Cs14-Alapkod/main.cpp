#include <iostream>
#include <string>

#include "MultiParameter.h"

using namespace std;
using namespace util;

int main()
{
    // 1. feladat
    {
        cout << "1. feladat: " << endl;

       MultiParameter<string, int> defaultMulti;

        double d = 2.5;
        bool b = true;
        MultiParameter<double, bool> multi(&d, &b);
    } // nincs kimenet

    cout << endl << endl;

    // 2. feladat
    {
        cout << "2. feladat: " << endl;

        MultiParameter<string, int> defaultMulti;
        cout << defaultMulti.getFirst() << " | " << defaultMulti.getSecond() << endl; //  | 0 (az első üres string)

        double d = 2.5;
        bool b = true;
        MultiParameter<double, bool> multi(&d, &b);
        cout << multi.getFirst() << " | " << multi.getSecond() << endl; // 2.5 | 1
    }

    cout << endl << endl;

    // 3. feladat
    {
       cout << "3. feladat: " << endl;

        string n1 = "Kakszi Lajos";
        string n2 = "Degec Imre";
        MultiParameter<string, string> multi1 = MultiParameter<string, string>::make(&n1, &n2);
        cout << multi1.getFirst() << " | " << multi1.getSecond() << endl; // Kakszi Lajos | Degec Imre

        int i = 11;
        short s = 22;
        MultiParameter<int, short> multi2 = MultiParameter<int, short>::make(&i, &s);
        cout << multi2.getFirst() << " | " << multi2.getSecond() << endl; // 11 | 22
    }

    cout << endl << endl;

    // 4. feladat
    {
        cout << "4. feladat: " << endl;

        // TODO: kivételkezelés
        string n1 = "Kakszi Lajos";
        MultiParameter<string, string> multi1 = MultiParameter<string, string>::make(&n1, nullptr);
        cout << multi1.getFirst() << " | " << multi1.getSecond() << endl;


        // TODO: kivételkezelés
        double d = 4.56;
        MultiParameter<double, double> multi2 = MultiParameter<double, double>::make(nullptr, nullptr);
        cout << multi2.getFirst() << " | " << multi2.getSecond() << endl;

        // TODO: kivételkezelés
        int i = 123;
        MultiParameter<string, int> multi3 = MultiParameter<string, int>::make(nullptr, &i);
        cout << multi3.getFirst() << " | " << multi3.getSecond() << endl;

    }

    return 0;
}
