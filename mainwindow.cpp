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


 int n = 4;
 int licznik_rezerwacji=0;
class list;

Lot *sam1 = new Lot[n]
{
    Lot(180,"Airbus A319",180,"WAW"),
    Lot(180,"Airbus A319",180,"POZ"),
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

    if(haslo == "admin123")
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

    Rezerwacje *p1=new Rezerwacje(imie,nazwisko,nrtel,kraj);
    rezerwacje.push_back(*p1);
   licznik_rezerwacji++;
    ui->stackedWidget->setCurrentWidget(ui->stronaKartapok);
}




void MainWindow::on_przyciskZaezadzaj_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaZarzadzaj);
}

void MainWindow::on_przyciskPowrot_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->stronaLoty);

}

void MainWindow::on_przyciskSpr_clicked()
{
    //tu wstawic wyszukiwanie rezerwacji
    ui->stackedWidget->setCurrentWidget(ui->stronaKartapok);
}
