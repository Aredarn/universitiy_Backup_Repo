#include <iostream>
#include "vektor.h"

using namespace std;

void vektorKiir(const Vektor &v)
{
	cout << "(";
	for (unsigned int i=0; i<v.getDarab(); i++)
	{
		if (i>0) cout << " , ";
		cout << v.getElem(i);
	}
	cout << ")" << endl;
}

int main()
{
	// Vektor teszt: alapkód
	cout << endl;
	cout << "Vektor teszt: alapkod" << endl;
	Vektor v1(4);
	v1.setElem(0,3.5);
	v1.setElem(1,-6.3);
	v1.setElem(2,2.4);
	v1.setElem(3,15);
	vektorKiir(v1); // (3.5 , -6.3 , 2.4 , 15)
	Vektor v2(v1);
	vektorKiir(v2); // (3.5 , -6.3 , 2.4 , 15)
	Vektor v3(4), v4(4), v5(4), v6(4);
	v3.setElem(0,52.3);
	v3.setElem(1,52.4);
	v3.setElem(2,52.5);
	v3.setElem(3,52.6);
	v4.setElem(0,-2.3);
	v4.setElem(1,-23);
	v4.setElem(2,-25);
	v4.setElem(3,-41);
	v5.setElem(0,5.6);
	v5.setElem(1,2.4);
	v5.setElem(2,1.9);
	v5.setElem(3,-4);
	v6.setElem(0,-2);
	v6.setElem(1,-1.6);
	v6.setElem(2,1.9);
	v6.setElem(3,7.6);
	vektorKiir(v3); // (52.3 , 52.4 , 52.5 , 52.6)
	vektorKiir(v4); // (-2.3 , -23 , -25 , -41)
	vektorKiir(v5); // (5.6 , 2.4 , 1.9 , -4)
	vektorKiir(v6); // (-2 , -1.6 , 1.9 , 7.6)

    // Vektor teszt: + operátor
//    cout << endl;
//    cout << "Vektor teszt: operator +" << endl;
//    Vektor v7=v1+v3;
//    vektorKiir(v7); // (55.8 , 46.1 , 54.9 , 67.6)

//	// Vektor teszt: += operátor
    cout << endl;
    cout << "Vektor teszt: operator +=" << endl;
    Vektor v8(v4);
    v8+=v2;
    vektorKiir(v8); // (1.2 , -29.3 , -22.6 , -26)
    Vektor v9(v1);
    v8+=v9+=v6; // Először v9+=v6, majd v8+=v9, ahol a v9 már a módosult vektor.
    vektorKiir(v8); // (2.7 , -37.2 , -18.3 , -3.4)
    vektorKiir(v9); // (1.5 , -7.9 , 4.3 , 22.6)

    // Vektor teszt: + operátor számmal balról
    cout << endl;
    cout << "Vektor teszt: operator + szammal balrol" << endl;
    Vektor v10=4.5+v4;
    vektorKiir(v10); // (2.2 , -18.5 , -20.5 , -36.5)

    // Vektor teszt: = operátor
    cout << endl;
    cout << "Vektor teszt: operator =" << endl;
    Vektor v11(3);
    v11=v3;
    vektorKiir(v11); // (52.3 , 52.4 , 52.5 , 52.6)
//    v11=v11; // Ez nem csinál semmit.
    vektorKiir(v11); // (52.3 , 52.4 , 52.5 , 52.6)
    Vektor v12(5);
    v12=v11=v6; // Mindegyik a v6 lesz, a v11-gyel kezdve.
    vektorKiir(v11); // (-2 , -1.6 , 1.9 , 7.6)
    vektorKiir(v12); // (-2 , -1.6 , 1.9 , 7.6)

//	// Vektor teszt: -- operátor
//	cout << endl;
    cout << "Vektor teszt: operator --" << endl;
    Vektor v13(v5);
//	v13--;
    vektorKiir(v13); // (4.6 , 1.4 , 0.9 , -5)
    --v13;
    vektorKiir(v13); // (3.6 , 0.4 , -0.1 , -6)

//	// Vektor teszt: << operátor
//	cout << endl;
//	cout << "Vektor teszt: operator <<" << endl;
//	cout << v1; // (3.5 , -6.3 , 2.4 , 15)
//	cout << endl;
//	cout << v2 << endl; // (3.5 , -6.3 , 2.4 , 15)
//	cout << v3 << endl << v4 << endl << v5 << endl << v6 << endl;	// (52.3 , 52.4 , 52.5 , 52.6)
//																	// (-2.3 , -23 , -25 , -41)
//																	// (5.6 , 2.4 , 1.9 , -4)
//																	// (-2 , -1.6 , 1.9 , 7.6)

//	// Vektor teszt: -, *, /, -=, *=, /= operátorok
//	cout << endl;
//	cout << "Vektor teszt: operator -, *, /, -=, *=, /=" << endl;
//	Vektor v14=v1-v3;
//	Vektor v15=v1*v3;
//	Vektor v16=v1/v3;
//	vektorKiir(v14); // (-48.8 , -58.7 , -50.1 , -37.6)
//	vektorKiir(v15); // (183.05 , -330.12 , 126 , 789)
//	vektorKiir(v16); // (0.0669216 , -0.120229 , 0.0457143 , 0.285171)
//	v14-=v2;
//	vektorKiir(v14); // (-52.3 , -52.4 , -52.5 , -52.6)
//	v14*=v4;
//	vektorKiir(v14); // (120.29 , 1205.2 , 1312.5 , 2156.6)
//	v14/=v5;
//	vektorKiir(v14); // (21.4804 , 502.167 , 690.789 , -539.15)
//	Vektor v17=5-v4;
//	Vektor v18=5*v4;
//	Vektor v19=5/v4;
//	vektorKiir(v17); // (7.3 , 28 , 30 , 46)
//	vektorKiir(v18); // (-11.5 , -115 , -125 , -205)
//	vektorKiir(v19); // (-2.17391 , -0.217391 , -0.2 , -0.121951)

//	// Vektor teszt: +, -, *, / operátorok számmal jobbról
//	cout << endl;
//	cout << "Vektor teszt: operator +, -, *, / szammal jobbrol" << endl;
//	Vektor v20=v3+2.5;
//	Vektor v21=v3-2.5;
//	Vektor v22=v3*2.5;
//	Vektor v23=v3/2.5;
//	vektorKiir(v20); // (54.8 , 54.9 , 55 , 55.1)
//	vektorKiir(v21); // (49.8 , 49.9 , 50 , 50.1)
//	vektorKiir(v22); // (130.75 , 131 , 131.25 , 131.5)
//	vektorKiir(v23); // (20.92 , 20.96 , 21 , 21.04)

//	// Vektor teszt: -- operátor
//	cout << endl;
//	cout << "Vektor teszt: operator --" << endl;
//	Vektor v24(v5);
//	v24++;
//	vektorKiir(v24); // (6.6 , 3.4 , 2.9 , -3)
//	++v24;
//	vektorKiir(v24); // (7.6 , 4.4 , 3.9 , -2)

//	// Vektor teszt: [] operátor
//	cout << endl;
//	cout << "Vektor teszt: operator []" << endl;
//	Vektor v25(v2);
//	cout << v25[0] << " " << v25[2] << endl; // 3.5 2.4
//	v25[0]=0.6;
//	v25[2]=1.5;
//	cout << v25[0] << " " << v25[2] << endl; // 0.6 1.5
//	vektorKiir(v25); // (0.6 , -6.3 , 1.5 , 15)
//	const Vektor &v26=v2;
//	cout << v26[0] << " " << v26[2] << endl; // 3.5 2.4
//	vektorKiir(v26); // (3.5 , -6.3 , 2.4 , 15)

//	// Vektor teszt: ^ operátor
//	cout << endl;
//	cout << "Vektor teszt: operator ^" << endl;
//	double res1=v1^v4;
//	cout << res1 << endl; // -538.15

//	// Vektor teszt: unáris * operátor
//	cout << endl;
//	cout << "Vektor teszt: unaris operator *" << endl;
//	double res2=*v4;
//	cout << res2 << endl; // 53.2944

//	// Vektor teszt: unáris ~ operátor
//	cout << endl;
//	cout << "Vektor teszt: unaris operator ~" << endl;
//	Vektor v27=~v4;
//	vektorKiir(v27); // (-0.0431565 , -0.431565 , -0.469093 , -0.769312)
//	// Gyorsan megnézzük, hogy a hossza tényleg 1 lett-e
//	cout << *v27 << endl; // 1

//	// Vektor teszt: == operátor
//	cout << endl;
//	cout << "Vektor teszt: operator ==" << endl;
//	bool res3=(v1==v2);
//	bool res4=(v3==v4);
//	cout << res3 << endl; // 1
//	cout << res4 << endl; // 0

//	// Vektor teszt: != operátor
//	cout << endl;
//	cout << "Vektor teszt: operator !=" << endl;
//	bool res5=(v1!=v2);
//	bool res6=(v3!=v4);
//	cout << res5 << endl; // 0
//	cout << res6 << endl; // 1

//	// Vektor teszt: < operátor
//	cout << endl;
//	cout << "Vektor teszt: operator <" << endl;
//	bool res7=(v1<v3);
//	bool res8=(v6<v3);
//	bool res9=(v4<v2);
//	bool res10=(v4<v5);
//	bool res11=(v1<v5);
//	bool res12=(v6<v2);
//	cout << res7 << endl; // 1
//	cout << res8 << endl; // 1
//	cout << res9 << endl; // 1
//	cout << res10 << endl; // 1
//	cout << res11 << endl; // 0
//	cout << res12 << endl; // 0
	return 0;
}
