#include "dostepne_polaczenia.h"

Dostepne_polaczenia::Dostepne_polaczenia(Lot lot,QString Klotnisko_wylotu, QString Kgodzina_odlotu, QString Kgodzina_przylotu,int Kindeks)
{
    data_lotu=lot.data_odlotu;
    lotnisko_docelowe=lot.lotnisko_docelowe;
    lotnisko_wylotu=Klotnisko_wylotu;
    godzina_odlotu=Kgodzina_odlotu;
    godzina_przylotu=Kgodzina_przylotu;
    indeks=Kindeks;

}

