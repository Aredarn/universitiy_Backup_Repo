#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tomb[12];
    int i = 0;

    for(i=0;i<12;i++){
        scanf("%d",&tomb[i]);
    }

    i =0;

    do{
        printf("%d ",tomb[i]);
        i = i+1;
    }while(i<12);

    int tizedikindexelegyenlo = -1;
    i = 0;

    for(i=0;i<12;i++){
        if(tomb[i] != tomb[10]){
            tizedikindexelegyenlo = i;
            break;
        }
    }
    printf("\n%d",tizedikindexelegyenlo);

    i = 0;
    int csere = tomb[10];
    tomb[10] = tomb[11];
    tomb[11] = csere;

    printf("\n");
    do{
        printf("%d ",tomb[i]);
        i = i+1;
    }while(i<12);

    return 0;
}
