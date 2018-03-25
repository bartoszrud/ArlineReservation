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
};



#endif // SAMOLOT_H
