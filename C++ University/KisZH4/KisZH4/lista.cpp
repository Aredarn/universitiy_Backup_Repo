#include "lista.h"

void Lista::hozzaad(const Telepules &t)
{
    ls.push_back(t);
}

const list<Telepules>& Lista::getTartalom() const
{
    return ls;
}

void Lista::kiir() const
{
    cout << "Tartalom (" << ls.size() << " db):" << endl;
    for (const Telepules& t : ls)
    {
        cout << t.getId() << " ";
        cout << t.getNev() << " ";
        Pont p = t.getKoordinatak();
        cout << "N" << p.esz << " ";
        cout << "E" << p.kh;
        cout << endl;
    }
}
