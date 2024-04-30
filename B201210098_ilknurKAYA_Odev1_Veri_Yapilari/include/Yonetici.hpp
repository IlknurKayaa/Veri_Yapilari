#ifndef YONETICI_HPP
#define YONETICI_HPP
#include "SatirListesi.hpp"
class Yonetici
{
public:
    Yonetici *sonrakiy;
    Yonetici *oncekiy;
    SatirListesi *sayi;
    double ortalama;
    double ortHesapla();
    Yonetici(SatirListesi *sayi);
    Yonetici(SatirListesi *sayi, Yonetici *sonrakiy);
    Yonetici(SatirListesi *sayi, Yonetici *sonrakiy, Yonetici *oncekiy);
};
#endif
