#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include "mainwindow.h"


class Admin
{

const QString haslo="admin123";
public:

    Admin();
    void zaloguj();
    void dodaj_lot();
    void usun_lot();
    void anuluj_rezerwacje();
    bool sprHaslo(QString h);
};

#endif // ADMIN_H
