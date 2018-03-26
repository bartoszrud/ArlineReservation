#include "samolot.h"

Samolot::Samolot(int n, QString name)
{
    nazwa=name;
    ilosc_miejsc=n;
}


QString Samolot::wysw()
{
    return nazwa;

}


Lot::Lot(int n, QString name, int wolne, QString docelowe, QString data , QString nr) : Samolot(n, name)
{
    wolne_miejsca=wolne;
    lotnisko_docelowe=docelowe;
    data_odlotu=data;
    nr_lotu=nr;

}
