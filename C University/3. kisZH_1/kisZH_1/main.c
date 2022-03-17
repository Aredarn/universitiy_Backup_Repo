#include <stdio.h>
#include <stdlib.h>

int main()
{
   //A:
    float a = -6.33;
    //B:
    unsigned int b;
    double c;

    scanf("%u %lf", &b, &c);
    //C:
    double d = b + c;


    //D:
    printf("D) %0.2lf %u %0.2lf\n", a, b, c );
    //E:
    printf("E) %0.2lf\n" ,d);

    //F:
    float e = a-b;
    printf("F) %0.2f",e);


    return 0;
}
