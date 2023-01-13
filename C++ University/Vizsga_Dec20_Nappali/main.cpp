#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "handler.h"

int main()
{
    cout << "main() eleje!" << endl << endl;

	const string db_hasznalt = "foglalasok.sqlite";
	const string db_eredeti = "foglalasok-eredeti.sqlite";
    {
        std::ifstream be(db_eredeti, std::ios::binary);
        if (!be.is_open())
        {
            cout << "Hiba! Nem sikerult megnyitni: " << db_eredeti << endl;
            cout << "(Jo helyre lett masolva a fajl?)" << endl << endl;
            return 1;
        }
        std::ofstream ki(db_hasznalt, std::ios::binary);
        if (!ki.is_open())
        {
            cout << "Hiba! Nem sikerult irasra megnyitni: " << db_hasznalt << endl;
            cout << "Az adatbazis igy nem all keszen a munkara." << endl << endl;
            return 1;
        }
        ki << be.rdbuf();
        be.close();
        ki.close();
    }

    Handler h;
    {
        cout << "Adatbazis teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.csatlakozas(db_hasznalt);
            h.teszt();
        });
    }
    // (...egyeb szoveg...)
	// Rekordok szama: 13
    // Jo munkat!

    {
        cout << "1/a.-1/c. feladatok - betoltes(), listazSzobak(), listazFoglalasok(0) teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            h.listazSzobak();
            h.listazFoglalasok();
            cout << endl;
        });
//		Szobak:
//		  (1) 0. emelet, 1. ajto, 5 ferohely
//		  (2) 0. emelet, 2. ajto, 6 ferohely
//		  (11) 1. emelet, 1. ajto, 3 ferohely
//		  (12) 1. emelet, 2. ajto, 4 ferohely
//		  (13) 1. emelet, 3. ajto, 4 ferohely
//		  (14) 1. emelet, 4. ajto, 3 ferohely
//		  (21) 2. emelet, 1. ajto, 2 ferohely
//		  (22) 2. emelet, 2. ajto, 3 ferohely
//		  (23) 2. emelet, 3. ajto, 2 ferohely
//		  (24) 2. emelet, 4. ajto, 3 ferohely
//		  (25) 2. emelet, 5. ajto, 2 ferohely
//		  (31) 3. emelet, 1. ajto, 6 ferohely
//		  (32) 3. emelet, 2. ajto, 5 ferohely
//		Foglalasok:
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
//		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
//		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
//		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
    }

    {
        cout << "1/d. feladat - mindentTorol() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            h.listazSzobak();
            h.listazFoglalasok();
            h.mindentTorol();
            h.listazSzobak();
            h.listazFoglalasok();
            cout << endl;
        });
//		Szobak:
//		  (1) 0. emelet, 1. ajto, 5 ferohely
//		  (2) 0. emelet, 2. ajto, 6 ferohely
//		  (11) 1. emelet, 1. ajto, 3 ferohely
//		  (12) 1. emelet, 2. ajto, 4 ferohely
//		  (13) 1. emelet, 3. ajto, 4 ferohely
//		  (14) 1. emelet, 4. ajto, 3 ferohely
//		  (21) 2. emelet, 1. ajto, 2 ferohely
//		  (22) 2. emelet, 2. ajto, 3 ferohely
//		  (23) 2. emelet, 3. ajto, 2 ferohely
//		  (24) 2. emelet, 4. ajto, 3 ferohely
//		  (25) 2. emelet, 5. ajto, 2 ferohely
//		  (31) 3. emelet, 1. ajto, 6 ferohely
//		  (32) 3. emelet, 2. ajto, 5 ferohely
//		Foglalasok:
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
//		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
//		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
//		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
//		Szobak:
//		Foglalasok:
    }

    {
        cout << "2. feladat - maxletszam() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            Foglalas *maxl = h.maxletszam();
            cout << "Legnagyobb letszamu foglalas: " << maxl->getId() << " (" << maxl->getLetszam() << ") " << endl;
            cout << endl;
        });
//		Legnagyobb letszamu foglalas: 3 (6)
    }

    {
        cout << "3. feladat - foglalasokSzama() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            for (int szobaId : {14, 21, 1, 31, 25})
            {
                cout << "Foglalasok szama a(z) " << szobaId << " szobahoz: " << h.foglalasokSzama(szobaId) << " db" << endl;
            }
            cout << endl;
        });
//		Foglalasok szama a(z) 14 szobahoz: 1 db
//		Foglalasok szama a(z) 21 szobahoz: 2 db
//		Foglalasok szama a(z) 1 szobahoz: 1 db
//		Foglalasok szama a(z) 31 szobahoz: 2 db
//		Foglalasok szama a(z) 25 szobahoz: 1 db
    }

    {
        cout << "4. feladat - szobakSzerint() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            map<Szoba*,list<Foglalas*>> szobaMap = h.szobakSzerint();
            for (const auto &kvp : szobaMap)
            {
                cout << kvp.first->getId() << ":";
                for (Foglalas *f : kvp.second)
                    cout << " " << f->getId();
                cout << endl;
            }
            cout << endl;
        });
        /*** A kimeneten itt a sorrend lehet, hogy más lesz ***/
//		25: 10
//		31: 3 7
//		13: 9 13
//		32: 14
//		12: 1 8 12
//		22:
//		23:
//		14: 11
//		11: 2
//		24:
//		21: 5 6
//		1: 4
//		2:
    }

    {
        cout << "5. feladat - szobaFoglaltsag() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            h.szobaFoglaltsag();
            cout << endl;
        });
        /*** A kimeneten itt a sorrend lehet, hogy más lesz ***/
//		Szoba: 12, osszes ejszakak: 13
//		Szoba: 24, osszes ejszakak: 0
//		Szoba: 11, osszes ejszakak: 1
//		Szoba: 13, osszes ejszakak: 8
//		Szoba: 23, osszes ejszakak: 0
//		Szoba: 14, osszes ejszakak: 2
//		Szoba: 31, osszes ejszakak: 9
//		Szoba: 25, osszes ejszakak: 3
//		Szoba: 32, osszes ejszakak: 2
//		Szoba: 21, osszes ejszakak: 12
//		Szoba: 22, osszes ejszakak: 0
//		Szoba: 2, osszes ejszakak: 0
//		Szoba: 1, osszes ejszakak: 2
    }

    {
        cout << "6. feladat - idorendben() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            h.idorendben();
            cout << endl;
        });
//		Foglalasok idorendben:
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
//		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
//		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
//		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
    }

//	{
//		cout << "7. feladat - szabadSzobak() teszt" << endl << endl;
//		Handler::futtatBiztos([&](){
//			h.betoltes();
//			for (const auto &datumok : list<pair<string,string>>({{"2022-05-11", "2022-05-15"}, {"2022-04-30", "2022-06-01"}, {"2022-06-02", "2022-08-12"}}))
//			{
//				list<Szoba*> szabad=h.szabadSzobak(datumok.first, datumok.second);
//				cout << "Szabad " << datumok.first << " es " << datumok.second << " kozott:";
//				for (Szoba *sz : szabad)
//					cout << " " << sz->getId();
//				cout << endl;
//			}
//			cout << endl;
//		});
////		Szabad 2022-05-11 es 2022-05-15 kozott: 1 2 11 14 22 23 24 25 31 32
////		Szabad 2022-04-30 es 2022-06-01 kozott: 1 2 11 22 23 24 25 31
////		Szabad 2022-06-02 es 2022-08-12 kozott: 2 14 22 23 24 32
//	}

    {
        cout << "7/a. feladat - szabadSzobak() harmadik parameter teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            for (const auto &datumok : list<pair<string,string>>({{"2022-05-11", "2022-05-15"}, {"2022-04-30", "2022-06-01"}, {"2022-06-02", "2022-08-12"}}))
            {
                list<Szoba*> szabad=h.szabadSzobak(datumok.first, datumok.second, 4);
                cout << "Szabad " << datumok.first << " es " << datumok.second << " kozott legalabb 4 fore:";
                for (Szoba *sz : szabad)
                    cout << " " << sz->getId();
                cout << endl;
            }
            cout << endl;
        });
//		Szabad 2022-05-11 es 2022-05-15 kozott legalabb 4 fore: 1 2 31 32
//		Szabad 2022-04-30 es 2022-06-01 kozott legalabb 4 fore: 1 2 31
//		Szabad 2022-06-02 es 2022-08-12 kozott legalabb 4 fore: 2 32
    }

    {
        cout << "8. feladat - ujFoglalas() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            h.ujFoglalas("324325FD", 2, "2022-09-12", "2022-09-13", 1, 23);
            h.ujFoglalas("543246LR", 1, "2022-09-06", "2022-09-08", 2, 25);
            h.ujFoglalas("322814WE", 3, "2022-09-16", "2022-09-20", 4, 11);
            h.ujFoglalas("741547RE", 6, "2022-09-21", "2022-09-27", 6, 2);
            h.betoltes();
            h.listazFoglalasok();
            cout << endl;
        });
//		Foglalasok:
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
//		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
//		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
//		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
//		  (15) foglalo: 324325FD, 2 fo, idotartam: 2022-09-12 - 2022-09-13 (1 ejszaka), szoba: 23
//		  (16) foglalo: 543246LR, 1 fo, idotartam: 2022-09-06 - 2022-09-08 (2 ejszaka), szoba: 25
//		  (17) foglalo: 322814WE, 3 fo, idotartam: 2022-09-16 - 2022-09-20 (4 ejszaka), szoba: 11
//		  (18) foglalo: 741547RE, 6 fo, idotartam: 2022-09-21 - 2022-09-27 (6 ejszaka), szoba: 2
    }

    {
        cout << "8. feladat - ujFoglalas() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.betoltes();
            try
            {
                h.ujFoglalas("321432DS", 5, "2022-10-12", "2022-10-13", 1, 1);
                h.ujFoglalas("127623RE", 4, "2022-10-06", "2022-10-08", 2, 13);
                h.ujFoglalas("517567EE", 2, "2022-10-16", "2022-10-20", 4, 33);
                h.ujFoglalas("168763LT", 6, "2022-10-21", "2022-10-27", 6, 2);
            }
            catch (exception &e)
            {
                cout << "std::exception:" << endl;
                cout << e.what() << endl;
            }
            h.betoltes();
            h.listazFoglalasok();
            cout << endl;
        });
//		std::exception:
//		Nincs szoba ilyen azonositoval: 33
//		Foglalasok:
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
//		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
//		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
//		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
//		  (15) foglalo: 324325FD, 2 fo, idotartam: 2022-09-12 - 2022-09-13 (1 ejszaka), szoba: 23
//		  (16) foglalo: 543246LR, 1 fo, idotartam: 2022-09-06 - 2022-09-08 (2 ejszaka), szoba: 25
//		  (17) foglalo: 322814WE, 3 fo, idotartam: 2022-09-16 - 2022-09-20 (4 ejszaka), szoba: 11
//		  (18) foglalo: 741547RE, 6 fo, idotartam: 2022-09-21 - 2022-09-27 (6 ejszaka), szoba: 2
//		  (19) foglalo: 321432DS, 5 fo, idotartam: 2022-10-12 - 2022-10-13 (1 ejszaka), szoba: 1
//		  (20) foglalo: 127623RE, 4 fo, idotartam: 2022-10-06 - 2022-10-08 (2 ejszaka), szoba: 13
    }


    cout << "main() vege!" << endl;
    return 0;
}
