#include <stdio.h>
#include <stdlib.h>



struct sportolo
{
    double atlagmeccs;
    unsigned int evek;
    unsigned int eletkor;
    char sportag[30];
};

// Ide jön a megoldás

int* lefoglal(int a)
{
    struct sportolo* tomb = (struct sportolo*) malloc(sizeof(int) * a);
    return tomb;
}

void visszaad(int* tomb)
{
    free(tomb);
}

void osszehasonlit(struct sportolo* a,struct sportolo* b)
{
    int kulonbseg = 0;

    if(a->atlagmeccs>b->atlagmeccs)
    {
        kulonbseg = a->atlagmeccs-b->atlagmeccs;
    }
    else
    {
        kulonbseg = b->atlagmeccs-a->atlagmeccs;
    }
    printf("%d\n",kulonbseg);
}

int* ujtomb()
{
    unsigned int meret=6;

    int* tomb = (int*) malloc(sizeof(int)* meret);
    int i=0;
    int j=0;
    for(i=0;i<meret;i++)
    {
        scanf("%d",tomb[i]);
    }

    for(i=0;i<meret-1;i++){
        for(j=i+1;j<meret;j++)
            if(tomb[i]>tomb[j])
        {
            int csere = tomb[i];
            tomb[i] = tomb[j];
            tomb[j] = csere;

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
    tomb=lefoglal(meret);
    unsigned int i;
    for (i=0; i<meret; i++)
    {
        scanf("%lf", &tomb[i].atlagmeccs);
        scanf("%u", &tomb[i].evek);
        scanf("%u", &tomb[i].eletkor);
        scanf("%s", tomb[i].sportag);
    }

    for (i=0; i<meret; i++)
    {
        printf("%.2lf ", tomb[i].atlagmeccs);
        printf("%u ", tomb[i].evek);
        printf("%u ", tomb[i].eletkor);
        printf("%s\n", tomb[i].sportag);
    }
    printf("\n--END OF PART1--\n");

    #ifdef PART2
    printf("\n--START OF PART2--\n");
    osszehasonlit(&tomb[1],&tomb[2]);
    osszehasonlit(&tomb[9],&tomb[6]);
    osszehasonlit(&tomb[5],&tomb[5]);
    osszehasonlit(&tomb[4],&tomb[7]);
    osszehasonlit(&tomb[7],&tomb[7]);
    osszehasonlit(&tomb[8],&tomb[6]);
    osszehasonlit(&tomb[9],&tomb[3]);
    osszehasonlit(&tomb[1],&tomb[6]);
    printf("\n--END OF PART2--\n");
    #endif

    #ifdef PART3
    printf("\n--START OF PART3--\n");
    int *uj=ujtomb();
    for (i=0; i<6; i++)
        printf("%d ", uj[i]);
    printf("\n");
    free(uj);
    printf("\n--END OF PART3--\n");
    #endif

    printf("\n--START OF PART1--\n");
    visszaad(tomb);
    printf("\n--END OF PART1--\n");

    return 0;
}
