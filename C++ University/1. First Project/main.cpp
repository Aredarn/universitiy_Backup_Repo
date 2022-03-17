#include <iostream>

using namespace std;


namespace urhajo{

    namespace adat{
        struct UrHajo
        {
            unsigned hossz;
            int legenyseg;
            double sebesseg;
            bool hiperter;
        };
    }//ADAT



    namespace muveletek{

        adat::UrHajo *lefoglal(unsigned meret)
        {
            return new adat::UrHajo[meret];
        }

        void kilistazHiperTer(adat::UrHajo *tomb, unsigned meret)
        {
            for(int i = 0;i<meret;i++)
            {
                if(tomb[i].hiperter)
                {
                    cout << i+1 << ". hajo: " << endl;
                    cout << "Hossz: "  << tomb[i].hossz << endl;
                    cout << "Legenyseg: " << tomb[i].legenyseg << endl;
                    cout << "Sebesseg: "  << tomb[i].sebesseg << endl;

                }
            }
        }


        unsigned megszamolLetszam(adat::UrHajo *tomb, unsigned meret, int minlegenyseg =100)
        {
            unsigned darab =0;

            for(int i=0; i<meret;i++)
            {
                if(tomb[i].legenyseg>=minlegenyseg)
                {
                    darab++;
                }
            }

            return darab;
        }


    adat::UrHajo *leglasabb(adat::UrHajo * tomb, int meret, bool csakAmiTudUgrani=false)
    {
        adat::UrHajo *lassu=nullptr;

        for(int i=0 ;i<meret;i++)
        {
            if(!csakAmiTudUgrani || tomb[i].hiperter)
            {
                if(lassu==nullptr)
                {
                    lassu =&tomb[i];
                }
                else if(tomb[i].sebesseg <lassu->sebesseg)
                    lassu=&tomb[i];
            }
        }
        return lassu;
    }

    }; //MUVELETEK



} //name space urhajo

using namespace urhajo::muveletek;
using namespace urhajo::adat;

int main()
{
    cout << "Mennyi hajo lesz?\n" ;
    unsigned meret;
    cin >> meret;
    UrHajo *tomb = lefoglal(meret);

    for(int i =0;i<meret;i++)
    {
        cout << "Kerem a(z)" << i+1 << ". urhajo adatait?" << endl;

        cout << "Hossz? ";
        cin >> tomb[i].hossz;

        cout << "Legenyseg: ";
        cin >> tomb[i].legenyseg;

        cout << "Sebesseg: ";
        cin >> tomb[i].sebesseg;

        cout << "Hiperter ugrasra kepes? :";
        cin >> tomb[i].hiperter;

    }


    cout << "KIIRAS" << endl;
    kilistazHiperTer(tomb, meret);

    int darab = megszamolLetszam(tomb, meret, 400);
    cout << endl<< "TOBB legenyseg: " << darab<<endl;

    lassu = leglasabb(tomb,meret);
    cout << "Hossz: "  << lassu->hossz << endl;
    cout << "Legenyseg: " << lassu->legenyseg << endl;
    cout << "Sebesseg: "  << tomb[i]->sebesseg << endl;


    return 0;
}
