#include "YoneticiListesi.hpp"
using namespace std;
YoneticiListesi::YoneticiListesi()
{
    ilky = NULL;
    boyuty = 0;
}
Yonetici *YoneticiListesi::OnceKonumBulY(int a) throw(ElemanYok)
{
    if (a < 0 || a > boyuty)
        throw ElemanYok("Eleman yok.");
    Yonetici *prv = ilky;
    int i = 1;
    for (Yonetici *yonetici = ilky; yonetici->sonrakiy != NULL && i != a; yonetici = yonetici->sonrakiy, i++)
    {
        prv = prv->sonrakiy;
    }
    return prv;
}
Yonetici *YoneticiListesi::KonumBulY(int a) throw(ElemanYok)
{
    if (a < 0 || a >= boyuty)
        throw ElemanYok("Eleman yok.");
    return this->OnceKonumBulY(a + 1);
}
int YoneticiListesi::sayY() const
{
    return boyuty;
}
bool YoneticiListesi::bosMuY() const
{
    return boyuty == 0;
}
SatirListesi *&YoneticiListesi::ilks() throw(ElemanYok)
{
    if (bosMuY())
    {
        throw ElemanYok("Eleman yok.");
    }

    return ilky->sayi;
}
SatirListesi *&YoneticiListesi::sons() throw(ElemanYok)
{
    if (bosMuY())
        throw ElemanYok("Eleman yok.");
    return OnceKonumBulY(boyuty)->sayi;
}
void YoneticiListesi::ekleAY(SatirListesi *&item)
{
    ekleBY(boyuty, item);
}
void YoneticiListesi::ekleBY(int a, SatirListesi *&item)
{
    if (a < 0 || a > boyuty)
        throw "Eklenemez.";
    if (a == 0)
    {
        ilky = new Yonetici(item, ilky);
        if (ilky->sonrakiy != NULL)
            ilky->sonrakiy->oncekiy = ilky;
    }
    else
    {
        Yonetici *prv = OnceKonumBulY(a);
        prv->sonrakiy = new Yonetici(item, prv->sonrakiy, prv);
        if (prv->sonrakiy->sonrakiy != NULL)
            prv->sonrakiy->sonrakiy->oncekiy = prv->sonrakiy;
    }
    boyuty++;
}
void YoneticiListesi::silAY(SatirListesi *&item)
{
    int a = indexOf(item);
    removeAt(a);
}
void YoneticiListesi::rndremoveAtSatir(int b, int inlineIndex) throw(IndexOutOfBounds, ElemanYok)
{

    int say = this->sayY();
    if (b < 0 || b >= say)
        throw IndexOutOfBounds("Sınır dışı.");

    SatirListesi *satir = this->elemanAt(b);

    satir->removeAt(inlineIndex);
    ortalamaHesapla(b);
}
void YoneticiListesi::removeAt(int b)
{
    if (b < 0 || b >= boyuty)
        throw "Sınır dışı.";
    Yonetici *del;
    if (b == 0)
    {
        del = ilky;
        ilky = ilky->sonrakiy;
        if (ilky != NULL)
            ilky->oncekiy = NULL;
    }
    else
    {
        Yonetici *prv = OnceKonumBulY(b);
        del = prv->sonrakiy;
        prv->sonrakiy = del->sonrakiy;
        if (del->sonrakiy != NULL)
            del->sonrakiy->oncekiy = prv;
    }
    boyuty--;
    delete del;
}
SatirListesi *&YoneticiListesi::elemanAt(int b) throw(ElemanYok)
{
    if (b < 0 || b >= boyuty)
        throw ElemanYok("Eleman yok.");
    if (b == 0)
        return ilky->sayi;
    return OnceKonumBulY(b)->sonrakiy->sayi;
}
void YoneticiListesi::git(int from, int to) throw(IndexOutOfBounds)
{
    if (from < 0 || from >= boyuty)
        throw IndexOutOfBounds("index out of bound");
    Yonetici *del;
    if (from == 0)
    {
        del = ilky;
        ilky = ilky->sonrakiy;
        if (ilky != NULL)
            ilky->oncekiy = NULL;
    }
    else
    {
        Yonetici *prv = OnceKonumBulY(from);
        del = prv->sonrakiy;
        prv->sonrakiy = del->sonrakiy;
        if (del->sonrakiy != NULL)
            del->sonrakiy->oncekiy = prv;
    }
    boyuty--;
    if (to < 0 || to > boyuty)
        throw "Sınır dışı.";
    if (to == 0)
    {

        del->sonrakiy = ilky;
        del->oncekiy = NULL;
        ilky = del;
        if (ilky->sonrakiy != NULL)
            ilky->sonrakiy->oncekiy = ilky;
    }
    else
    {
        Yonetici *prv = OnceKonumBulY(to);

        del->sonrakiy = prv->sonrakiy;
        del->oncekiy = prv;
        prv->sonrakiy = del;
        if (prv->sonrakiy->sonrakiy != NULL)
            prv->sonrakiy->sonrakiy->oncekiy = prv->sonrakiy;
    }
    boyuty++;
}
bool YoneticiListesi::bul(SatirListesi *&item)
{
    for (Yonetici *yonetici = ilky; yonetici != NULL; yonetici = yonetici->sonrakiy)
    {
        if (yonetici->sayi == item)
            return true;
    }
    return false;
}
void YoneticiListesi::tersiniAl()
{
    for (Yonetici *yonetici = ilky; yonetici != NULL;)
    {
        Yonetici *tmp = yonetici->sonrakiy;
        yonetici->sonrakiy = yonetici->oncekiy;
        yonetici->oncekiy = tmp;
        if (tmp == NULL)
        {
            ilky = yonetici;
            break;
        }
        yonetici = tmp;
    }
}
void YoneticiListesi::ortalamaHesapla(int b)
{
    Yonetici *Yonetici = this->KonumBulY(b);

    if (Yonetici == NULL)
    {

        throw "HATA";
    }

    double toplam = 0;
    if (Yonetici->sayi->bosMu())
    {

        Yonetici->ortalama = toplam;
        return;
    }

    int say = Yonetici->sayi->Say();
    for (int i = 0; i < say; ++i)
    {
        toplam += Yonetici->sayi->elemanAt(i);
    }
    Yonetici->ortalama = toplam / say;
}
int YoneticiListesi::randomSayi(int b) throw(IndexOutOfBounds, ElemanYok)
{
    int say = this->sayY();

    if (b < 0 || b >= say)
        throw IndexOutOfBounds("Sınır dışı.");

    srand(time(NULL));
    SatirListesi *satir = this->elemanAt(b);

    int ort = satir->Say();
    if (ort == 0)
    {
        throw ElemanYok("Eleman yok.");
    }
    int inlineIndex = rand() % ort;

    return inlineIndex;
}
void YoneticiListesi::ortSira()
{
    if (this->boyuty <= 1)
        return;

    for (int a = 0; a < boyuty; ++a)
    {

        for (int i = 0; i < boyuty - a - 1; ++i)
        {
            Yonetici *tmp = this->KonumBulY(i);
            Yonetici *tmp2 = tmp->sonrakiy;

            if (tmp->ortalama > tmp2->ortalama)
            {

                this->git(i + 1, i);
            }
        }
    }
}
int YoneticiListesi::indexOf(SatirListesi *&item) throw(ElemanYok)
{
    int b = 0;
    for (Yonetici *yonetici = ilky; yonetici != NULL; yonetici = yonetici->sonrakiy)
    {
        if (yonetici->sayi == item)
            return b;
        b++;
    }
    throw ElemanYok("Eleman yok.");
}
void YoneticiListesi::temizle()
{
    while (!bosMuY())
        removeAt(0);
}
void YoneticiListesi::yazdir(int a, int x, int y)
{
    Yonetici *node = this->KonumBulY(a);
    Pozisyon.gotoxy(x, y);
    cout << fixed << setprecision(2);
    cout << node << "\n";
    Pozisyon.gotoxy(x, y + 1);
    cout << "-----------\n";
    Pozisyon.gotoxy(x, y + 2);
    cout << "|" << node->oncekiy << setw(3) << "|\n";
    Pozisyon.gotoxy(x, y + 3);
    cout << "-----------\n";
    Pozisyon.gotoxy(x, y + 4);
    cout << "|" << setw(3) << node->ortalama << setw(5) << "|" << endl;
    Pozisyon.gotoxy(x, y + 5);
    cout << "-----------\n";
    Pozisyon.gotoxy(x, y + 6);
    cout << "|" << node->sonrakiy << setw(3) << "|\n";
    Pozisyon.gotoxy(x, y + 7);
    cout << "-----------\n\n";
}
YoneticiListesi::~YoneticiListesi()
{
    temizle();
}