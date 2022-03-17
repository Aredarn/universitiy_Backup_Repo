#include <stdio.h>
#include <stdlib.h>


int keres(int tomb[], int meret, int ertek)
{
    int idx=0;
    while(idx<meret&&tomb[idx] != ertek)
        idx++;
    return idx;
}


int main()
{
    int tomb[6] = {2,4,8,16,32};

    int* ptomb[10];

    for(int i=0;i<10;++i)
    {
        int a;
        scanf("%d", &a);
        int idx = keres(tomb,6,a);
        if(idx<6)
        {
            ptomb[i] = &tomb[idx];
        }
        else
        {
            ptomb[i] = 0;
        }
    }

    for(int i=0;i<10;++i)
    {
        if(ptomb[i] != 0)
        {
            printf("%d.: %d (%p)\n", i+1, *ptomb[i], ptomb[i]);
        }
        else{
            printf("%d NULL\n", i);
        }
    }


    return 0;
}
