 #ifndef DOSTEPNE_POLACZENIA_H
#define DOSTEPNE_POLACZENIA_H
#include <QString>
#include "samolot.h"



class Dostepne_polaczenia
{

    QString lotnisko_wylotu;
    QString lotnisko_docelowe;
    QString godzina_odlotu;
    QString godzina_przylotu;
    QString data_lotu;
    int indeks;

public:
    Dostepne_polaczenia(QString Klotnisko_wylotu, QString Kgodzina_odlotu, QString Kgodzina_przylotu,int Kindeks);
    void dodaj_polaczenie();
    void wczytaj(Lot& lot);


};


#endif // DOSTEPNE_POLACZENIA_H
