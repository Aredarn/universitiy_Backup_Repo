#include <iostream>
using namespace std;

class Szam
{
    int a;

    public :int beolvas()
    {
        cin >> a;
        return a;
    }

    public :void set(int b)
    {
        a = b;
    }

    public :void print()
    {
        cout << "Kimenet : " << a;
    }
};

int main()
{
    Szam var;
    int i=var.beolvas();
    cout<<i<<endl;
    cin>>i;
    var.set(i);
    var.print();
    return 0;
}
