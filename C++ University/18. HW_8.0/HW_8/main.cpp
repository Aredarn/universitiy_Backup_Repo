#include <iostream>
#include <cmath>
using namespace std;

/*##SOLUTION##*/

template <class T, class S> class DuplaTomb{
    T* tomb1 = new T[0];
    S* tomb2 = new S[0];
    int elsomeret =0;
    int masodikmeret=0;
public:
    DuplaTomb<T,S>(){}
    ~DuplaTomb<T,S>(){

        delete[] tomb1;
        delete[] tomb2;
    }



    void ujertek(T val){

        elsomeret++;
        T * uj = new T[elsomeret];
        for (unsigned i=0; i<elsomeret - 1; i++){
            uj[i] = tomb1[i];
        }
        uj[elsomeret - 1] = val;
        delete [] tomb1;
        tomb1 = uj;
    }

    void ujertek(S val){

        masodikmeret++;
        S * uj = new S[masodikmeret];
        for (unsigned i=0; i<masodikmeret - 1; i++){
            uj[i] = tomb2[i];
        }
        uj[masodikmeret - 1] = val;
        delete [] tomb2;
        tomb2 = uj;
    }

    unsigned meret1()
    {
        return elsomeret;
    }

    unsigned masikmeret()
    {
        return masodikmeret;
    }

    T egyikleker(int idx)
    {
        return tomb1[idx];
    }

    S leker2(int idx)
    {
        return tomb2[idx];
    }

};

/*##SOLUTION##*/

int main()
{
    cout << "Feltoltes" << endl;
    DuplaTomb<char, string> tarolo;
    tarolo.ujertek("xd");
    tarolo.ujertek("Heisenberg");
    tarolo.ujertek('4');
    tarolo.ujertek("Bazinga!");
    tarolo.ujertek("alma");
    tarolo.ujertek("alma");
    tarolo.ujertek('a');
    tarolo.ujertek('d');
    tarolo.ujertek('F');
    tarolo.ujertek('a');
    tarolo.ujertek('A');
    tarolo.ujertek('c');
    tarolo.ujertek('0');

    cout << endl << "Listazas" << endl;
    for (unsigned i=0; i<tarolo.meret1(); i++)
        cout << i << " " << tarolo.egyikleker(i) << endl;
    for (unsigned i=0; i<tarolo.masikmeret(); i++)
        cout << i << " " << tarolo.leker2(i) << endl;

    cout << endl << "Felszabaditas" << endl;
    return 0;
}
