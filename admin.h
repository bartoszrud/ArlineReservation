#ifndef ADMIN_H
#define ADMIN_H
#include <QString>

class Admin
{
const QString m="admin123";
public:
    Admin();
    void zaloguj();
    void dodaj_lot();
    void usun_lot();
    void anuluj_rezerwacje();
};

#endif // ADMIN_H
