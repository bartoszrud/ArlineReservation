#ifndef DOSTEPNE_POLACZENIA_H
#define DOSTEPNE_POLACZENIA_H
#include <QString>
#include "samolot.h"
#include "mainwindow.h"

class Lot;
class MainWindow;

class Dostepne_polaczenia
{
private:
   friend class MainWindow;
   QString lotnisko_wylotu;
   QString lotnisko_docelowe;
   QString godzina_odlotu;
   QString godzina_przylotu;
   QString data_lotu;
   int indeks;

public:

   Dostepne_polaczenia(const Lot & lot, QString Klotnisko_wylotu="WRO", QString Kgodzina_odlotu="12:30", QString Kgodzina_przylotu="14:40",int Kindeks=1);
   Dostepne_polaczenia(QString Kdata_lotu="11.11.2018",QString Klotnisko_docelowe="JFK", QString Klotnisko_wylotu="WRO", QString Kgodzina_odlotu="12:30", QString Kgodzina_przylotu="14:40",int Kindeks=1);
   void wczytaj(Lot& lot);



};


#endif // DOSTEPNE_POLACZENIA_H
