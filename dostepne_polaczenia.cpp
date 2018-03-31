#include "dostepne_polaczenia.h"


void Dostepne_polaczenia::wczytaj(Lot& lot)
{
    data_lotu=lot.data_odlotu;
   lotnisko_docelowe=lot.lotnisko_docelowe;
}
Dostepne_polaczenia::Dostepne_polaczenia(QString Klotnisko_wylotu, QString Kgodzina_odlotu, QString Kgodzina_przylotu,int Kindeks)
{
    //data_lotu=lot.data_odlotu;
    //lotnisko_docelowe=lot.lotnisko_docelowe;
    lotnisko_wylotu=Klotnisko_wylotu;
    godzina_odlotu=Kgodzina_odlotu;
    godzina_przylotu=Kgodzina_przylotu;
    indeks=Kindeks;

}

Dostepne_polaczenia* Dostepne_polaczenia::dodaj_polaczenie( )
{
    Dostepne_polaczenia *p=new Dostepne_polaczenia("l","DF","FD",1); // to nam nic nie da

    return p;

}


