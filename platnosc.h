#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <QString>

class Platnosc
{
   int nr_platnosci;
   double cena_koncowa;
public:
    Platnosc();
    bool zaplac();
    double oblicz_cene();
};

#endif // PLATNOSC_H
