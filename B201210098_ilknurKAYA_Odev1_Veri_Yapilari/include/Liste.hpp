#ifndef Liste_hpp
#define Liste_hpp
#include <exception>
#include <iostream>
class Liste
{
public:
    Liste *sonraki;
    Liste *onceki;
    int sayi;
    Liste(const int sayi);
    Liste(const int sayi, Liste *sonraki);
    Liste(const int sayi, Liste *sonraki, Liste *onceki);
};
#endif