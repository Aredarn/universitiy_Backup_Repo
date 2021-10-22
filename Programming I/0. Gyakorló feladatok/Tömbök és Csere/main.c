#include <stdio.h>
#include <stdlib.h>
#define n 10


int main()
{
    //3.5 feladat
    int t1[3];
    int t2[3];
    int i;
    printf("Type in the first vector: ");

    for(i=0;i<3;i++)
        scanf("%d", &t1[i]);

     printf("Type in the second vector: ");

    for(i=0;i<3;i++)
        scanf("%d", &t2[i]);

    printf("Three times the first vector: %d %d %d\n", t1[0]*3 , t1[1]*3, t1[2]*3);
    printf("Two times the second vector: %d %d %d\n", t2[0]*2 , t2[1]*2, t2[2]*2);

    printf("Unit vector of the first vector: 1/%d , 1/%d , 1/%d\n" ,t1[0], t1[1], t1[2]);

    printf("The scalar product of the two vector: %d %d %d\n", t1[0]*t2[0], t1[1]*t2[1], t1[2]*t2[2]);


    printf("Scalar product with loops:");

    for(i=0;i<3;i++){
        printf("%d ", t1[i]*t2[i]);
    }

    int c1 = t1[1]*t2[2]-t1[2]*t2[1];
    int c2 = t1[2]*t2[0]-t1[0]*t2[2];
    int c3 = t1[0]*t2[1]-t1[1]*t2[0];

    printf("\nVectorial: (%d,%d,%d)",c1 ,c2,c3);


    //4.5.1
    int tomb[n];

    for(i=0;i<n;i++){
        printf("\nEnter the arrays %d. item", i+1);
        scanf("%d", &tomb[i]);
    }

    int j;

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
            if(tomb[j]<tomb[i])
            {
                int temp = tomb[i];
                tomb[i] = tomb[j],
                tomb[j] = temp;
            }
    }


    for(i=0;i<n;i++){
        printf("%d, ", tomb[i]);
    }

    printf("\n\n\n");

    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++)
            if(tomb[j]>tomb[i])
            {
                int temp = tomb[i];
                tomb[i] = tomb[j],
                tomb[j] = temp;
            }
    }

     for(i=0;i<n;i++){
        printf("%d, ", tomb[i]);
    }


    return 0;
}
