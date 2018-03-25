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


Lot::Lot(int n, QString name, int wolne) : Samolot(n, name)
{

}
