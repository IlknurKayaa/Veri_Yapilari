#include "Konsol.hpp"
Konsol::Konsol(YoneticiListesi *yonetici)
{
    this->yonetici = yonetici;
    if (this->yonetici->sayY() < DisplayperOnePage)
    {
        this->bitis = this->yonetici->sayY();
    }
    else
    {
        this->bitis = DisplayperOnePage;
    }

    this->basla = BeginOffset;
}
void Konsol::kur()
{
    int page = konum / DisplayperOnePage;
    this->basla = DisplayperOnePage * page;
    this->bitis = DisplayperOnePage * (page + 1);
    if (this->bitis >= this->yonetici->sayY())
    {
        this->bitis = this->yonetici->sayY();
    }
}
void Konsol::kurSayfa(sayfaYon pdr)
{
    if (pdr == downPage)
    {
        for (int i = 0; i < DisplayperOnePage; ++i)
        {
            this->kurKonum(down);
        }
    }
    else if (pdr == upPage)
    {
        for (int i = 0; i < DisplayperOnePage; ++i)
        {
            this->kurKonum(up);
        }
    }
}

void Konsol::kurKonum(Yon dr)
{

    if (dr == up)
    {
        if (konum >= this->yonetici->sayY() - 1)
        {
            return;
        }
        ++konum;
        kur();
    }
    else if (dr == down)
    {
        if (konum <= 0)
        {

            return;
        }
        --konum;
        kur();
    }
    else if (dr == refresh)
    {
        kur();
    }
}
void Konsol::yazdirSatirListesi(int x, int y)
{
    this->yonetici->elemanAt(this->konum)->yazdirSatirListesi(x, y);
}
int Konsol::randomSec() throw(IndexOutOfBounds, ElemanYok)
{

    int rndsec = this->yonetici->randomSayi(this->konum);
    int xpozisyon = ((this->konum % DisplayperOnePage) + 1) * 15;
    int ypozisyon = (rndsec)*6;
    ypozisyon += 12;
    Pozisyon.gotoxy(xpozisyon, ypozisyon);
    cout << "<--sil";
    ypozisyon = this->yonetici->elemanAt(this->konum)->Say() * 6 + 12;

    Pozisyon.gotoxy(0, ypozisyon - 1);

    return rndsec;
}
void Konsol::yazdirYoneticiListesi()
{

    int say = yonetici->sayY();
    system("cls");
    if (say == 0)
    {
        cout << "Goruntulenecek Yonetici listesi yok\n";
        exit(1);
        return;
    }

    Pozisyon.gotoxy(0, 0);
    if (this->basla == 0)
    {
        cout << "<-ilk";
    }
    else
    {
        cout << "<-geri";
    }

    int gostersayY = this->bitis - this->basla;
    gostersayY *= 13;

    Pozisyon.gotoxy(gostersayY, 0);

    if (this->bitis == yonetici->sayY())
    {
        cout << "son->";
    }
    else
    {
        cout << "ileri->";
    }
    for (int i = this->basla; i < this->bitis; ++i)
    {

        int mod = i % DisplayperOnePage;
        this->yonetici->yazdir(i, 15 * mod, 1);
    }
    this->yazdirSatirListesi((this->konum % DisplayperOnePage) * 15, 9);
}
void Konsol::silYonetici()
{
    this->yonetici->removeAt(this->konum);
    this->kurKonum(refresh);

    if (this->konum == this->bitis)
    {
        this->konum--;
    }
    this->kurKonum(refresh);
}
void Konsol::silRandom(int random) throw(IndexOutOfBounds, ElemanYok)
{
    this->yonetici->rndremoveAtSatir(this->konum, random);
}
