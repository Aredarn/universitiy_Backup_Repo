#include "player.h"

#include <iostream>

using namespace std;

int main()
{
    Player* asd = new Player(100,50,12,"Sanyi");

    asd->getAllInfo();

    delete asd;
    cout <<endl<< "End of Practise!" << endl;
    return 0;
}
