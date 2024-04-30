#include "Liste.hpp"
Liste::Liste(const int sayi, Liste *sonraki, Liste *onceki)
{
    this->sayi = sayi;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
Liste::Liste(const int sayi, Liste *sonraki)
{
    this->sayi = sayi;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
Liste::Liste(const int sayi)
{
    this->sayi = sayi;
    this->sonraki = sonraki;
    this->onceki = onceki;
}
