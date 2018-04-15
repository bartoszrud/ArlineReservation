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
#include <adminwindow.h>
#include <QList>
#include <fstream>


 int n = 4;
 int licznik_rezerwacji=0;
 int licznik_kart=0;
 int ktora_rezerwacja=0;

 Admin *admin1=new Admin;

Lot *sam1 = new Lot[n]
{
    Lot(180,"Airbus A319",180,"WAW"),
    Lot(180,"Airbus A319",180,"POZ"),
    Lot(180,"Airbus A319",180,"OSL"),
};

Dostepne_polaczenia *pol1 = new Dostepne_polaczenia[n];
QList<Rezerwacje> rezerwacje;
QList<Karta_pokladowa> karty;


void wyswietlanie(Dostepne_polaczenia  pol[]);




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
     //ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej
    ui->statusBar->addPermanentWidget(ui->PrzyciskAdmin); //Przycisk w StatusBar


    wyswietlanie(pol1);

}

void MainWindow::wyswietlanie(Dostepne_polaczenia  pol[])
{
    for (int i=0;i<n;i++)
    {
        pol1[i]= Dostepne_polaczenia(sam1[i]);
    }
    for(int i=0;i<n;i++){
MainWindow::ui->tabelaLotow->setItem(i,0,new QTableWidgetItem(pol[i].lotnisko_wylotu));
MainWindow::ui->tabelaLotow->setItem(i,1,new QTableWidgetItem(pol[i].lotnisko_docelowe));
MainWindow::ui->tabelaLotow->setItem(i,2,new QTableWidgetItem(pol[i].godzina_odlotu));
MainWindow::ui->tabelaLotow->setItem(i,3,new QTableWidgetItem(pol[i].godzina_przylotu));
MainWindow::ui->tabelaLotow->setItem(i,4,new QTableWidgetItem(pol[i].data_lotu));
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

    if(admin1->sprHaslo(haslo))
    {
    hide();
    adminwindow *admwin =new adminwindow(this);
     admwin->show();
    }
    else
    {
        ui->statusBar->showMessage("Wprowadzono błędne hasło, spróbuj ponownie.",2000);
    }
}

void MainWindow::on_przyciskDalej_clicked()
{

    QString imie = ui->lineImie->text();
    QString nazwisko = ui->lineNazwisko->text();
    QString nrtel = ui->lineNrTelefonu->text();
    QString kraj = ui->lineKraj->text();

    Rezerwacje *p1=new Rezerwacje(sam1[1],imie,nazwisko,nrtel,kraj);
    rezerwacje.push_back(*p1);
    licznik_rezerwacji+=1;
    ui->stackedWidget->setCurrentWidget(ui->stronaKartapok);
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

for(int x=0;x<licznik_rezerwacji;x++)
{
        if(karty[x].match(Snazw,Snr)==true)
        {
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

 //wstawic sprawdzanie czy pasazer ma juz wykupiony bagaz lub priority

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

    karty[licznik_kart].wybierz_miejsce(ui->spinBox->value());
   //std:: ofstream plik("karty.dat" , std::ios_base::out | std::ios_base::app | std::ios_base::binary);
   //plik.write( karty[licznik_kart], sizeof karty[licznik_kart]);
licznik_kart++;
   // QString s = QString::number(licznik_rezerwacji);
    //ui->statusBar->showMessage(s,2000);
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
    ui->checkBagaz->setChecked(false);
    ui->checkPriority->setChecked(false);
}


void MainWindow::on_przyciskStrgl_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}



//const char FileName[] = "plik.bin";

/*
void MainWindow::closeEvent(QCloseEvent *event){

    std::ofstream file;
       file.write( FileName, std::ios::binary | std::ios::app );
       if( file.good() )
       {
           for (int i=0;i<licznik_kart;i++){
           file.write( reinterpret_cast < char *>(karty[i] ), sizeof( karty[i] ) );
           file.close();
           }
       }
}
*/


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

    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}

void MainWindow::on_przyciskStrglZarezerw_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);
}
