#ifndef EPICTOOLBOX_H
#define EPICTOOLBOX_H

namespace Tarolo{
class EpicToolBox
{

    int *tomb;

    public:
        unsigned meret;
        EpicToolBox();
        EpicToolBox(unsigned _meret);
        ~EpicToolBox();
        void kiir() const;
        void hozzaad(int szam);
        int atlag() ;

    protected:

    private:
};


}
#endif // EPICTOOLBOX_H
