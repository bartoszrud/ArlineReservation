#ifndef PRZECIAZENIA_H
#define PRZECIAZENIA_H

#include "samolot.h"
#include <QtCore>



QDataStream &operator <<(QDataStream &out, const Lot &lot);
QDataStream &operator >>(QDataStream &in,  Lot &lot);

QDataStream &operator <<(QDataStream &out, const Lot &lot)
{
    out<<lot.ilosc_miejsc<<lot.nazwa<<lot.wolne_miejsca<<lot.lotnisko_docelowe<<lot.nr_lotu<<lot.data_odlotu;
    return out;
}
QDataStream &operator >>(QDataStream &in, Lot &lot)
{
     in>>lot.ilosc_miejsc>>lot.nazwa>>lot.wolne_miejsca>>lot.lotnisko_docelowe>>lot.nr_lotu>>lot.data_odlotu;
     return in;
}
#endif // PRZECIAZENIA_H
