#include "rezerwacje.h"

Rezerwacje::Rezerwacje()
{

}
Rezerwacje::Rezerwacje(Lot &lot,QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj)
{

imie=Kimie;
nazwisko=Knazwisko;
nr_tel=Knr_tel;
kraj=Kkraj;
nr_lotu=lot.podaj_nr_lotu();
data_odlotu=lot.podaj_date();

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

Karta_pokladowa::Karta_pokladowa() : Rezerwacje()
{

}
Karta_pokladowa::Karta_pokladowa(Rezerwacje & rezerw,bool bag, bool prio) : Rezerwacje(rezerw)
{
    bagaz=bag;
    priority=prio;
}


int Karta_pokladowa::pokaz_karte() //zwraca miejsce wybrane w rezerwacji
{
    return nr_miejsca;
}

bool Karta_pokladowa::match(QString nazwisk, QString nrtel)
{
    if(nazwisk == nazwisko && nrtel == nr_tel && anulowana==false)
    {

        return true;
    } else {return false;}
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
