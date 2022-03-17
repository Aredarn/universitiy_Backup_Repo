#include <stdio.h>
#include <stdlib.h>

int main()
{
    int meret;
    scanf("%d", &meret);
    int* tomb = (int*)malloc(sizeof(int) * meret);

    for(int i=0;i<meret;i++){
        scanf("%d", &tomb[i]);
    }




    for(int i=0;i<meret;i++)
    {
        printf("%d\n", tomb[i]);
    }

    free(tomb);

    return 0;
}
