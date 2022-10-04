#include <iostream>
#include <string>
#include <exception>
using namespace std;

#include "container.h"

int main()
{
	cout << "main() eleje!" << endl << endl;

//	// a namespace-es feladathoz:
    using MyNamespace::Container;

    {
        cout << "contains()" << " teszt" << endl;
        Container<string> szavak;
        szavak.addObject("egy");
        szavak.addObject("ketto");
        szavak.addObject("harom");
        szavak.addObject("negy");
        for (string szo : {"egy","ket","ha","negy"})
        {
            bool c = szavak.contains(szo);
            cout << szo << " -> " << c << endl;
        }
        cout << endl;
        // egy -> 1
        // ket -> 0
        // ha -> 0
        // negy -> 1
    }

    {
        cout << "addUnique()" << " teszt" << endl;
        Container<unsigned> maradekok;
        for (int i=0;i<1000;i++)
        {
            maradekok.addUnique((7*i)%10);
        }
        for (int i=0;i<maradekok.getSize();i++)
        {
            cout << maradekok[i] << " ";
        }
        cout << endl << endl;
        // 0 7 4 1 8 5 2 9 6 3
    }

    {
        cout << "setObject() normal mukodes" << " teszt" << endl;
        Container<char> karakterek;
        karakterek.addObject('k');
        karakterek.addObject('a');
        karakterek.addObject('r');
        karakterek.setObject(0,'f');
        karakterek.setObject(2,'l');
        for (int i=0;i<karakterek.getSize();i++)
        {
            cout << karakterek[i] << flush;
        }
        cout << endl << endl;
        // fal
    }

    {
        cout << "setObject() exception" << " teszt" << endl;
        Container<int> tomb;
        tomb.addObject(100);
        tomb.addObject(200);
        tomb.addObject(300);
        try {
            tomb.setObject(0,400);
            tomb.setObject(1,500);
            tomb.setObject(2,600);
            cout << "Eddig jo..." << endl;
            tomb.setObject(168,700);
            cout << "Idaig nem szabad eljutni!" << endl;
        }
        catch (const exception& exc)
        {
            cout << "Exception (standard): " << exc.what() << endl;
        }
        catch (...)
        {
            cout << "Exception (barmilyen)!" << endl;
        }
        cout << endl;
        // Eddig jo...
        // Exception (standard): 168
    }

    {
        cout << "repeat()" << " teszt" << endl;
        Container<unsigned long long int> code;
        code.addObject(1);
        code.addObject(0);
        code.repeat();
        code.repeat();
        code.repeat();
        cout << code.getSize() << ": " << flush;
        for (int i=0;i<code.getSize();i++)
        {
            cout << code[i];
        }
        cout << endl << endl;
        // 16: 1010101010101010
    }

	cout << "main() vege!" << endl;
	return 0;
}
