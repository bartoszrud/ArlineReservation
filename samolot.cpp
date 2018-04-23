#include "samolot.h"


Samolot::Samolot(int n, QString name)
{
    nazwa=name;
    ilosc_miejsc=n;
}


QString Samolot::wysw()
{
    return nazwa;

}

int Samolot::ile_miejsc()
{
    return ilosc_miejsc;
}

Lot::Lot(int n, QString name, int wolne, QString docelowe,QString nr, QString data  ) : Samolot(n, name)
{
    for (int i=0;i<=wolne;i++)
    {
        miejsca[i]=true;
    }
    wolne_miejsca=wolne;
    lotnisko_docelowe=docelowe;
    data_odlotu=data;
    nr_lotu=nr;
    cena_pdst= ustaw_cene();

}
Lot::Lot(Samolot & sam, int wolne, QString docelowe,QString nr, QString data  ) : Samolot(sam)
{
    for (int i=0;i<=wolne;i++)
    {
        miejsca[i]=true;
    }

    wolne_miejsca=wolne;
    lotnisko_docelowe=docelowe;
    data_odlotu=data;
    nr_lotu=nr;
    cena_pdst= ustaw_cene();
}

int Lot::ile_miejsc()
{
    return wolne_miejsca;
}
QString Lot::podaj_nr_lotu()
{
    return nr_lotu;
}

double Lot::ustaw_cene()
{
    double losowanie = double(((std::rand() % 50) +220));

    return losowanie;
}

bool Lot::zajmij_miejsce(int miejsce)
{

    if (miejsca[miejsce] == true && miejsce>0)
    {
        miejsca[miejsce] = false;
        wolne_miejsca--;
        return true;
    } else return false;

}

bool Lot::zwolnij_miejsce(int miejsce)
{
    if (miejsca[miejsce] == false && miejsce>0)
    {
        miejsca[miejsce] = true;
        wolne_miejsca++;
        return true;
    } else return false;
}



double Lot::podaj_cene(bool bagaz, bool priority)
{
    double cena_aktualna=cena_pdst;
    if(bagaz==true)
    {
        cena_aktualna+=110;
    }
    if(priority==true)
    {
        cena_aktualna+=50;
    }

    return cena_aktualna ;
}

