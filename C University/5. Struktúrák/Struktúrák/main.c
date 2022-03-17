#include <stdio.h>
#include <stdlib.h>
#define N 3

typedef struct computer{
    float cpu;
    int memory;
    int hdd;
}Computer;

typedef struct workspace{
    int user_id;
    Computer cp;
}workspace;

typedef struct point{
    int x;
    int y;
    int z;
}Point;

typedef struct triangle{
    Point a;
    Point b;
    Point c;
}Thr;



int main()
{
    //Sima computer struktúrával való mûveltek
    //Computer szamitogepek[N];
    /*
    for(int i = 0; i<N;i++){
        scanf("%f" , &szamitogepek[i].cpu);
        scanf("%d", &szamitogepek[i].memory);
        scanf("%d", &szamitogepek[i].hdd);
    }
    for(int i = 0; i<N;i++){
        printf("Cpu %f , %d hdd , %d memory\n", szamitogepek[i].cpu , szamitogepek[i].hdd, szamitogepek[i].memory);
    }
    */

    //Workspcae struktúra mûvelet

    /*
    workspace ws;
    scanf("%d", &ws.user_id);
    scanf("%f %d %d", &ws.cp.cpu , &ws.cp.memory , &ws.cp.hdd);

    printf("ID:%d , CPU:%f , Memory: %d , HDD: %d", ws.user_id, ws.cp.cpu , ws.cp.memory , ws.cp.hdd);
    */

    Thr hrm;

    scanf("%d %d %d",&hrm.a.x,&hrm.a.y, &hrm.a.z);
    scanf("%d %d %d",&hrm.b.x,&hrm.b.y, &hrm.b.z);
    scanf("%d %d %d",&hrm.c.x,&hrm.c.y, &hrm.c.z);


    printf("%d %d %d\n",hrm.a.x,hrm.a.y,hrm.a.z);
    printf("%d %d %d\n",hrm.b.x, hrm.b.y,hrm.b.z);
    printf("%d %d %d\n",hrm.c.x,hrm.c.y, hrm.c.z);







    return 0;
}
