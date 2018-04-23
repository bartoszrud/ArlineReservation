#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include "mainwindow.h"

class Rezerwacje;


class Admin
{

const QString haslo="admin123";
public:

    Admin();
    Lot* dodaj_lot(QString docelowe,  QString nr_lotu, QString data);
    void usun_lot();
    bool zaloguj(QString h);
    //void anuluj_rezerwacje(Rezerwacje & r);
};

#endif // ADMIN_H
