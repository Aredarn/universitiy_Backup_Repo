#include <iostream>
#include <string>
#include <list>
#include <functional>
#include <algorithm>
using namespace std;

struct Versenyzo
{
    string nev;
    string datum;
    int pontszam;
};

//int megszamlal(const list<Versenyzo> &lista, int pont, function<bool (const Versenyzo &)> fetetel)
//{
//    int darab = 0;
//    for(const Versenyzo &v : lista)
//    {
//        if(fetetel(v))
//            ++darab;
//    }
//    return darab;
//}

bool nagyobbMint60(const Versenyzo &v)
{
    return v.pontszam > 60;
}

class predikatum
{
  int pont;
public:
    predikatum(int p):pont(p)
    {}
    bool operator() (const Versenyzo &v) const
    {
        return v.pontszam > pont;
    }
};

int main()
{
    list<Versenyzo> v{
        {"Valaki", "2022-05-06", 40},
        {"Yoda", "2030-03-03", 45},
        {"Sanyi", "2077-03-12", 66},
        {"Laci", "2022-03-03", 30}
    };
    predikatum p1(50);
    cout << "v elso eleme nagyobb e mint p1 pont? " << p1(v.front()) << endl;
//    int db = megszamlal(v,30, nagyobbMint60());

    int db = count_if(v.begin(),v.end(), p1);
    cout << "Mennyi nagyobb van a v ben mint p1 pontja? " << db << endl;

    cout << "adj meg egy erteket";
    int ponts;
    cin >> ponts;
    predikatum p2(ponts);

    db = count_if(v.begin(),v.end(), p2);
    cout << "Mennyi nagyobb van a v ben mint p2 pontja? " <<db << endl;


    //EZEK KÖNNYEBBEN MEGVALÓSITHATÓAK SAJÁT OSZTÁLY NÉLKÜL LAMBDA FGV_EL !!!!!!!!
    cout << "And meg egy hosszt: ";
    int hossz;
    cin >> hossz;
    // [] <-- belső változók megadására
    // () <-- paraméterlista
    // {} <-- funkció

    auto pred = [hossz](const Versenyzo &v)/* -> bool*/{
        return v.nev.length() > hossz;
    };

    db = count_if(v.begin(),v.end(), pred);
    cout << "auto pred lambda alapján csinál db: " << db << endl;


    return 0;
}
