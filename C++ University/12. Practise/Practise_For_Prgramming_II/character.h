#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string.h>

using namespace std;

class Character
{
    int health;
    int armor;
    int damage;
    string name;

public:
    Character(int a1,int a2,int a3, string a4);

    void setHealth(int newHealth);
    virtual ~Character() = default;
    virtual string getSpecies() =0;

    int getArmor() const;
    int getDamage() const;
    int getHealth() const;

    const string &getName() const;
};

#endif // CHARACTER_H
