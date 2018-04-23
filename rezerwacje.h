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
protected:
QString nr_lotu;
QString data_odlotu;
QString nazwisko;
QString nr_tel;
bool anulowana;

public:

    Rezerwacje( );
    Rezerwacje(Lot &lot,QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj="PL");
    void wczytaj_dane(QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj);
    void zarezerwuj();
    bool czy_anulowana() {return anulowana;}
    void anuluj();
    QString pokazNazwisko(){return nazwisko;}
    QString pokazNr_tel(){return nr_tel;}
    QString podajNr_lotu() {return nr_lotu;}
    QString podajDate_lotu() {return data_odlotu;}


};


class Karta_pokladowa : public Rezerwacje
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
    int pokaz_karte(); //zwraca nr miejsca ktróre wybrał pasażer
    bool czyBagaz(); // zwraca true jeżeli pasażer ma już wykupiony bagaż
    bool czyPriority(); // zwraca true jeżeli pasażer ma już wykupiony Priority Pass
    bool potwierdzPlatnosc();


};

#endif // REZERWACJE_H
