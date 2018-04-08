#include "rezerwacje.h"

Rezerwacje::Rezerwacje()
{

}
Rezerwacje::Rezerwacje(QString Kimie, QString Knazwisko, QString Knr_tel, QString Kkraj)
{
imie=Kimie;
nazwisko=Knazwisko;
nr_tel=Knr_tel;
kraj=Kkraj;
}
void Rezerwacje::wczytaj_dane()
{

}

void Rezerwacje::zarezerwuj()
{

}

Karta_pokladowa::Karta_pokladowa() : Rezerwacje()
{

}



void Karta_pokladowa::pokaz_karte()
{

}
