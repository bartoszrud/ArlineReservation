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
    Rezerwacje(QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj="PL");
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
    void dodaj_bagaz() {bagaz=true;}
    void dodaj_priority() {priority=true;}
    void wybierz_miejsce(int siedzenie) {nr_miejsca=siedzenie;}
    void pokaz_karte();

};

#endif // REZERWACJE_H
