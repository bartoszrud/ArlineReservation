#ifndef REZERWACJE_H
#define REZERWACJE_H
#include <QString>


class Rezerwacje
{
QString imie;
QString nazwisko;
QString nr_tel;
QString kraj;
QString nr_lotu;
QString data_odlotu;
bool anulowana;

public:
    Rezerwacje();
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
    void dodaj_bagaz();
    void dodaj_priority();
    void wybierz_miejsce();
    void pokaz_karte();

};

#endif // REZERWACJE_H
