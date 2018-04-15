#ifndef REZERWACJE_H
#define REZERWACJE_H
#include <QString>
#include <QDebug>
#include "samolot.h"

class Lot;

class Rezerwacje
{
QString imie;
QString kraj;
QString nr_lotu;
QString data_odlotu;
protected:
bool anulowana;
QString nazwisko;
QString nr_tel;
public:

    Rezerwacje( );
    Rezerwacje(Lot &lot,QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj="PL");
    void wczytaj_dane();
    void zarezerwuj();

};


class Karta_pokladowa : Rezerwacje
{

  bool priority;
  bool bagaz;
  int nr_miejsca;
  bool status_platnosci;
public:
    Karta_pokladowa();
    Karta_pokladowa(Rezerwacje & rezerw, bool bag=false, bool prio=false);
    void dodaj_bagaz() {bagaz=true;}
    void dodaj_priority() {priority=true;}
    void wybierz_miejsce(int siedzenie) {nr_miejsca=siedzenie;}
    void pokaz_karte();
    bool match(QString nazwisk, QString nrtel);
    bool czyBagaz(); // zwraca true jeżeli pasażer ma już wykupiony bagaż
    bool czyPriority(); // zwraca true jeżeli pasażer ma już wykupiony Priority Pass

};

#endif // REZERWACJE_H
