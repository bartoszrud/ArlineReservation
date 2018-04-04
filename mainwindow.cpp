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



Lot *sam1 = new Lot;
Lot *sam2 = new Lot(140,"Airbus A319",140,"KEF");
Lot *sam3 = new Lot;
Lot *sam4 = new Lot;

Dostepne_polaczenia *pol1 = new Dostepne_polaczenia(*sam1,"WRO", "14:20", "17:30", 120);

void wyswietlanie(Dostepne_polaczenia & pol);




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
     //ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej
    wyswietlanie(*pol1);



}

void MainWindow::wyswietlanie(Dostepne_polaczenia & pol)
{
MainWindow::ui->tabelaLotow->setItem(0,0,new QTableWidgetItem(pol.lotnisko_docelowe));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{


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


