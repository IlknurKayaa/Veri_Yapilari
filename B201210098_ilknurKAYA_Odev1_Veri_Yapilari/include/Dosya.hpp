#ifndef DOSYA_HPP
#define DOSYA_HPP
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
using namespace std;
class Dosya
{
private:
    string dosyaAdi;
    SatirListesi **satir;
    void satirOku();
    int satirSayisi();

public:
    Dosya(string);
    ~Dosya();
    YoneticiListesi *GetFillYoneticiListesi();
};
#endif
