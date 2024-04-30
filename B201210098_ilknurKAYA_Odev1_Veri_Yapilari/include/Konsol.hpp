#ifndef KONSOL_HPP
#define KONSOL_HPP
#include "YoneticiListesi.hpp"
#include "Pozisyon.hpp"
#define DisplayperOnePage 8
#define BeginOffset 0
enum sayfaYon
{
    upPage = 0,
    downPage = 1,
};
enum Yon
{
    up = 0,
    down = 1,
    refresh = 2,

};
class Konsol
{
private:
    YoneticiListesi *yonetici;
    int konum;
    int basla;
    int bitis;
    void kur();

public:
    Konsol(YoneticiListesi *yonetici);
    void kurKonum(Yon dr);
    void yazdirYoneticiListesi();
    void yazdirSatirListesi(int x, int y);
    void kurSayfa(sayfaYon pdr);
    void silYonetici();
    void silRandom(int randomIndex) throw(IndexOutOfBounds, ElemanYok);
    int randomSec() throw(IndexOutOfBounds, ElemanYok);
};
#endif