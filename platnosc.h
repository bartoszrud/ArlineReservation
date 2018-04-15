#ifndef PLATNOSC_H
#define PLATNOSC_H
#include <QString>

class Platnosc
{
   int nr_platnosci;
   double cena_koncowa;
public:
    Platnosc(int nr=0,int cena=0);
    bool zaplac();
    double oblicz_cene();
};

#endif // PLATNOSC_H
