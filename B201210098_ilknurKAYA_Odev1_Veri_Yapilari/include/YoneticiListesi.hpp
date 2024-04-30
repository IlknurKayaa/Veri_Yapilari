#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP
#include <iostream>
#include "SatirListesi.hpp"
#include "Yonetici.hpp"
#include <stdlib.h>
#include <time.h>
#include "IndexOutOfBounds.hpp"
#include "Pozisyon.hpp"

class YoneticiListesi
{
private:
    Yonetici *ilky;
    int boyuty;
    Yonetici *KonumBulY(int a) throw(ElemanYok);
    Yonetici *OnceKonumBulY(int a) throw(ElemanYok);

public:
    YoneticiListesi();
    int sayY() const;
    bool bosMuY() const;
    SatirListesi *&ilks() throw(ElemanYok);
    SatirListesi *&sons() throw(ElemanYok);
    void ekleAY(SatirListesi *&item);
    void ekleBY(int a, SatirListesi *&item);
    void silAY(SatirListesi *&item);
    void rndremoveAtSatir(int a, int inlineIndex) throw(IndexOutOfBounds, ElemanYok);
    void removeAt(int a);
    SatirListesi *&elemanAt(int a) throw(ElemanYok);
    void git(int from, int to) throw(IndexOutOfBounds);
    bool bul(SatirListesi *&item);
    void tersiniAl();
    void ortalamaHesapla(int a);
    int randomSayi(int a) throw(IndexOutOfBounds, ElemanYok);
    void ortSira();
    int indexOf(SatirListesi *&item) throw(ElemanYok);
    void temizle();
    void yazdir(int a, int x, int y);
    void silDugum(int a);
    ~YoneticiListesi();
};

#endif
