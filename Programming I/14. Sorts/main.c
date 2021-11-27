#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tomb[6];

    for(int i=0;i<6;i++)
        scanf("%d",&tomb[i]);

    for(int i=0;i<6;i++)
        printf("%d  ", tomb[i]);

    printf("\n");

    for(int i=0;i<5;i++)
    {
        for(int j=i+1;j<6;j++)
            if(tomb[i]>tomb[j]){
                int csere = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = csere;
            }
    }
     for(int i=0;i<6;i++)
        printf("%d ", tomb[i]);



    return 0;
}
