#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef struct Sportolo{
    unsigned int magassag;
    double atlagmeccs;
    unsigned int evek;
    unsigned int eletkor;

}Sportolo;

Sportolo kiir(){
    Sportolo focista[9];
    for(int i=0;i<9;i++){
        printf("\n%u",focista[i].magassag);
        printf("\n%lf",focista[i].atlagmeccs);
        printf("\n%u",focista[i].evek);
        printf("\n%u", focista[i].eletkor);
    }
}

    return 0;
}
