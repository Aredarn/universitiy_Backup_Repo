#include "player.h"
#include "character.h"
void Player::getAllInfo()
{
    cout << "Name: " << this->getName()<< endl;
    cout << "Health: " <<this->getHealth() <<endl;
    cout << "Armor: " << this->getArmor() << endl;
    cout << "Regen: " << this->regen << endl;
    cout << "Damage: " << this->getDamage() << endl;
}

Player::Player(int a1, int a2, int a3, string a4):Character(a1,a2,a3,a4)
{

}

string Player::getSpecies()
{
    return "Játékos";
}

