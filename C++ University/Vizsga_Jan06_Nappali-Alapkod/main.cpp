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
        cout << "1/a.-1/c. feladatok - beolvas(), szobaListazas(), foglalasListazas() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            h.szobaListazas();
            h.foglalasListazas();
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
        cout << "1/d. feladat - listakTorol() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            h.szobaListazas();
            h.foglalasListazas();
            h.listakTorol();
            h.szobaListazas();
            h.foglalasListazas();
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
        cout << "2. feladat - nagyLetszamu() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            int nagyDb = h.nagyLetszamu();
            cout << "Legalabb 5 fos foglalasbol " << nagyDb << " darab van." << endl;
            cout << endl;
        });
//		Legalabb 5 fos foglalasbol 3 darab van.
    }

    {
        cout << "3. feladat - osszesEjszakak() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            for (const string &szgid : {"754573EW", "121431LD", "621267LR", "324543WE", "481989WK"})
            {
                cout << "Osszes ejszakak szama a(z) " << szgid << " azonositoju foglalotol: " << h.osszesEjszakak(szgid) << "" << endl;
            }
            cout << endl;
        });
//		Osszes ejszakak szama a(z) 754573EW azonositoju foglalotol: 0
//		Osszes ejszakak szama a(z) 121431LD azonositoju foglalotol: 17
//		Osszes ejszakak szama a(z) 621267LR azonositoju foglalotol: 4
//		Osszes ejszakak szama a(z) 324543WE azonositoju foglalotol: 0
//		Osszes ejszakak szama a(z) 481989WK azonositoju foglalotol: 3
    }

    {
        cout << "4. feladat - osszesFoglalo() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            list<string> igazolvanyLista = h.osszesFoglalo();
            cout << "Osszes azonosito:";
            for (const string &id : igazolvanyLista) cout << " " << id;
            cout << endl;
            cout << endl;
        });
//		Osszes azonosito: 121431LD 123515GR 274324KD 481989WK 536346WE 621267LR 654254WE 958434IR
    }

    {
        cout << "5. feladat - szemelySzerint() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            map<string,list<Foglalas*>> szemelyMap = h.szemelySzerint();
            for (const auto &kvp : szemelyMap)
            {
                cout << kvp.first << ":";
                for (Foglalas *f : kvp.second)
                    cout << " " << f->getId();
                cout << endl;
            }
            cout << endl;
        });
//		121431LD: 3 5 8 9
//		123515GR: 7
//		274324KD: 1 6 10
//		481989WK: 2 11
//		536346WE: 12
//		621267LR: 13
//		654254WE: 14
//		958434IR: 4
    }

    {
        cout << "6. feladat - foglalasokSzobahoz() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            for (int id : {1, 2, 12, 31, 23, 21})
            {
                h.foglalasokSzobahoz(id);
            }
            cout << endl;
        });
//		Szoba: 1, foglalasok idorendben:
//		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
//		Szoba: 2, foglalasok idorendben:
//		Szoba: 12, foglalasok idorendben:
//		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
//		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
//		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
//		Szoba: 31, foglalasok idorendben:
//		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
//		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
//		Szoba: 23, foglalasok idorendben:
//		Szoba: 21, foglalasok idorendben:
//		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
//		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
    }

    {
        cout << "7. feladat - foglaltValamikorra() teszt" << endl << endl;
        Handler::futtatBiztos([&](){
            h.beolvas();
            for (const auto &datumok : list<pair<string,string>>({{"2022-05-11", "2022-05-15"}, {"2022-04-30", "2022-06-01"}, {"2022-06-02", "2022-08-12"}}))
            {
                list<string> van=h.foglaltValamikorra(datumok.first, datumok.second);
                cout << "Nekik van foglalasuk " << datumok.first << " es " << datumok.second << " kozott:";
                for (const string &id : van)
                    cout << " " << id;
                cout << endl;
            }
            cout << endl;
        });
//		Nekik van foglalasuk 2022-05-11 es 2022-05-15 kozott: 274324KD 481989WK 621267LR
//		Nekik van foglalasuk 2022-04-30 es 2022-06-01 kozott: 121431LD 274324KD 481989WK 536346WE 621267LR 654254WE
//		Nekik van foglalasuk 2022-06-02 es 2022-08-12 kozott: 121431LD 123515GR 274324KD 481989WK 958434IR
    }

//	{
//		cout << "8. feladat - ujFoglalas() teszt" << endl << endl;
//		Handler::futtatBiztos([&](){
//			h.beolvas();
//			h.ujFoglalas("324325FD", 2, "2022-09-12", "2022-09-13", 1, 23);
//			h.ujFoglalas("543246LR", 1, "2022-09-06", "2022-09-08", 2, 25);
//			h.ujFoglalas("322814WE", 3, "2022-09-16", "2022-09-20", 4, 11);
//			h.ujFoglalas("741547RE", 6, "2022-09-21", "2022-09-27", 6, 2);
//			h.beolvas();
//			h.foglalasListazas();
//			cout << endl;
//		});
////		Foglalasok:
////		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
////		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
////		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
////		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
////		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
////		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
////		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
////		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
////		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
////		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
////		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
////		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
////		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
////		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
////		  (15) foglalo: 324325FD, 2 fo, idotartam: 2022-09-12 - 2022-09-13 (1 ejszaka), szoba: 23
////		  (16) foglalo: 543246LR, 1 fo, idotartam: 2022-09-06 - 2022-09-08 (2 ejszaka), szoba: 25
////		  (17) foglalo: 322814WE, 3 fo, idotartam: 2022-09-16 - 2022-09-20 (4 ejszaka), szoba: 11
////		  (18) foglalo: 741547RE, 6 fo, idotartam: 2022-09-21 - 2022-09-27 (6 ejszaka), szoba: 2
//	}

//	{
//		cout << "8. feladat - ujFoglalas() teszt" << endl << endl;
//		Handler::futtatBiztos([&](){
//			h.beolvas();
//			try
//			{
//				h.ujFoglalas("321432DS", 5, "2022-10-12", "2022-10-13", 1, 1);
//				h.ujFoglalas("127623RE", 4, "2022-10-06", "2022-10-08", 2, 13);
//				h.ujFoglalas("517567EE", 2, "2022-10-16", "2022-10-20", 4, 33);
//				h.ujFoglalas("168763LT", 6, "2022-10-21", "2022-10-27", 6, 2);
//			}
//			catch (exception &e)
//			{
//				cout << "std::exception:" << endl;
//				cout << e.what() << endl;
//			}
//			h.beolvas();
//			h.foglalasListazas();
//			cout << endl;
//		});
////		std::exception:
////		Nincs szoba ilyen azonositoval: 33
////		Foglalasok:
////		  (1) foglalo: 274324KD, 4 fo, idotartam: 2022-05-12 - 2022-05-16 (4 ejszaka), szoba: 12
////		  (2) foglalo: 481989WK, 3 fo, idotartam: 2022-06-05 - 2022-06-06 (1 ejszaka), szoba: 11
////		  (3) foglalo: 121431LD, 6 fo, idotartam: 2022-04-25 - 2022-04-30 (5 ejszaka), szoba: 31
////		  (4) foglalo: 958434IR, 5 fo, idotartam: 2022-08-05 - 2022-08-07 (2 ejszaka), szoba: 1
////		  (5) foglalo: 121431LD, 2 fo, idotartam: 2022-08-06 - 2022-08-10 (4 ejszaka), szoba: 21
////		  (6) foglalo: 274324KD, 2 fo, idotartam: 2022-05-12 - 2022-05-20 (8 ejszaka), szoba: 21
////		  (7) foglalo: 123515GR, 6 fo, idotartam: 2022-07-11 - 2022-07-15 (4 ejszaka), szoba: 31
////		  (8) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 12
////		  (9) foglalo: 121431LD, 4 fo, idotartam: 2022-07-08 - 2022-07-12 (4 ejszaka), szoba: 13
////		  (10) foglalo: 274324KD, 2 fo, idotartam: 2022-08-08 - 2022-08-11 (3 ejszaka), szoba: 25
////		  (11) foglalo: 481989WK, 3 fo, idotartam: 2022-05-15 - 2022-05-17 (2 ejszaka), szoba: 14
////		  (12) foglalo: 536346WE, 4 fo, idotartam: 2022-05-16 - 2022-05-21 (5 ejszaka), szoba: 12
////		  (13) foglalo: 621267LR, 4 fo, idotartam: 2022-05-14 - 2022-05-18 (4 ejszaka), szoba: 13
////		  (14) foglalo: 654254WE, 4 fo, idotartam: 2022-05-16 - 2022-05-19 (2 ejszaka), szoba: 32
////		  (15) foglalo: 324325FD, 2 fo, idotartam: 2022-09-12 - 2022-09-13 (1 ejszaka), szoba: 23
////		  (16) foglalo: 543246LR, 1 fo, idotartam: 2022-09-06 - 2022-09-08 (2 ejszaka), szoba: 25
////		  (17) foglalo: 322814WE, 3 fo, idotartam: 2022-09-16 - 2022-09-20 (4 ejszaka), szoba: 11
////		  (18) foglalo: 741547RE, 6 fo, idotartam: 2022-09-21 - 2022-09-27 (6 ejszaka), szoba: 2
////		  (19) foglalo: 321432DS, 5 fo, idotartam: 2022-10-12 - 2022-10-13 (1 ejszaka), szoba: 1
////		  (20) foglalo: 127623RE, 4 fo, idotartam: 2022-10-06 - 2022-10-08 (2 ejszaka), szoba: 13
//	}


    cout << "main() vege!" << endl;
    return 0;
}
