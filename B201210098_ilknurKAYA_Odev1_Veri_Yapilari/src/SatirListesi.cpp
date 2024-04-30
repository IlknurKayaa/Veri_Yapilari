#include "SatirListesi.hpp"
#include "Konsol.hpp"
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
SatirListesi::SatirListesi()
{
    ilk = NULL;
    boyut = 0;
}
Liste *SatirListesi::KonumBulS(int a) throw(ElemanYok)
{
    if (a < 0 || a > boyut)
        throw ElemanYok("Eleman yok.");
    Liste *prv = ilk;
    int i = 1;
    for (Liste *eleman = ilk; eleman->sonraki != NULL && i != a; eleman = eleman->sonraki, i++)
    {
        prv = prv->sonraki;
    }
    return prv;
}
int SatirListesi::Say() const
{
    return boyut;
}
const int &SatirListesi::ilkMi() throw(ElemanYok)
{
    if (bosMu())
        throw ElemanYok("Eleman yok");
    return ilk->sayi;
}
const int &SatirListesi::sonMu() throw(ElemanYok)
{
    if (bosMu())
        throw ElemanYok("Eleman yok");
    return KonumBulS(boyut)->sayi;
}
bool SatirListesi::bosMu() const
{
    return boyut == 0;
}
void SatirListesi::ekleA(const int &item)
{
    ekleB(boyut, item);
}
void SatirListesi::ekleB(int a, const int &item)
{
    if (a < 0 || a > boyut)
        throw "Eklenemez.";
    if (a == 0)
    {
        ilk = new Liste(item, ilk);
        if (ilk->sonraki != NULL)
            ilk->sonraki->onceki = ilk;
    }
    else
    {
        Liste *prv = KonumBulS(a);
        prv->sonraki = new Liste(item, prv->sonraki, prv);
        if (prv->sonraki->sonraki != NULL)
            prv->sonraki->sonraki->onceki = prv->sonraki;
    }
    boyut++;
}
void SatirListesi::removeAt(int a)
{
    if (a < 0 || a >= boyut)
        throw "Silinemez.";
    Liste *del;
    if (a == 0)
    {
        del = ilk;
        ilk = ilk->sonraki;
        if (ilk != NULL)
            ilk->onceki = NULL;
    }
    else
    {
        Liste *prv = KonumBulS(a);
        del = prv->sonraki;
        prv->sonraki = del->sonraki;
        if (del->sonraki != NULL)
            del->sonraki->onceki = prv;
    }
    boyut--;
    delete del;
}
void SatirListesi::silA(const int &item)
{
    int a = indexOf(item);
    removeAt(a);
}
void SatirListesi::konumdanTersYazdir(int a) throw(ElemanYok)
{
    if (a < 0 || a >= boyut)
        throw ElemanYok("Eleman yok.");
    for (Liste *eleman = KonumBulS(a + 1); eleman != NULL; eleman = eleman->onceki)
    {

        cout << eleman->sayi << " <-> ";
    }
    cout << endl;
}
void SatirListesi::tersYazdir()
{
    konumdanTersYazdir(boyut - 1);
}
int SatirListesi::indexOf(const int &item) throw(ElemanYok)
{
    int a = 0;
    for (Liste *eleman = ilk; eleman != NULL; eleman = eleman->sonraki)
    {
        if (eleman->sayi == item)
            return a;
        a++;
    }
    throw ElemanYok("Eleman yok.");
}
bool SatirListesi::araBul(const int &item)
{
    for (Liste *eleman = ilk; eleman != NULL; eleman = eleman->sonraki)
    {
        if (eleman->sayi == item)
            return true;
    }
    return false;
}
void SatirListesi::tersle()
{
    for (Liste *eleman = ilk; eleman != NULL;)
    {
        Liste *tmp = eleman->sonraki;
        eleman->sonraki = eleman->onceki;
        eleman->onceki = tmp;
        if (tmp == NULL)
        {
            ilk = eleman;
            break;
        }
        eleman = tmp;
    }
}
const int &SatirListesi::elemanAt(int a) throw(ElemanYok)
{
    if (a < 0 || a >= boyut)
        throw ElemanYok("Eleman yok.");
    if (a == 0)
        return ilk->sayi;
    return KonumBulS(a)->sonraki->sayi;
}
void SatirListesi::silSupur()
{
    while (!bosMu())
        removeAt(0);
}
void SatirListesi::yazdirSatirListesi(int x, int y)
{
    int yKonum = y;
    Pozisyon.gotoxy(x, yKonum);
    cout << "vvvvvvvv\n";
    for (Liste *eleman = this->ilk; eleman != NULL; eleman = eleman->sonraki)
    {

        Pozisyon.gotoxy(x, ++yKonum);
        cout << eleman << "\n";
        Pozisyon.gotoxy(x, ++yKonum);
        cout << "-----------\n";
        Pozisyon.gotoxy(x, ++yKonum);
        cout << "|" << setw(5) << eleman->sayi << setw(5) << "|" << endl;
        Pozisyon.gotoxy(x, ++yKonum);
        cout << "-----------\n";
        Pozisyon.gotoxy(x, ++yKonum);
        cout << "|" << eleman->sonraki << setw(3) << "|\n";
        Pozisyon.gotoxy(x, ++yKonum);
        cout << "-----------\n\n";
    }
}
ostream &operator<<(ostream &screen, SatirListesi &rgt)
{

    for (Liste *eleman = rgt.ilk; eleman != NULL; eleman = eleman->sonraki)
    {
        screen << eleman << "\n";
        screen << "-----------\n";
        screen << "|" << setw(5) << eleman->sayi << setw(5) << "|" << endl;
        screen << "-----------\n";
        screen << "|" << eleman->sonraki << setw(3) << "|\n";
        screen << "-----------\n\n";
    }
    screen << endl;
    return screen;
}
SatirListesi::~SatirListesi()
{
    silSupur();
}