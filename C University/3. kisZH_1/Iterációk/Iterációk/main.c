#include <stdio.h>
#include <stdlib.h>

int main()
{
    int eletkor;
    printf("Kerem az eletkort:");

    //legalább 0 éves, legfeljebb 150
    do
      scanf("%d", &eletkor);
    while(eletkor>150 || eletkor<0);


    //2. feladat
    float sok;
    float atlag = 0;
    int osszeg=-1;

    do{
        if(!sok == 0)
        {   scanf("%f", &sok);
            osszeg = osszeg+1;
            atlag = atlag + sok;
        }
    }while(!sok == 0);


    printf("Átlaguk: %f" , atlag/osszeg);
    return 0;
}
