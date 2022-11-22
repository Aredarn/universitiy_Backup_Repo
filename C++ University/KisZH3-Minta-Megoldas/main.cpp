#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

#include "szemely.h"

string getSzoveg1 ();
vector<string> getJelszavak2 ();
list<double> getMereslista3 ();
vector<Szemely> getSzemelyek4 ();
list<Szemely> getCsoport5 ();
vector<Szemely> getAlkalmazottak6 ();
vector<bool> getSzuletesnap6 ();
map<Szemely,unsigned> getVaroterem7 ();

int main()
{
    cout << "main() eleje!" << endl << endl;

    {
        cout << "1. feladat" << endl << endl;
        map<char,int> hisztogram;
        //// 1. feladat --- MEGIRANDO RESZ ELEJE
        auto kiirTop = [&hisztogram](int min)
        {
            for(auto it : hisztogram)
            {
                if(it.second >= min)
                    cout << it.first;
            }
        };// kiirTop lambda ide
        //// 1. feladat --- MEGIRANDO RESZ VEGE
        for (char c : getSzoveg1())
            hisztogram[c]++;
        for (int min_elofordulasszam : {3,5,7})
        {
            cout << "Minimum " << min_elofordulasszam << "x:";
            kiirTop(min_elofordulasszam);
            cout << endl;
        }
        cout << endl;
    }
    // Minimum 3x: aeiklmnotyz
    // Minimum 5x: aelmn
    // Minimum 7x: eln

    {
        cout << "2. feladat" << endl << endl;
        auto erosJelszo = [&](const string& j)->bool{
            if (j.size()<8) return false; // legalabb 8 karakteres
            if (none_of(j.begin(),j.end(),[](char c){ return '0'<=c && c<='9'; }))
                return false; // minimum egy szamjegy
            if (!any_of(j.begin(),j.end(),[](char c){ return 'A'<=c && c<='Z'; }))
                return false; // minimum egy (angol) nagybetu
            if (1 > count_if(j.begin(),j.end(),[](char c){ return 'a'<=c && c<='z'; }))
                return false; // minimum egy (angol) kisbetu
            return true;
        };
        vector<string> jelszavak = getJelszavak2();
        //// 2. feladat --- MEGIRANDO RESZ ELEJE
        ///

        auto elso = find_if(jelszavak.begin(),jelszavak.end(),erosJelszo); // find_if fuggvenyhivas ide

        //// 2. feladat --- MEGIRANDO RESZ VEGE
        if (elso==jelszavak.end())
            cout << "Nincs eros jelszo!" << endl;
        else
        {
            string elsoEros = *elso;
            cout << "Elso eros jelszo: \"" << elsoEros << "\"" << endl;
        }
        cout << endl;
    }
    // Elso eros jelszo: "Szent3sag"

    {
        cout << "3. feladat" << endl << endl;
        int also_korlat = 0;
        int felso_korlat = 100;



        //// 3. feladat --- MEGIRANDO RESZ ELEJE
        ///

        auto normalis = [&also_korlat,&felso_korlat](int meres)
        {
            return also_korlat <= meres && felso_korlat >= meres;
        };
        // normalis lambda ide
        //// 3. feladat --- MEGIRANDO RESZ VEGE
        ///
        ///
        list<double> mereslista = getMereslista3();
        bool n1 = all_of(mereslista.begin(),mereslista.end(),normalis);
        cout << "1.: " << (n1 ? "mind normalis." : "valamelyik abnormalis!") << endl;
        also_korlat = -30;
        felso_korlat = 120;
        bool n2 = all_of(mereslista.begin(),mereslista.end(),normalis);
        cout << "2.: " << (n2 ? "mind normalis." : "valamelyik abnormalis!") << endl;
        also_korlat = -1;
        felso_korlat = 101;
        bool n3 = all_of(mereslista.begin(),mereslista.end(),normalis);
        cout << "3.: " << (n3 ? "mind normalis." : "valamelyik abnormalis!") << endl;
        felso_korlat = 104;
        bool n4 = all_of(mereslista.begin(),mereslista.end(),normalis);
        cout << "4.: " << (n4 ? "mind normalis." : "valamelyik abnormalis!") << endl;
        cout << endl;
    }
    // 1.: valamelyik abnormalis!
    // 2.: mind normalis.
    // 3.: valamelyik abnormalis!
    // 4.: mind normalis.

    {
        cout << "4. feladat" << endl << endl;
        //// 4. feladat --- MEGIRANDO RESZ ELEJE


        auto korabbi = [&](Szemely& w, Szemely& w2)
        {
           if(w.getEletkor() < w2.getEletkor()) return true;
           if(w.getEletkor() > w2.getEletkor()) return false;
        };



                // korabbi lambda ide
        //// 4. feladat --- MEGIRANDO RESZ VEGE
        vector<Szemely> szemelyek = getSzemelyek4();
        sort(szemelyek.begin(),szemelyek.end(),korabbi);
        for (auto& sz : szemelyek)
            cout << sz.getNev() << ", " << sz.getEletkor() << endl;
        cout << endl;
    }
    // Laszlo, 9
    // Ferenc, 14
    // Hanna, 17
    // Andras, 25
    // Eszter, 25
    // Judit, 25
    // Sara, 25
    // Magdolna, 34
    // Zsombor, 34
    // Ilona, 64
    // Karoly, 75

//    {
//        cout << "5. feladat" << endl << endl;
//        int arGyerek=1500, arDiak=2100, arFelnott=3000;
//        list<Szemely> csoport = getCsoport5();
//        //// 5. feladat --- MEGIRANDO RESZ ELEJE
//        int vegosszeg = // accumulate fuggvenyhivas ide
//        //// 5. feladat --- MEGIRANDO RESZ VEGE
//        cout << "Vegosszeg = " << vegosszeg << endl;
//        cout << endl;
//    }
//    // Vegosszeg = 29700

//    {
//        cout << "6. feladat" << endl << endl;
//        vector<Szemely> alkalmazottak = getAlkalmazottak6();
//        vector<bool> szuletesnap = getSzuletesnap6();
//        //// 6. feladat --- MEGIRANDO RESZ ELEJE
//        // transform fuggvenyhivas ide
//        //// 6. feladat --- MEGIRANDO RESZ VEGE
//        for (auto& a : alkalmazottak)
//            cout << a.getNev() << ", " << a.getEletkor() << endl;
//        cout << endl;
//    }
//    // Karoly, 76
//    // Zsombor, 34
//    // Ilona, 65
//    // Judit, 26
//    // Hanna, 18
//    // Eszter, 26
//    // Ferenc, 15
//    // Andras, 25
//    // Sara, 25
//    // Magdolna, 34
//    // Laszlo, 9

//    {
//        cout << "7. feladat" << endl << endl;
//        map<Szemely,unsigned> varoterem = getVaroterem7();
//        vector<map<Szemely,unsigned>::iterator> seged;
//        //// 7. feladat --- MEGIRANDO RESZ ELEJE
//        // seged vector feltoltese ide
//        auto kisebbsorszam = // kisebbsorszam lambda ide
//        //// 7. feladat --- MEGIRANDO RESZ VEGE
//        sort(seged.begin(),seged.end(),kisebbsorszam);
//        for (auto& it : seged) // map<Szemely,unsigned>::iterator
//        {
//            auto p = *it; // pair<Szemely,unsigned>
//            cout << "Sorszam=" << p.second << " <- ";
//            cout << it->first.getNev() << ", " << it->first.getEletkor() << endl;
//        }
//        cout << endl;
//    }
//    // Sorszam=1001 <- Sara, 25
//    // Sorszam=1002 <- Magdolna, 34
//    // Sorszam=1003 <- Laszlo, 9
//    // Sorszam=1004 <- Hanna, 17
//    // Sorszam=1005 <- Ferenc, 14
//    // Sorszam=1006 <- Eszter, 25
//    // Sorszam=1007 <- Zsombor, 34
//    // Sorszam=1008 <- Karoly, 75
//    // Sorszam=1009 <- Ilona, 64
//    // Sorszam=1010 <- Judit, 25
//    // Sorszam=1011 <- Andras, 25

    cout << "main() vege!" << endl;
    return 0;
}

string getSzoveg1 ()
{
    return "a kiralynot megolni nem kell felnetek jo lesz \
            ha ti mindnyajan beleegyeztek en nem ellenzem";
}

vector<string> getJelszavak2 ()
{
    return {"dragon","rovid","hosszujelszo","kell123","TASKA1234567",
        "egyikSemJo", "P4SSW0RD", "P4SSW0RD42", "!!!Hard_Boiled!!!",
        "ezegyhosszuszo", "CSUPANAGYBETUS", "csupakisbetus", "202262412",
        "e4e5Hf3", "Szent3sag", "sTrOnGpAsSwOrD123", "ezmegmarnemjo123",
    };
}

list<double> getMereslista3 ()
{
    return { 55.3, 17.8, 19.2, 102.3, -0.02, 0.1, 66.4, 47.8, 99.6 };
}

vector<Szemely> getSzemelyek4 ()
{
    return {
        {"Karoly", 75},
        {"Zsombor", 34},
        {"Ilona", 64},
        {"Judit", 25},
        {"Hanna", 17},
        {"Eszter", 25},
        {"Ferenc", 14},
        {"Andras", 25},
        {"Sara", 25},
        {"Magdolna", 34},
        {"Laszlo", 9},
    };
}

list<Szemely> getCsoport5 ()
{
    auto v = getSzemelyek4();
    return list<Szemely>(v.begin(),v.end());
}

vector<Szemely> getAlkalmazottak6 ()
{
    return getSzemelyek4();
}

vector<bool> getSzuletesnap6 ()
{
    return {1,0,1,1,1,1,1,0,0,0,0};
}

map<Szemely,unsigned> getVaroterem7 ()
{
    return {
        {{"Karoly", 75}, 1008},
        {{"Zsombor", 34}, 1007},
        {{"Ilona", 64}, 1009},
        {{"Judit", 25}, 1010},
        {{"Hanna", 17}, 1004},
        {{"Eszter", 25}, 1006},
        {{"Ferenc", 14}, 1005},
        {{"Andras", 25}, 1011},
        {{"Sara", 25}, 1001},
        {{"Magdolna", 34}, 1002},
        {{"Laszlo", 9}, 1003},
    };
}
