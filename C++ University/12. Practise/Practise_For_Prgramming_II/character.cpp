#include "character.h"


int Character::getHealth() const
{
    return health;
}

void Character::setHealth(int newHealth)
{
    health = newHealth;
}



int Character::getArmor() const
{
    return armor;
}

int Character::getDamage() const
{
    return damage;
}


const string &Character::getName() const
{
    return name;
}

Character::Character(int a1, int a2, int a3, string a4):health(a1),armor(a2),damage(a3),name(a4)
{

}
