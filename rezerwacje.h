#ifndef REZERWACJE_H
#define REZERWACJE_H
#include <QString>
#include <QDebug>
#include "samolot.h"

class Lot;
class MainWindow;

class Rezerwacje
{
friend void MainWindow::wczytywanieRezerw();
friend void MainWindow::zapisywanieRezerw();
friend void MainWindow::wczytywanieKart();
friend void MainWindow::zapisywanieKart();


QString imie;
QString kraj;
QString nr_lotu;
QString data_odlotu;
protected:
QString nazwisko;
QString nr_tel;
bool anulowana;

public:

    Rezerwacje( );
    Rezerwacje(Lot &lot,QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj="PL");
    void wczytaj_dane(QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj);
    void zarezerwuj();



};


class Karta_pokladowa : Rezerwacje
{
friend void MainWindow::wczytywanieKart();
friend void MainWindow::zapisywanieKart();
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
    int pokaz_karte();
    bool match(QString nazwisk, QString nrtel);
    bool czyBagaz(); // zwraca true jeżeli pasażer ma już wykupiony bagaż
    bool czyPriority(); // zwraca true jeżeli pasażer ma już wykupiony Priority Pass

};

#endif // REZERWACJE_H
