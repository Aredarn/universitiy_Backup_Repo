#ifndef DOLGOZAT_H
#define DOLGOZAT_H
#include <iostream>
#include <string.h>

#define PART1
#define PART1a
#define PART1b
#define PART2
#define PART2a
#define PART2b
#define PART3
#define PART3a
#define PART3b
#define PART4
#define PART4a
#define PART4b
#define PART4c
#define PART4d
#define PART4e

using namespace std;

class Dolgozat
{
    string targyneve;
    int pontszam;
public:
    Dolgozat(string tnev, int pszam);
    const string &getTantargy() const;
    int getPontszam() const;
    virtual string tipus()const = 0;
    virtual int erdemjegy() const =0;
    virtual ~Dolgozat();

};

#endif // DOLGOZAT_H
