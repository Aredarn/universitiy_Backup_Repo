#ifndef SZEMELY_H
#define SZEMELY_H

#include <string>
using namespace std;

class Szemely
{
    string nev;
    int eletkor;
public:
    Szemely(const string& nev, int eletkor);
    const string &getNev() const;
    int getEletkor() const;
    void setEletkor(int newEletkor);

    // csak azert, hogy lehessen map kulcsakent hasznalni:
    bool operator < (const Szemely& masik) const;
};

#endif // SZEMELY_H
