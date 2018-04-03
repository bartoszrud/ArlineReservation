#ifndef SAMOLOT_H
#define SAMOLOT_H
#include <cstdlib>
#include <QString>
#include <dostepne_polaczenia.h> // nie wiem czy potrzebne do przyjaźni, jeszcze sprawdze


class Samolot
{
    QString nazwa;
    int ilosc_miejsc;
public:
    Samolot(int n=100, QString name="Boeing 737-800");
    QString wysw();
};

class Lot : public Samolot
{
    friend class Dostepne_polaczenia;
    friend class Admin;

    int wolne_miejsca;
    QString nr_lotu;
    QString lotnisko_docelowe;
    double cena_pdst;
    QString data_odlotu;


public:
    Lot(int n=100, QString name="Boeing 737-800",int wolne=100, QString docelowe="WRO", QString data="01.01.2019" , QString nr="NO2137" );
    void zajmij_miejsce();

};


#endif // SAMOLOT_H
