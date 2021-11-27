#include <stdio.h>
#include <stdlib.h>
#define FIX_ELEM_SZAM 4
int main()
{
    void SzamokBeker(int*)
    {

  for(int i=0;i<FIX_ELEM_SZAM;i++){

  printf("Kérem a %d. számot: ",i+1);
  scanf("%d",szamok_helye+i);

  }
}

    return 0;
}
