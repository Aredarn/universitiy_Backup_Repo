#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Logolo
{
public:
    static string fileneve;
    static void setLogNev(string file);
    static void logbaIr(string gs,string neve, string tos);
};
string Logolo::fileneve;

void Logolo::setLogNev(string file)
{
     Logolo::fileneve = file;
}

void Logolo::logbaIr(string gs, string neve, string tos)
{
    ofstream file;
    file.open(Logolo::fileneve, ios_base::app);

    file << neve << " adattag ";
    if(gs == "get")
    {
        file << "lekerese (ertek: " << tos << ")"<<endl;
    }
    else if(gs == "set")
    {
        file << "beallitasa " << tos << " ertekre" << endl;
    }
    file.close();
}

class Munkas{
    int mikorKezdett;
    int ertekeles;
public:
    Munkas();
    Munkas(int _mikorKezdett, int _ertekeles);
    int getMikorKezdett() const;
    void setMikorKezdett (int _mikorKezdett);
    int getErtekeles() const;
    void setErtekeles (int _ertekeles);
};

Munkas::Munkas():
    mikorKezdett(0),
    ertekeles(0)
{}

Munkas::Munkas(int _mikorKezdett, int _ertekeles):
    mikorKezdett(_mikorKezdett),
    ertekeles(_ertekeles)
{}

int Munkas::getMikorKezdett() const{
    Logolo::logbaIr("get", "mikorKezdett", to_string(mikorKezdett));
    return mikorKezdett;
}

void Munkas::setMikorKezdett (int _mikorKezdett){
    Logolo::logbaIr("set", "mikorKezdett", to_string(_mikorKezdett));
    mikorKezdett=_mikorKezdett;
}

int Munkas::getErtekeles() const{
    Logolo::logbaIr("get", "ertekeles", to_string(ertekeles));
    return ertekeles;
}

void Munkas::setErtekeles (int _ertekeles){
    Logolo::logbaIr("set", "ertekeles", to_string(_ertekeles));
    ertekeles=_ertekeles;
}


int main()
{
    // Log fájl ürítése, biztos ami biztos
    {ofstream urites("log1.txt");}
    // Fájlnév beállítás
    Logolo::setLogNev("log1.txt");

    cout << "Feltoltes" << endl;
    Munkas tomb[4];
    tomb[2].setMikorKezdett(1980);
    tomb[0].setMikorKezdett(2013);
    tomb[3].setMikorKezdett(1997);
    tomb[1].setMikorKezdett(2020);
    tomb[1].setErtekeles(31);
    tomb[3].setErtekeles(40);
    tomb[2].setErtekeles(14);
    tomb[0].setErtekeles(81);

    cout << endl << "Listazas" << endl;
    cout << tomb[0].getMikorKezdett() << " ";
    cout << tomb[0].getErtekeles() << endl;
    cout << tomb[3].getMikorKezdett() << " ";
    cout << tomb[3].getErtekeles() << endl;
    cout << tomb[2].getMikorKezdett() << " ";
    cout << tomb[2].getErtekeles() << endl;
    cout << tomb[1].getMikorKezdett() << " ";
    cout << tomb[1].getErtekeles() << endl;

    cout << endl << "Log fajl tartalma:" << endl;
    ifstream testlog("log1.txt");
    cout << testlog.rdbuf();

    cout << endl << "Vege" << endl;
    return 0;
}
