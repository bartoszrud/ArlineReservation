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
    Karta_pokladowa* dodaj_lot();
    void usun_lot();
    void anuluj_rezerwacje();
    bool zaloguj(QString h);
};

#endif // ADMIN_H
