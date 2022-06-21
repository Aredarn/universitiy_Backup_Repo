#include <iostream>

using namespace std;

void printArray(int array[], int size) {
  for (int i = 0; i < size; i++) {
    cout << array[i] << " ";
  }
  cout << endl;
}


void beszúró_rendezés(int tomb[], int N)
{

}


int main()
{
    int tomb[10]{176,224,33,41,86,45,432,521,312,32};

    printArray(tomb,10);

    return 0;
}
