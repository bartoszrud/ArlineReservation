#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include "mainwindow.h"

class Karta_pokladowa;

class Admin
{

const QString haslo="admin123";
public:

    Admin();
    Lot* dodaj_lot(QString docelowe,  QString nr_lotu, QString data);
    void usun_lot();
    void anuluj_rezerwacje();
    bool zaloguj(QString h);
};

#endif // ADMIN_H
