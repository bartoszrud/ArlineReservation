#include "dostepne_polaczenia.h"


void Dostepne_polaczenia::wczytaj(Lot& lot)
{
    data_lotu=lot.data_odlotu;
   lotnisko_docelowe=lot.lotnisko_docelowe;
   lotnisko_wylotu=lot.lotnisko_wylotu;
}
Dostepne_polaczenia::Dostepne_polaczenia(const Lot & lot,  QString Kgodzina_odlotu, QString Kgodzina_przylotu,int Kindeks)
{
    data_lotu=lot.data_odlotu;
    lotnisko_docelowe=lot.lotnisko_docelowe;
    lotnisko_wylotu=lot.lotnisko_wylotu;
    godzina_odlotu=Kgodzina_odlotu;
    godzina_przylotu=Kgodzina_przylotu;
    indeks=Kindeks;

}

Dostepne_polaczenia::Dostepne_polaczenia(QString Kdata_lotu,QString Klotnisko_docelowe, QString Klotnisko_wylotu, QString Kgodzina_odlotu, QString Kgodzina_przylotu,int Kindeks)
{
    data_lotu=Kdata_lotu;
    lotnisko_docelowe=Klotnisko_docelowe;
    lotnisko_wylotu=Klotnisko_wylotu;
    godzina_odlotu=Kgodzina_odlotu;
    godzina_przylotu=Kgodzina_przylotu;
    indeks=Kindeks;

}



