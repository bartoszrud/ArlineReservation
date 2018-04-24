#include "admin.h"
#include "rezerwacje.h"

Admin::Admin()
{

}


bool Admin::zaloguj(QString h)
{
    if (h == haslo)
        return true;
    else return false;
}

Lot* Admin::dodaj_lot(QString docelowe, QString nr_lotu, QString data, QString wylotu)
{
    Lot *lot=new Lot(156,"Airbus A319", 156,docelowe,nr_lotu,data,wylotu);
            return lot;
}


void Admin::anuluj_rezerwacje(Rezerwacje & r)
{
    r.anuluj();
}

