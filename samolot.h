#ifndef SAMOLOT_H
#define SAMOLOT_H
#include <cstdlib>
#include <QString>


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
    int wolne_miejsca;
    QString nr_miejsca;
    QString lotnisko_docelowe;
    double cena_pdst;
    QString data_odlotu;


public:
    Lot(int n=100, QString name="Boeing 737-800",int wolne=100);

};


#endif // SAMOLOT_H
