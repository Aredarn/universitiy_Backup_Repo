#include <iostream>

using namespace std;

namespace Focista{

    namespace adatok{

        struct focista
        {
            int sorszam;
            unsigned eletkor;
            unsigned magassag;
            int osszgol;
            int osszmeccs;
            bool voltevb;
        };
    }


    namespace fuggvenyek
    {
        //Lefoglaló függvény
        adatok::focista *lefoglal(unsigned meret)
        {
            return new adatok::focista [meret];
        }

        //BEOLVAS FUGGVENY
        adatok::focista bekeres(adatok::focista *tomb ,unsigned meret)
        {

            for(int i =0;i<meret;i++)
            {
                cout <<"Eletkora a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].eletkor;

                cout <<"Magassaga a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].magassag;

                cout <<"Lott goljai  a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].osszgol;

                cout <<"Osszes meccse a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].osszmeccs;

                cout <<"Sorszama a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].sorszam;

                cout <<"Jatszott-e VB-t a " << i+1<<". Jatekosnak" <<endl;
                cin >> tomb[i].voltevb;

                cout << endl;
            }
        }

        //KIIR FÜGGVÉNY
        adatok::focista kiiras(adatok::focista *tomb, unsigned meret)
        {
            for(int i=0;i<meret;i++)
            {

                cout << "Eletkora a(z) " << i+1 << ". jatetkosnak: " << tomb[i].eletkor;
                cout << endl;
                cout <<"Magassaga a " << i+1<<". Jatekosnak: " << tomb[i].magassag;
                cout << endl;
                cout <<"Lott goljai  a " << i+1<<". Jatekosnak: " << tomb[i].osszgol;
                cout << endl;
                cout <<"Osszes meccse a " << i+1<<". Jatekosnak: " << tomb[i].osszmeccs;
                cout << endl;
                cout <<"Sorszama a " << i+1<<". Jatekosnak: " << tomb[i].sorszam;
                cout << endl;
                cout <<"Jatszott-e VB-t a " << i+1<<". Jatekosnak: " << tomb[i].voltevb;
            }
        }

        //LEGIDOSEBB JATEKOS
        adatok::focista* legidosebb(adatok::focista *tomb, unsigned meret)
        {
            adatok::focista legidosebb_jatekos = tomb[0];
            for( int i=0;i<meret;i++)
            {
                if(legidosebb_jatekos.eletkor<tomb[i].eletkor)
                {
                    legidosebb_jatekos = tomb[i];
                }
            }
            cout << endl;
            cout << legidosebb_jatekos.sorszam;
            cout << endl;
            cout << legidosebb_jatekos.eletkor;
            cout << endl;
            return &legidosebb_jatekos;
        }

        //LEGALABB JATSZOTT MECCS
        adatok::focista legalabbmeccs(adatok::focista *tomb,int meret, int legameccs =10)
        {
            int darab = 0;

            for(int i=0;i<meret;i++)
            {
                if(tomb[i].osszmeccs>legameccs)
                    darab++;
            }
            cout << endl;
            cout << "Ennyi jatekos jatszott legalabb " << legameccs<< " meccset: " << darab;
        }

        //VAN E A MEGADOTT MEZSZAM
        adatok::focista vanemezszam(adatok::focista *tomb, int meret, int kivantmez)
        {
            int keresettIDX = -1;

            for(int i=0;i<meret;i++)
            {
                if(tomb[i].sorszam == kivantmez)
                {
                    keresettIDX = i;
                }
            }

            if(keresettIDX!=-1)
            {
                cout << "Eletkora a(z) " << keresettIDX+1 << ". jatetkosnak: " << tomb[keresettIDX].eletkor;
                cout << endl;
                cout <<"Magassaga a " << keresettIDX+1<<". Jatekosnak: " << tomb[keresettIDX].magassag;
                cout << endl;
                cout <<"Lott goljai  a " << keresettIDX+1<<". Jatekosnak: " << tomb[keresettIDX].osszgol;
                cout << endl;
                cout <<"Osszes meccse a " << keresettIDX+1<<". Jatekosnak: " << tomb[keresettIDX].osszmeccs;
                cout << endl;
                cout <<"Sorszama a " << keresettIDX+1<<". Jatekosnak: " << tomb[keresettIDX].sorszam;
                cout << endl;
                cout <<"Jatszott-e VB-t a " << keresettIDX+1<<". Jatekosnak: " << tomb[keresettIDX].voltevb;
            }
            else
            {
                cout << "nincs ilyen mezszamu jatekos";
            }

        }

        adatok::focista tombrendezo(adatok::focista *tomb, int meret)
        {
            int i,j;
            for(i=0;i<meret-1;i++)
            {
                for(j=i+1;j<meret;j++)
                {
                    if(tomb[i].magassag<tomb[j].magassag)
                    {
                        adatok::focista tombcsere = tomb[i];
                        tomb[i] = tomb[j];
                        tomb[j] = tombcsere;

                    }
                }
            }

            cout << endl;
            for(i=0;i<meret;i++)
            {
                cout << tomb[i].magassag << endl;
            }
        }

    }
}//FOCISTA

using namespace Focista::adatok;
using namespace Focista::fuggvenyek;

int main()
{
    cout << "Hany jatekost taroljunk?"<<endl;

    int jatekosok;
    cin >> jatekosok;
    focista *tomb = lefoglal(jatekosok);

    bekeres(tomb,jatekosok);

    kiiras(tomb,jatekosok);

    legidosebb(tomb,jatekosok);

    legalabbmeccs(tomb,jatekosok,20);

    cout << endl;
    int legennyi;
    cin >> legennyi;
    legalabbmeccs(tomb,jatekosok,legennyi);

    cout << endl;
    int kivantmez;
    cin >> kivantmez;
    vanemezszam(tomb,jatekosok,kivantmez);

    tombrendezo(tomb,jatekosok);

    return 0;
}
