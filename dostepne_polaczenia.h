 #ifndef DOSTEPNE_POLACZENIA_H
#define DOSTEPNE_POLACZENIA_H
#include <QString>


class Dostepne_polaczenia
{
    QString lotnisko_wylotu;
    QString lotnisko_docelowe;
    QString godzina_odlotu;
    QString godzina_przylotu;
    int indeks;

public:
    Dostepne_polaczenia();
    void dodaj_polaczenie();

};

#endif // DOSTEPNE_POLACZENIA_H
