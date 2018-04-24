#include "rezerwacje.h"

Rezerwacje::Rezerwacje()
{
anulowana=false;
}
Rezerwacje::Rezerwacje(Lot &lot,QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj)
{

imie=Kimie;
nazwisko=Knazwisko;
nr_tel=Knr_tel;
kraj=Kkraj;
nr_lotu=lot.podaj_nr_lotu();
data_odlotu=lot.podaj_date();
anulowana=false;

}
void Rezerwacje::wczytaj_dane(QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj)
{
    imie=Kimie;
    nazwisko=Knazwisko;
    nr_tel=Knr_tel;
    kraj=Kkraj;

}

void Rezerwacje::zarezerwuj()
{

}
void Rezerwacje::anuluj()
{
    anulowana=true;
}
Rezerwacje & Rezerwacje::operator --()
{
    this->anuluj();
    return *this;
}

Karta_pokladowa::Karta_pokladowa() : Rezerwacje()
{

}
Karta_pokladowa::Karta_pokladowa(Rezerwacje & rezerw,bool bag, bool prio) : Rezerwacje(rezerw)
{
    bagaz=bag;
    priority=prio;
    status_platnosci=false;
}


int Karta_pokladowa::pokaz_karte() //zwraca miejsce wybrane w rezerwacji
{
    return nr_miejsca;
}

bool Karta_pokladowa::czyBagaz()
{
    if (bagaz == true)
    {
        return true;
    } else return false;
}
bool Karta_pokladowa::czyPriority()
{
    if (priority == true)
    {
        return true;
    } else return false;
}

void Karta_pokladowa::potwierdzPlatnosc()
{
    status_platnosci=true;
}
