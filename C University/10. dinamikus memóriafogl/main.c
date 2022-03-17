#include <stdio.h>
#include <stdlib.h>

#define N 5

typedef struct Koord{
    float x, y;
}Koord;


int main()
{
    Koord* tomb[N];

    for(int i; i<N;i++){
        printf("Beolvas?");
        int beolvas =0;
        scanf("%d", &beolvas);
        if(beolvas == 1){
            tomb[i] = (Koord*)malloc(sizeof(Koord));
            scanf("%f %f", &tomb[i] ->x, &tomb[i]->y);

        }
        else{
            tomb[i] =0;
        }

    }

    for(int i=0;i<N;i++)
    {
        if(tomb[i] !=0){
            printf("%f %f\n", tomb[i]->x, tomb[i]->y);
        }
    }

    for(int i=0;i<N;i++){
        if(tomb!=0)
            free(tomb[i]);
    }


    return 0;
}
