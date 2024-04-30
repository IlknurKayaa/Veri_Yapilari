#include <cstdlib>
#include "SatirListesi.hpp"
#include "YoneticiListesi.hpp"
#include "Yonetici.hpp"
#include "Dosya.hpp"
#include "Konsol.hpp"
#include "Exception.hpp"
using namespace std;
int main(int argc, char **argv)
{
    Dosya *read = new Dosya("veriler.txt");
    YoneticiListesi *yoneticiListesi = read->GetFillYoneticiListesi();
    Konsol *console = new Konsol(yoneticiListesi);
    yoneticiListesi->ortSira();
    string karakter = "";
    do
    {
        console->yazdirYoneticiListesi();
        cin >> karakter;
        if (karakter == "z")
        {
            Yon yon = down;
            console->kurKonum(yon);
        }
        else if (karakter == "c")
        {
            Yon yon = up;
            console->kurKonum(yon);
        }
        else if (karakter == "a")
        {
            console->kurSayfa(downPage);
        }
        else if (karakter == "d")
        {
            console->kurSayfa(upPage);
        }
        else if (karakter == "p")
        {
            console->silYonetici();
        }
        else if (karakter == "k")
        {
            int random = 0;
            try
            {
                random = console->randomSec();
            }
            catch (...)
            {
                continue;
            }
            cin >> karakter;
            if (karakter == "k")
            {

                console->silRandom(random);
                yoneticiListesi->ortSira();
            }
            /*if (yoneticiListesi->bosMuY())
            {
                console->silYonetici();
            }*/
        }

    } while (karakter != "e");

    return 0;
}
