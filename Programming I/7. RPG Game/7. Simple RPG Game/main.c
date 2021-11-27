#include <conio.h>
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Player{
    int Health ;
    int Strength;
    int Agility;
    int Intelligence;
    int Level;
    int Xp;
}player;

typedef struct Enemies{
    int Health;
    int Damage;
    int Level;
    int GivenXP;
}enemies;

player hero;
enemies enemy;

player fillStats()
{
    player hero;
    hero.Health = 100;
    hero.Strength = 5;
    hero.Agility = 3;
    hero.Intelligence = 3;
    hero.Level = 1;
    hero.Xp = 0;

    return hero;
}

enemies giveStats()
{
    enemies enemy;

    srand(time(NULL));
    int rnd = rand() % 7;

    int xpGiven = hero.Level*10*rnd;

    enemy.Health = 45;
    enemy.Damage = enemy.Level+ rnd;
    enemy.Level = hero.Level;
    enemy.GivenXP = xpGiven;

    return enemy;
}

// main menu for the game, New game, Load game and Exit.
void menu(){
    printf("1. Start game");
    printf("\n2. load game");
    printf("\n3. Exit\n");
    int choise = 0;
    scanf("%d", &choise);

    switch(choise)
    {
        case 1:
            inGame();
            break;
        case 2:
            //In the future
            break;
        case 3:
            exit(0);
            break;
        default:
            menu();
            break;

    }
}

//This is the mostly used Menu for the game, you can attack, heal, back up, Switch Weapon and view your stats here.
void inGame(){
    system("cls");
    printf("\nSelect option:\n\n");
    bool enemyIsAlive = true;


    do{
    int choise;
    printf("1. Attack");
    printf("\n2. Heal");
    printf("\n3. Enemy Stats");
    //printf("\n4. Switch Weapon");
    printf("\n5. Stats");
    printf("\n6. Menu\n");



    scanf("%d", &choise);

    switch(choise)
    {
        case 1:
            Attack();
            EnemyBehavior();
            system("cls");
            break;
        case 2:
            Heal();
            EnemyBehavior();
            system("cls");
            break;
        case 3:
            EnemyInfo();
            system("cls");
            break;
        case 5:
            Stats();
            system("cls");
            break;
        case 6:
            system("cls");
            menu();
            break;
        default:
            inGame();
            break;
    }

    if(enemy.Health<0)
        enemyIsAlive = false;

    }while(enemyIsAlive && hero.Health>0);

    if(!enemyIsAlive)
       {
            system("cls");
            printf("GAME OVER");
            sleep(2);
            inGame();
        }
    else{
            system("cls");
            printf("GAME OVER");
            sleep(2);
            menu();
        }
}
//This method shows the stat points of your character
void Stats(){
    printf("\nHealth: %d", hero.Health);
    printf("\nStrenght: %d", hero.Strength);
    printf("\nAgility: %d", hero.Agility);
    printf("\nIntelligence: %d", hero.Intelligence);
    printf("\nLevel: %d ", hero.Level);
    printf("\nExperience: %d", hero.Xp);
    sleep(5);
    system("cls");
}

void EnemyInfo()
{

    printf("\nHealth: %d", enemy.Health);
    printf("\nDamage: %d", enemy.Damage);
    printf("\nExperience for killing: %d", enemy.GivenXP);
    printf("\nLevel: %d", enemy.Level);
    sleep(5);
    system("cls");
}
EnemyBehavior(){
    srand(time(NULL));
    int BehaveRand = rand()%10;

    if(enemy.Health<20&&rand<4)
    {
        printf("Enemy healed");
        enemy.Health = enemy.Health + (enemy.Health/50);
    }
    else
    {
        printf("\nEnemy Attacked you and dealt %d damage", enemy.Damage+BehaveRand);
        hero.Health-=enemy.Damage+BehaveRand;
    }
    sleep(2);
}

//This method calculates your damage based on your STRENGTH attribute for stats.
int Attack(){
    //Creates random number for attack
    srand(time(NULL));
    int random = rand() % 10;
    //Normal attack
    int damage = hero.Strength+random;// + weapon.equipped

    if(random <3)
            printf("You missed");
    else if(random == 10)
        {
            printf("You have dealt a critical!!! %d damage.", damage+ random);
            enemy.Health-=damage+random;
        }
    else
        {
            printf("You have dealt %d damage.", damage);
            enemy.Health-=damage;
        }



    sleep(2);
}

void Heal(){
    hero.Health = hero.Health+(hero.Intelligence * hero.Agility);
    printf("Healed: %d points", hero.Intelligence * hero.Agility);
    printf("\nYour correct health is: %d", hero.Health);
    sleep(2);
}


int main()
{
    hero = fillStats();
    enemy = giveStats();
    menu();
    return 0;
}
