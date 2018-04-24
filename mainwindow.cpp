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
#include <ctime>
#include <QFile>
#include <QCloseEvent>
#include <QPixmap>


 int n = 0;
 int licznik_rezerwacji=0;
 int licznik_kart=0;
 int ktora_rezerwacja=0;
 int wybrany_lot=0;

 Admin *admin1=new Admin;

 QList<Rezerwacje> rezerwacje;
 QList<Karta_pokladowa> karty;
 QList<Lot> loty;
 QList<Dostepne_polaczenia> pol;


void wczytywanieLotow();
void wyswietlanie();
void wczytywanieRezerw();
void wczytywanieKart();
void wczytywaniePolaczen();





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap miejsca(":/siedzenia/A319 Kadrowane530PNG.png");
    ui->siedzenia->setPixmap(miejsca);
    ui->siedzenia2->setPixmap(miejsca);
   setupConnections();

    ui->statusBar->addPermanentWidget(ui->PrzyciskAdmin); //Przycisk w StatusBar
    wczytywanieLotow();

   wczytywanieRezerw();
    wczytywanieKart();

    wyswietlanie();


}




void MainWindow::wyswietlanie()
{

  int comb=1;
    for (int i=0;i<n;i++)
    {


        Dostepne_polaczenia *polaczenie= new Dostepne_polaczenia(loty[i]);
        pol.insert(i,*polaczenie);

        ui->tabelaLotow->insertRow(i);
        ui->tabelaLotowAdmin->insertRow(i);
        ui->comboBox->addItem(QString::number(comb));
        ui->comboBoxAdmin->addItem(QString::number(comb));
        comb++;
    }
  wczytywaniePolaczen();
    for(int i=0;i<n;i++)
    {
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


    wybrany_lot=ui->comboBox->currentIndex();
    ui->stackedWidget->setCurrentWidget(ui->stronaRezerwacje);

}

void MainWindow::on_PrzyciskAdmin_clicked()
{

    ui->stackedWidget->setCurrentWidget(ui->LogowanieAdmin);


}

void MainWindow::on_PrzyciskZaloguj_clicked()
{
    QString haslo = ui->wprowadzoneHaslo->text();

    if(admin1->zaloguj(haslo))
    {
        ui->stackedWidget->setCurrentWidget(ui->AdminPanel);
        ui->wprowadzoneHaslo->clear();
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

    licznik_rezerwacji+=1;
    ui->stackedWidget->setCurrentWidget(ui->stronaKartapok);
    ui->lineImie->clear();
    ui->lineNazwisko->clear();
    ui->lineNrTelefonu->clear();
    ui->lineKraj->clear();

   } else   ui->statusBar->showMessage("Wprowadzono błędne dane, popraw dane i spróbuj ponownie.",3000);



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
            } else ui->statusBar->showMessage("Wybrane miejsce jest już zajęte!",3000);
}


void MainWindow::on_przyciskStrgl_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}




void MainWindow::closeEvent(QCloseEvent *event)
{
  zapisywanieRezerw();
  zapisywanieKart();
  zapisywanieLotow();
  zapisywaniePolaczen();

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

    if (loty[wybrany_lot].zajmij_miejsce(ui->spinBoxZarezerw->value()))
         {
        loty[wybrany_lot].zwolnij_miejsce(karty[ktora_rezerwacja].pokaz_karte());
    karty[ktora_rezerwacja].wybierz_miejsce(ui->spinBoxZarezerw->value());

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
        int tymczasowa=licznik_kart-1;
    karty[tymczasowa].potwierdzPlatnosc();
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
         out <<karty[i].priority<<karty[i].bagaz<<karty[i].nr_miejsca<<karty[i].status_platnosci;
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
        Karta_pokladowa *kar1=new Karta_pokladowa(rezerwacje[i]);
        karty.insert(i,*kar1);
    }
    for (int i=0;i<licznik_kart;i++)
        {

        in>>karty[i].priority>>karty[i].bagaz>>karty[i].nr_miejsca>>karty[i].status_platnosci;

        for(int k=0;k<n;k++)
        {

            if(karty[i].podajNr_lotu()==loty[k].podaj_nr_lotu() && karty[i].podajDate_lotu()==loty[k].podaj_date() && karty[i].czy_anulowana()==false)
            {
              //  qDebug()<<"Znaleziono zgodność"<<karty[i].pokaz_karte();

                loty[k].zajmij_miejsce(karty[i].pokaz_karte());
            }
        }

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

     out<<loty[i].ilosc_miejsc<<loty[i].nazwa<<loty[i].wolne_miejsca<<loty[i].lotnisko_docelowe<<loty[i].nr_lotu<<loty[i].data_odlotu<<loty[i].lotnisko_wylotu;
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

    for (int i=0;i<n;i++)
    {
        Lot *lot1 = new Lot();
        loty.insert(i,*lot1);

       in>>loty[i].ilosc_miejsc>>loty[i].nazwa>>loty[i].wolne_miejsca>>loty[i].lotnisko_docelowe>>loty[i].nr_lotu>>loty[i].data_odlotu>>loty[i].lotnisko_wylotu;
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
    QString DLotniskoWylotu=ui->lineLotniskoWylotu->text();
    QString DGodzWylotu=ui->lineGodzinaWylotu->text();
    QString DGodzPrzylotu=ui->lineGodzinaPrzylotu->text();

   // qDebug()<<"zaladowalo tekst"<<DGodzWylotu<<DGodzPrzylotu;
    loty.insert(n,*admin1->dodaj_lot(Ddocelowe,Dnrlotu,Ddata,DLotniskoWylotu));
   // qDebug()<<"utworzylo lot";
    Dostepne_polaczenia *polaczenie= new Dostepne_polaczenia(loty[n],DGodzWylotu,DGodzPrzylotu);
    pol.push_back(*polaczenie);
    ui->tabelaLotow->insertRow(n);
    ui->tabelaLotowAdmin->insertRow(n);
   // qDebug()<<"dodalo wiersz";
    MainWindow::ui->tabelaLotow->setItem(n,0,new QTableWidgetItem(pol[n].lotnisko_wylotu));
    MainWindow::ui->tabelaLotow->setItem(n,1,new QTableWidgetItem(pol[n].lotnisko_docelowe));
    MainWindow::ui->tabelaLotow->setItem(n,2,new QTableWidgetItem(pol[n].godzina_odlotu));
    MainWindow::ui->tabelaLotow->setItem(n,3,new QTableWidgetItem(pol[n].godzina_przylotu));
    MainWindow::ui->tabelaLotow->setItem(n,4,new QTableWidgetItem(pol[n].data_lotu));
    MainWindow::ui->tabelaLotowAdmin->setItem(n,0,new QTableWidgetItem(pol[n].lotnisko_wylotu));
    MainWindow::ui->tabelaLotowAdmin->setItem(n,1,new QTableWidgetItem(pol[n].lotnisko_docelowe));
    MainWindow::ui->tabelaLotowAdmin->setItem(n,2,new QTableWidgetItem(pol[n].godzina_odlotu));
    MainWindow::ui->tabelaLotowAdmin->setItem(n,3,new QTableWidgetItem(pol[n].godzina_przylotu));
    MainWindow::ui->tabelaLotowAdmin->setItem(n,4,new QTableWidgetItem(pol[n].data_lotu));
   //  qDebug()<<"zaladowalo do kolumn";

    n++;
    ui->comboBox->addItem(QString::number(n));
    ui->comboBoxAdmin->addItem(QString::number(n));
    ui->stackedWidget->setCurrentWidget(ui->AdminPanel);
    ui->lineLotniskoDocelowe->clear();
    ui->lineNrLotu->clear();
    ui->lineDataLotu->clear();
    ui->lineLotniskoWylotu->clear();
    ui->lineGodzinaWylotu->clear();
    ui->lineGodzinaPrzylotu->clear();
}

void MainWindow::on_przyciskUsunLot_clicked()
{
    int dousuniecia = ui->comboBoxAdmin->currentIndex();
    loty.removeAt(dousuniecia);
    ui->tabelaLotow->removeRow(dousuniecia);
    ui->tabelaLotowAdmin->removeRow(dousuniecia);
    n--;

}

void MainWindow::on_przyciskAnulowanieRezerw_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaAnulowanie);
}



void MainWindow::on_przyciskAnuluj_clicked()
{
    QString Anazw = ui->lineNazwiskoAnulacja->text();
    QString Anr=ui->lineNrTelAnulacja->text();

    for(int j=0;j<licznik_rezerwacji;j++)
        {

            if(rezerwacje[j].pokazNazwisko() == Anazw && rezerwacje[j].pokazNr_tel() == Anr)
            {
               --rezerwacje[j];
            }
         }
for(int x=0;x<licznik_kart;x++)
    {

        if(karty[x].pokazNazwisko() == Anazw && karty[x].pokazNr_tel() == Anr)
        {
           admin1->anuluj_rezerwacje(karty[x]);
           for (int k=0;k<n;k++)
           {
           if(karty[x].podajNr_lotu()==loty[k].podaj_nr_lotu() && karty[x].podajDate_lotu()==loty[k].podaj_date() )
           {

               loty[k].zwolnij_miejsce(karty[x].pokaz_karte());
               break;
           }

        }        ui->stackedWidget->setCurrentWidget(ui->AdminPanel);

           break;
        }

    }

}

void MainWindow::zapisywaniePolaczen()
{
    QFile plik_polaczenia("polaczeniaplik.txt");
    if(!plik_polaczenia.open(QIODevice::WriteOnly))
    {
        return;
    }
    QDataStream out(&plik_polaczenia);
    out.setVersion(QDataStream::Qt_5_10);

    for (int i=0;i<n;i++)
    {
        out<<pol[i].godzina_odlotu<<pol[i].godzina_przylotu;
    }
    plik_polaczenia.flush();
    plik_polaczenia.close();
}

void MainWindow::wczytywaniePolaczen()
{
    QFile plik_polaczenia("polaczeniaplik.txt");
    if(!plik_polaczenia.open(QIODevice::ReadOnly))
    {
        return;
    }
    QDataStream in(&plik_polaczenia);
    in.setVersion(QDataStream::Qt_5_10);

    for (int i=0;i<n;i++)
    {
      in>>pol[i].godzina_odlotu>>pol[i].godzina_przylotu;
    }

    plik_polaczenia.close();
}
