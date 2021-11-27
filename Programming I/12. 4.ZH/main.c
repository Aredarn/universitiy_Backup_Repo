#include <stdio.h>
#include <stdlib.h>
struct sportolo
{
    unsigned int mezszam;
    unsigned int evek;
    unsigned int magassag;
    double atlagmeccs;
};

//Készíts egy helyetfoglal függvényt, amely megkap egy egész számot, lefoglal egy dinamikus tömböt ennyi darab sportoló tárolására, és visszatér a memóriaterület címével.
//Készíts egy torol függvényt, amely megkapja egy dinamikusan lefoglalt sportoló tömb címét, és felszabadítja azt.


double* helyetfoglal( int a){

    struct sportolo* tomb = (struct sportolo*) malloc (sizeof(struct sportolo) * a);
    return tomb;

}

void torol(struct sportolo* tomb)
{
    free(tomb);
}

void fuggveny2(struct sportolo* a, struct sportolo* b)
{
    int kulonbseg;
    if(a->mezszam < b->mezszam)
    {
        kulonbseg = b->mezszam-a->mezszam;
    }
    else if(a->mezszam > b->mezszam){
        kulonbseg = a->mezszam-b->mezszam;
    }
    else{
        return 0;
    }

    printf("%d\n", kulonbseg);
}



double* tombosfuggveny(){

    int meret =6;
    int* tomb = (int*) malloc(sizeof(tomb) * meret);

    for(int i =0; i<meret;i++)
    {
        scanf("%d",&tomb[i]);
    }

    for(int i=0;i<meret-1;i++)
    {
        for(int j=1;j<meret;i++){
            if(tomb[i]<tomb[j])
            {
                int csere = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = csere;
            }
        }
    }
    return tomb;

}



int main()
{
    printf("\n--START OF PART1--\n");
    unsigned int meret;
    scanf("%u", &meret);
    struct sportolo *tomb;
    tomb=helyetfoglal(meret);
    unsigned int i;
    for (i=0; i<meret; i++)
    {
        scanf("%u", &tomb[i].mezszam);
        scanf("%u", &tomb[i].evek);
        scanf("%u", &tomb[i].magassag);
        scanf("%lf", &tomb[i].atlagmeccs);
    }

    for (i=0; i<meret; i++)
    {
        printf("%u ", tomb[i].mezszam);
        printf("%u ", tomb[i].evek);
        printf("%u ", tomb[i].magassag);
        printf("%.2lf\n", tomb[i].atlagmeccs);
    }
    printf("\n--END OF PART1--\n");

    #ifdef PART2
    printf("\n--START OF PART2--\n");
    fuggveny2(&tomb[4],&tomb[7]);
    fuggveny2(&tomb[1],&tomb[7]);
    fuggveny2(&tomb[8],&tomb[1]);
    fuggveny2(&tomb[5],&tomb[2]);
    fuggveny2(&tomb[0],&tomb[5]);
    fuggveny2(&tomb[9],&tomb[7]);
    fuggveny2(&tomb[4],&tomb[0]);
    fuggveny2(&tomb[4],&tomb[3]);
    printf("\n--END OF PART2--\n");
    #endif

    #ifdef PART3
    printf("\n--START OF PART3--\n");
    int *uj=tombosfuggveny();
    for (i=0; i<6; i++)
        printf("%d ", uj[i]);
    printf("\n");
    free(uj);
    printf("\n--END OF PART3--\n");
    #endif

    printf("\n--START OF PART1--\n");
    torol(tomb);
    printf("\n--END OF PART1--\n");
    int a;
    scanf("%d",&a);
    return 0;
}
