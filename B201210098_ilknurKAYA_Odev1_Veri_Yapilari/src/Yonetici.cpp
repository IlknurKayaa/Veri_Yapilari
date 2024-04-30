#include "Yonetici.hpp"
using namespace std;
Yonetici::Yonetici(SatirListesi *sayi, Yonetici *sonrakiy, Yonetici *oncekiy)
{
    this->sayi = sayi;
    this->sonrakiy = sonrakiy;
    this->oncekiy = oncekiy;
    this->ortalama = ortHesapla();
}
Yonetici::Yonetici(SatirListesi *sayi)
{
    this->sayi = sayi;
    this->sonrakiy = sonrakiy;
    this->oncekiy = oncekiy;
    this->ortalama = ortHesapla();
}
Yonetici::Yonetici(SatirListesi *sayi, Yonetici *sonrakiy)
{
    this->sayi = sayi;
    this->sonrakiy = sonrakiy;
    this->oncekiy = oncekiy;
    this->ortalama = ortHesapla();
}
double Yonetici::ortHesapla()
{
    double toplam = 0;
    if (this->sayi->bosMu())
        return toplam;

    int say = this->sayi->Say();
    for (int i = 0; i < say; ++i)
    {
        toplam += this->sayi->elemanAt(i);
    }
    return toplam / say;
}