#ifndef DOSTEPNE_POLACZENIA_H
#define DOSTEPNE_POLACZENIA_H
#include <QString>
#include "samolot.h"

class Lot;


class Dostepne_polaczenia
{

   QString lotnisko_wylotu;
   QString lotnisko_docelowe;
   QString godzina_odlotu;
   QString godzina_przylotu;
   QString data_lotu;
   int indeks;

public:
   Dostepne_polaczenia(const Lot & lot, QString Klotnisko_wylotu="WRO", QString Kgodzina_odlotu="12:30", QString Kgodzina_przylotu="14:40",int Kindeks=1);
   Dostepne_polaczenia* dodaj_polaczenie();
   void wczytaj(Lot& lot);


};


#endif // DOSTEPNE_POLACZENIA_H
