#include <stdio.h>
#include <stdlib.h>

typedef struct lakas{
    int alapterulet;
    int szobak;
    double gazfogyaszt;

}lakasok;

typedef struct tarsashaz
{
    lakasok helyilakas[6];
    int kenyelem;
    int gondokKor;
}tarsashazak;


/*
65
50
45
3
10
54
4
12
65
3
13
76
5
11
37
4
9
78
1
5

72
45
65
3
10
76
4
12
98
3
13
48
5
11
37
4
9
78
1
5

83
67
45
3
10
54
4
12
65
3
13
76
5
11
37
4
9
78
1
5


*/
int main()
{
    tarsashazak lakopark[3];
    int i,j;
    for(i=0;i<3;i++){
        printf("Gondnok eletkora:");
        scanf("%d", &lakopark[i].gondokKor);

        printf("Kenyelem: ");
        scanf("%d", &lakopark[i].kenyelem);

        for(j=0;j<6;j++){
            printf("%d . alapterulete:",j+1);
            scanf("%d", &lakopark[i].helyilakas[j].alapterulet);

            printf("%d . szobai:",j+1);
            scanf("%d", &lakopark[i].helyilakas[j].szobak);

            printf("%d . gazfogyasztasa:",j+1);
            scanf("%d", &lakopark[i].helyilakas[j].gazfogyaszt);


        }
    }

    int max = 0, maxindex =0;

    for(i=0;i<3;i++){
        if(lakopark[i].gondokKor>max)
        {
            max=lakopark[i].gondokKor;
            maxindex = i;
        }
    }
    printf("%d %d", max,maxindex);

    int maxlakas;

    for(i=0;i<5;i++)
    {
        if(lakopark[maxindex].helyilakas[i].alapterulet>maxlakas)
            maxlakas = lakopark[maxindex].helyilakas[i].alapterulet;
    }

    printf("\n%d nm a legkisebb lakás", maxlakas);



    return 0;
}
