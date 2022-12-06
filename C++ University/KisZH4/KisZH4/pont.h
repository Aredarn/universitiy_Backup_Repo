#ifndef PONT_H
#define PONT_H

// Egy foldrajzi pont koordinatait tarolja.
//   - latitude: esz (eszaki) szelesseg
//   - longitude: kh (keleti) hosszusag
//
// Az adattagok publikusak!
//
// Peldaul Budapest, N47.498333°, E19.040833°
//   -> eszaki szelesseg 47.498333 fok
//   -> keleti hosszusag 19.040833 fok
struct Pont
{
public:
	double esz, kh;
public:
    Pont();
    Pont(double esz, double kh);
	double lat () const;
	double lon () const;

    // visszaadja a foldrajzi pont tavolsagat egy masiktol
    // km-ben, legvonalban
    double tavolsag (const Pont& masik) const;
};

#endif // PONT_H
