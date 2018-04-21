#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "samolot.h"
#include "rezerwacje.h"
#include "admin.h"
#include <QStandardItemModel>
#include <QStringListModel>
#include <QDateTime>
#include <QString>
#include <dostepne_polaczenia.h>
#include <QList>
#include <fstream>
#include <ctime>

#include <QFile>
#include <QCloseEvent>


 int n = 4;
 int licznik_rezerwacji=0;
 int licznik_kart=0;
 int ktora_rezerwacja=0;
 int wybrany_lot=0;

 Admin *admin1=new Admin;

 //Dostepne_polaczenia *pol1 = new Dostepne_polaczenia[n];
 QList<Rezerwacje> rezerwacje;
 QList<Karta_pokladowa> karty;
 QList<Lot> loty;
 QList<Dostepne_polaczenia> pol;



void wyswietlanie();
void wczytywanieRezerw();
void wczytywanieKart();
void wczytywanieLotow();





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   setupConnections();
     //ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej
    ui->statusBar->addPermanentWidget(ui->PrzyciskAdmin); //Przycisk w StatusBar
   wczytywanieLotow();
    wczytywanieRezerw();
    wczytywanieKart();

    wyswietlanie();

}

void MainWindow::wyswietlanie()
{
/*
    Lot *sam1 = new Lot(156,"Airbus A319",156,"WAW","NO332");
    loty.push_back(*sam1);
    Lot *sam2 = new Lot(156,"Airbus A319",156,"OSL","NO29");
    loty.push_back(*sam2);
    Lot *sam3 = new Lot(156,"Airbus A319",156,"KEF","NO32");
    loty.push_back(*sam3);
    Lot *sam4 = new Lot(156,"Airbus A319",156,"JFK","NO21");
    loty.push_back(*sam4);
*/

    for (int i=0;i<n;i++)
    {

        Dostepne_polaczenia *polaczenie= new Dostepne_polaczenia(loty[i]);
        pol.push_back(*polaczenie);
    }

    for(int i=0;i<n;i++){
MainWindow::ui->tabelaLotow->setItem(i,0,new QTableWidgetItem(pol[i].lotnisko_wylotu));
MainWindow::ui->tabelaLotow->setItem(i,1,new QTableWidgetItem(pol[i].lotnisko_docelowe));
MainWindow::ui->tabelaLotow->setItem(i,2,new QTableWidgetItem(pol[i].godzina_odlotu));
MainWindow::ui->tabelaLotow->setItem(i,3,new QTableWidgetItem(pol[i].godzina_przylotu));
MainWindow::ui->tabelaLotow->setItem(i,4,new QTableWidgetItem(pol[i].data_lotu));
MainWindow::ui->tabelaLotowAdmin->setItem(i,0,new QTableWidgetItem(pol[i].lotnisko_wylotu));
MainWindow::ui->tabelaLotowAdmin->setItem(i,1,new QTableWidgetItem(pol[i].lotnisko_docelowe));
MainWindow::ui->tabelaLotowAdmin->setItem(i,2,new QTableWidgetItem(pol[i].godzina_odlotu));
MainWindow::ui->tabelaLotowAdmin->setItem(i,3,new QTableWidgetItem(pol[i].godzina_przylotu));
MainWindow::ui->tabelaLotowAdmin->setItem(i,4,new QTableWidgetItem(pol[i].data_lotu));
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::rezerwujLot()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaRezerwacje);
}


void MainWindow::setupConnections()
{
    connect (ui->przyciskRezerwuj, &QPushButton::clicked,
             this, &MainWindow::rezerwujLot);
}

void MainWindow::on_przyciskRezerwuj_clicked()
{

    qDebug()<<"licznik rezerwacji"<<licznik_rezerwacji<<"licznik kart"<<licznik_kart;
    wybrany_lot=ui->comboBox->currentIndex();
    ui->stackedWidget->setCurrentWidget(ui->stronaRezerwacje);
   // wczytywanieKart();
}

void MainWindow::on_PrzyciskAdmin_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->LogowanieAdmin);

    /*
   hide();
   adminwindow *admwin =new adminwindow(this);
    admwin->show();
    */

}

void MainWindow::on_PrzyciskZaloguj_clicked()
{
    QString haslo = ui->wprowadzoneHaslo->text();

    if(admin1->zaloguj(haslo))
    {
        ui->stackedWidget->setCurrentWidget(ui->AdminPanel);

    }
    else
    {
        ui->statusBar->showMessage("Wprowadzono błędne hasło, spróbuj ponownie.",2000);
    }
}

void MainWindow::on_przyciskDalej_clicked()
{
 if(ui->lineImie->text().length() >1 && ui->lineNazwisko->text().length()>1 && ui->lineNrTelefonu->text().length() >=9
         && ui->lineNrTelefonu->text().length()<=13 && ui->lineKraj->text().length()>0)
 {
    QString imie = ui->lineImie->text();
    QString nazwisko = ui->lineNazwisko->text();
    QString nrtel = ui->lineNrTelefonu->text();
    QString kraj = ui->lineKraj->text();

    Rezerwacje *p1=new Rezerwacje(loty[wybrany_lot],imie,nazwisko,nrtel,kraj);
    rezerwacje.push_back(*p1);
    qDebug()<<licznik_rezerwacji;
    licznik_rezerwacji+=1;
    ui->stackedWidget->setCurrentWidget(ui->stronaKartapok);
 } else   ui->statusBar->showMessage("Wprowadzono błędne dane, popraw dane i spróbuj ponownie.",4000);

    ui->lineImie->clear();
    ui->lineNazwisko->clear();
    ui->lineNrTelefonu->clear();
    ui->lineKraj->clear();

}




void MainWindow::on_przyciskZaezadzaj_clicked()
{
    ui->lineNazwiskoZarz->clear();
    ui->lineNrtelZarz->clear();
    ui->stackedWidget->setCurrentWidget(ui->stronaZarzadzaj);

}

void MainWindow::on_przyciskPowrot_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);

}

void MainWindow::on_przyciskSpr_clicked()
{

    QString Snazw = ui->lineNazwiskoZarz->text();
    QString Snr=ui->lineNrtelZarz->text();


for(int x=0;x<licznik_kart;x++)
{
    qDebug()<<"Nr miejsca: "<<karty[x].pokaz_karte()<<"Czy bagaz: "<<karty[x].czyBagaz()<<"x: "<<x<<"Czy match "<<karty[x].match(Snazw,Snr)<<"Nazwisko"<<karty[x].pokazNazwisko()<<"Wprowadzone nazwisko:"<<Snazw ;

        if(karty[x].pokazNazwisko() == Snazw && karty[x].pokazNr_tel() == Snr)
        {
            ui->spinBoxZarezerw->setValue(karty[x].pokaz_karte());
            ui->stackedWidget->setCurrentWidget(ui->stronaKartaZarz);
            ktora_rezerwacja=x;   //wskazuje numer znalezionej rezerwacji.
            if(karty[x].czyBagaz()== true)
            {
                ui->checkBagazZarezerw->setChecked(true);

            } else ui->checkBagazZarezerw->setChecked(false);
            if (karty[x].czyPriority()==true)
            {
                ui->checkPriorityZarezerw->setChecked(true);
            } else ui->checkPriorityZarezerw->setChecked(false);

           break;
        }

}



}

void MainWindow::on_przyciskAkceptuj_clicked()
{


    Karta_pokladowa *k1=new Karta_pokladowa(rezerwacje[licznik_kart]);
    karty.push_back(*k1);


    if(ui->checkBagaz->isChecked())
    {
        karty[licznik_kart].dodaj_bagaz();
    }

    if(ui->checkPriority->isChecked())
    {
        karty[licznik_kart].dodaj_priority();
    }
    if (loty[wybrany_lot].zajmij_miejsce(ui->spinBox->value()))
            {
    karty[licznik_kart].wybierz_miejsce(ui->spinBox->value());


    QString s=QString::number((loty[wybrany_lot].podaj_cene(karty[licznik_kart].czyBagaz(),karty[licznik_kart].czyPriority())),10,2);
    licznik_kart++;
    ui->kwotaPlatnosci->setText(s);
    ui->stackedWidget->setCurrentWidget(ui->stronaPlatnosc);
    ui->checkBagaz->setChecked(false);
    ui->checkPriority->setChecked(false);
            } else ui->statusBar->showMessage("Wybrane miejsce jest już zajęte!",4000);
}


void MainWindow::on_przyciskStrgl_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}



//const char FileName[] = "plik.bin";



void MainWindow::closeEvent(QCloseEvent *event)
{
  zapisywanieRezerw();
  zapisywanieKart();
  zapisywanieLotow();

}


void MainWindow::on_przyciskAkceptujZarezerw_clicked()
{
    if(ui->checkBagazZarezerw->isChecked())
    {
        karty[ktora_rezerwacja].dodaj_bagaz();
    }

    if(ui->checkPriorityZarezerw->isChecked())
    {
        karty[ktora_rezerwacja].dodaj_priority();
    }

    if (loty[wybrany_lot].zajmij_miejsce(ui->spinBox->value()))
         {
    karty[ktora_rezerwacja].wybierz_miejsce(ui->spinBox->value());
    }
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}

void MainWindow::on_przyciskStrglZarezerw_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}




void MainWindow::on_przyciskZaplac_clicked()
{
    if(ui->lineNrKarty->text().length() ==16 &&ui->lineCVC->text().length()==3 )
    {
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
    ui->lineNrKarty->clear();
    ui->lineCVC->clear();
    }else ui->statusBar->showMessage("Wprowadzono błędne dane, spróbuj ponownie.",2000);

}
void  MainWindow::zapisywanieRezerw()
{
    QFile plik_rezerw("rezerwacjeplik.txt");
    if(!plik_rezerw.open(QIODevice::WriteOnly))
    {
        return;
    }
    QDataStream out(&plik_rezerw);
    out.setVersion(QDataStream::Qt_5_10);
    out<<licznik_rezerwacji<<licznik_kart;

for(int j=0;j<licznik_rezerwacji;j++)
{


    out<<rezerwacje[j].imie<<rezerwacje[j].nazwisko<<rezerwacje[j].kraj<<rezerwacje[j].nr_tel<<rezerwacje[j].nr_lotu<<rezerwacje[j].data_odlotu<<rezerwacje[j].anulowana;


}


plik_rezerw.flush();
plik_rezerw.close();
}

void MainWindow::wczytywanieRezerw()
{
    QFile plik_rezerw("rezerwacjeplik.txt");
    if(!plik_rezerw.open(QIODevice::ReadOnly))
    {
        return;
    }
    QDataStream in(&plik_rezerw);
    in.setVersion(QDataStream::Qt_5_10);

    in>>licznik_rezerwacji>>licznik_kart;

for(int j=0;j<licznik_rezerwacji;j++)
{
    Rezerwacje *rez1 = new Rezerwacje();
    rezerwacje.insert(j,*rez1);
    in>>rezerwacje[j].imie>>rezerwacje[j].nazwisko>>rezerwacje[j].kraj>>rezerwacje[j].nr_tel>>rezerwacje[j].nr_lotu>>rezerwacje[j].data_odlotu>>rezerwacje[j].anulowana;
}


plik_rezerw.close();
}
void MainWindow::zapisywanieKart()
{
    QFile plik_karty("kartyplik.txt");
    if(!plik_karty.open(QIODevice::WriteOnly))
    {
        return;
    }
    QDataStream out(&plik_karty);
    out.setVersion(QDataStream::Qt_5_10);

    for (int i=0;i<licznik_kart;i++)
       {
        out<<karty[i].imie<<karty[i].nazwisko<<karty[i].kraj<<karty[i].nr_tel<<karty[i].nr_lotu<<karty[i].data_odlotu<<karty[i].anulowana
          <<karty[i].priority<<karty[i].bagaz<<karty[i].nr_miejsca<<karty[i].status_platnosci;
       }
    plik_karty.flush();
    plik_karty.close();

}
void MainWindow::wczytywanieKart()
{
    QFile plik_karty("kartyplik.txt");
    if(!plik_karty.open(QIODevice::ReadOnly))
    {
        return;
    }
    QDataStream in(&plik_karty);
    in.setVersion(QDataStream::Qt_5_10);

    for (int i=0;i<licznik_kart;i++)
        {
        Karta_pokladowa *kar1=new Karta_pokladowa();
      //  qDebug()<<rezerwacje[i].imie;
        karty.insert(i,*kar1);
    }
    for (int i=0;i<licznik_kart;i++)
        {
        in>>karty[i].imie>>karty[i].nazwisko>>karty[i].kraj>>karty[i].nr_tel>>karty[i].nr_lotu>>karty[i].data_odlotu>>karty[i].anulowana>>karty[i].priority>>karty[i].bagaz>>karty[i].nr_miejsca>>karty[i].status_platnosci;
        //in>>karty[i].priority>>karty[i].bagaz>>karty[i].nr_miejsca>>karty[i].status_platnosci;
        qDebug()<<karty[i].nazwisko<<karty[i].nr_tel<<licznik_kart<<licznik_rezerwacji<<i;

        }

    plik_karty.close();
}

void MainWindow::zapisywanieLotow()
{
    QFile plik_loty("lotyplik.txt");
    if(!plik_loty.open(QIODevice::WriteOnly))
    {
        return;
    }
    QDataStream out(&plik_loty);
    out.setVersion(QDataStream::Qt_5_10);

    out<<n;

    for (int i=0;i<n;i++)
    {
       out<<loty[i].ilosc_miejsc<<loty[i].nazwa<<loty[i].wolne_miejsca<<loty[i].lotnisko_docelowe<<loty[i].nr_lotu<<loty[i].data_odlotu;
    }

    plik_loty.flush();
    plik_loty.close();
}
void MainWindow::wczytywanieLotow()
{
    QFile plik_loty("lotyplik.txt");
    if(!plik_loty.open(QIODevice::ReadOnly))
    {
        return;
    }
    QDataStream in(&plik_loty);
    in.setVersion(QDataStream::Qt_5_10);

    in>>n;
    qDebug()<<n;
    for (int i=0;i<n;i++)
    {
        Lot *lot1 = new Lot();
        loty.insert(i,*lot1);

       in>>loty[i].ilosc_miejsc>>loty[i].nazwa>>loty[i].wolne_miejsca>>loty[i].lotnisko_docelowe>>loty[i].nr_lotu>>loty[i].data_odlotu;
    }


    plik_loty.close();
}




void MainWindow::on_przyciskDodajLot_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaDodajLot);
}

void MainWindow::on_przyciskDodaj2_clicked()
{
    QString Ddocelowe=ui->lineLotniskoDocelowe->text();
    QString Dnrlotu=ui->lineNrLotu->text();
    QString Ddata=ui->lineDataLotu->text();
    qDebug()<<"zaladowalo tekst";
    loty.insert(n,*admin1->dodaj_lot(Ddocelowe,Dnrlotu,Ddata));
    qDebug()<<"utworzylo lot";
    Dostepne_polaczenia *polaczenie= new Dostepne_polaczenia(loty[n]);
    pol.push_back(*polaczenie);
    ui->tabelaLotow->insertRow(n);
    qDebug()<<"dodalo wiersz";
    MainWindow::ui->tabelaLotow->setItem(n,0,new QTableWidgetItem(pol[n].lotnisko_wylotu));
    MainWindow::ui->tabelaLotow->setItem(n,1,new QTableWidgetItem(pol[n].lotnisko_docelowe));
    MainWindow::ui->tabelaLotow->setItem(n,2,new QTableWidgetItem(pol[n].godzina_odlotu));
    MainWindow::ui->tabelaLotow->setItem(n,3,new QTableWidgetItem(pol[n].godzina_przylotu));
    MainWindow::ui->tabelaLotow->setItem(n,4,new QTableWidgetItem(pol[n].data_lotu));
     qDebug()<<"zaladowalo do kolumn";
    n++;
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}
