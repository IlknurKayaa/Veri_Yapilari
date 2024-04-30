#include "Dosya.hpp"
using namespace std;
YoneticiListesi *Dosya::GetFillYoneticiListesi()
{
    satirOku();
    YoneticiListesi *tmp = new YoneticiListesi();
    int say = satirSayisi();
    for (int i = 0; i < say; ++i)
    {
        tmp->ekleAY(this->satir[i]);
    }
    return tmp;
}
Dosya::Dosya(string dosyaAdi)
{
    this->dosyaAdi = dosyaAdi;
    int satirNo = satirSayisi();
    this->satir = new SatirListesi *[satirNo];
    for (int i = 0; i < satirNo; i++)
    {
        this->satir[i] = new SatirListesi();
    }
}
int Dosya::satirSayisi()
{
    int say = 0;
    ifstream file(this->dosyaAdi);
    string unused;
    while (getline(file, unused))
        ++say;
    file.close();
    return say;
}
void Dosya::satirOku()
{
    string ayir;
    ifstream file(this->dosyaAdi);
    string str;
    int a = 0;
    while (getline(file, ayir))
    {
        istringstream ss(ayir);

        while (getline(ss, str, ' '))
        {
            this->satir[a]->ekleA(stoi(str));
        }
        a++;
    }
    file.close();
}
Dosya::~Dosya()
{
    if (satir != 0)
    {
        int say = satirSayisi();
        for (int i = 0; i < say; i++)
        {
            if (satir[i] != 0)
                delete satir[i];
        }
        delete[] satir;
    }
}
