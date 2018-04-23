#ifndef SAMOLOT_H
#define SAMOLOT_H
//#include <cstdlib>
#include <QString>
#include <dostepne_polaczenia.h> // nie wiem czy potrzebne do przyjaźni, jeszcze sprawdze
#include "mainwindow.h"



class Karta_pokladowa;

class Samolot
{
  //  friend void MainWindow::zapisywanieLotow();
   // friend void MainWindow::wczytywanieLotow(); deklaracja przyjazni dla funkcji, tu nie działa
protected:
    QString nazwa;
    int ilosc_miejsc;

public:
    virtual int ile_miejsc(); //zwraca ilość miejsc w samolocie dla obiektu samolot, a dla obiektu lot ilość wolnych miejsc w danym połączeniu
    Samolot(int n=156, QString name="Airbus A319");
    QString wysw();
    virtual ~Samolot(){}
};



class Lot : public Samolot
{

    friend class Dostepne_polaczenia;
    friend class MainWindow;

   // friend void MainWindow::zapisywanieLotow();
  // friend void MainWindow::wczytywanieLotow();

    bool *miejsca= new bool[++ilosc_miejsc]; //jeśli miejsca[i] == true to miejsce jest wolne
    int wolne_miejsca;
    QString nr_lotu;
    QString lotnisko_docelowe;
    double cena_pdst;
    QString data_odlotu;
    double ustaw_cene();


public:
    virtual int ile_miejsc();
    double ustaw_cene(bool bagaz, bool priority); //ustawia cenę zależnie od tego czy pasażer wybrał bagaż i/lub priority
    Lot(int n=156, QString name="Airbus A319",int wolne=156, QString docelowe="KEF", QString nr="NO217", QString data="01.01.2019");
    Lot(Samolot & sam, int wolne=156, QString docelowe="WRO",QString nr="NO217", QString data="01.01.2019" );
    bool zajmij_miejsce(int miejsce); //zajmuje wybrane miejsce i zwraca true jeżeli miejsce zostało poprawnie zajęte lub false jeżeli wybrane miejsce było już zajęte
    bool zwolnij_miejsce(int miejsce); //zwalnia miejsce i zwraca true jeśli miejsce zostało poprawnie zwolnione lub false w przeciwnym wypadku
    QString podaj_nr_lotu();
    QString podaj_date() {return data_odlotu;}
    double podaj_cene(bool bagaz, bool priority);


};


#endif // SAMOLOT_H
