#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP
#include "Liste.hpp"
#include "ElemanYok.hpp"
#include <iomanip>
class SatirListesi
{
private:
    Liste *ilk;
    int boyut;
    Liste *KonumBulS(int a) throw(ElemanYok);

public:
    SatirListesi();
    int Say() const;
    const int &ilkMi() throw(ElemanYok);
    const int &sonMu() throw(ElemanYok);
    bool bosMu() const;
    void ekleA(const int &item);
    void ekleB(int a, const int &item);
    void removeAt(int a);
    void silA(const int &item);
    void konumdanTersYazdir(int a) throw(ElemanYok);
    void tersYazdir();
    int indexOf(const int &item) throw(ElemanYok);
    bool araBul(const int &item);
    void tersle();
    const int &elemanAt(int a) throw(ElemanYok);
    void silSupur();
    void yazdirSatirListesi(int x, int y);
    friend ostream &operator<<(ostream &screen, SatirListesi &rgt);
    ~SatirListesi();
};
#endif