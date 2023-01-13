#ifndef SZOBA_H
#define SZOBA_H

class Szoba
{
	int id, emelet, ajto, ferohelyek;
public:
	Szoba() = default;
	Szoba(int id, int emelet, int ajto, int ferohelyek);
	int getId() const;
	int getEmelet() const;
	int getAjto() const;
	int getFerohelyek() const;
};

#endif // SZOBA_H
