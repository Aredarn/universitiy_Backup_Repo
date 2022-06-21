#ifndef PLAYER_H
#define PLAYER_H
#include <character.h>
#include <iostream>
#include <string.h>
using namespace std;


class Player : public Character
{
    int regen = 2;
public:
    void getAllInfo();
    Player(int a1,int a2,int a3, string a4);
    virtual string getSpecies();
};

#endif // PLAYER_H
