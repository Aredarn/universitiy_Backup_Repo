#include "Hallgato.h"
#include "szemely.h"
#include <iostream>
using namespace std;

Hallgato::Hallgato(const string &v, const string &k, unsigned int kor, const string &neptun, unsigned felev)
: Szemely(v,k,kor), felevek(felev)
{
    //ctor
}

void Hallgato::kiir() const
{
   cout << getVezetekNev << " " << getKeresztNev() << ": " << getEletkor() ;

}
