#include <iostream>
using namespace std;

class IntVektor{
    int tomb[3];
public:
    IntVektor(){
        tomb[0]=0;
        tomb[1]=0;
        tomb[2]=0;
    }
    IntVektor(int a, int b, int c){
        tomb[0]=a;
        tomb[1]=b;
        tomb[2]=c;
    }
    int &operator[](unsigned index){
        return tomb[index];
    }
    const int &operator[](unsigned index) const{
        return tomb[index];
    }
    void print() const{
        cout << "(" << tomb[0] << ";" << tomb[1] << ";" << tomb[2] << ")" << endl;
    }
};

IntVektor operator + (const int szam, const IntVektor& vekt)
{
    return{
      vekt[0] + szam,vekt[1] + szam, vekt[2] + szam

    };
}

IntVektor operator *(const IntVektor vekt, const int szor)
{
    return {vekt[0] * szor, vekt[1]*szor,vekt[2]*szor};
}

int operator * (const IntVektor second)
{

    int negyzet2 = second[0] * second[0] + second[1]*second[1] + second[2]*second[2];

    return negyzet2;
}

IntVektor operator -(const IntVektor a,const IntVektor b)
{
    return
    {
        a[0] - b[0], a[1]-b[1], a[2]-b[2]
    };
}

void operator -=(IntVektor& a, int szam)
{
    a[0] -= szam;
    a[1] -= szam;
    a[2] -= szam;

}

void operator *=(IntVektor& bal, IntVektor& jobb)
{
    bal[0] *= jobb[0];
    bal[1] *= jobb[1];
    bal[2] *= jobb[2];
}



int main()
{
    IntVektor vec0(6, 56, 54);
    IntVektor vec1(47, 26, 42);
    IntVektor vec2(48, 58, 24);
    IntVektor vec3(46, 54, 37);
    IntVektor vec4(67, 44, 43);
    IntVektor vec5(9, 6, 22);
    IntVektor vec6(44, 17, 44);
    IntVektor vec7(39, 53, 24);

    {
        IntVektor tmp=101+vec7;
        tmp.print();
    }
    {
        IntVektor tmp=vec6*31;
        tmp.print();
    }
    {
        int tmp=*vec1;
        cout << tmp << endl;
    }
    {
        IntVektor tmp=vec4-vec2;
        tmp.print();
    }
    {
        vec3-=55;
        vec3.print();
    }
    {
        vec5*=vec0;
        vec5.print();
    }

    return 0;
}
