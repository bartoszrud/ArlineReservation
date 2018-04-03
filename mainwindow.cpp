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
Lot *sam2 = new Lot;
Lot *sam3 = new Lot;
Lot *sam4 = new Lot;

Dostepne_polaczenia *pol1 = new Dostepne_polaczenia(*sam1,"WRO", "14:20", "17:30", 120);





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupConnections();
     //ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej

    /*
    QStandardItemModel *model = new QStandardItemModel(1,2,this);
     model->setData(model->index(0,0), sam1->dane_lotu[0], Qt::DisplayRole);
     model->setData(model->index(0,1), sam1->dane_lotu[1], Qt::DisplayRole);
     ui->tabelaLotow->setModel(model);

     QDateTime date2 = QDateTime::currentDateTime();
     date2 = date2.addDays(1);
     QString date = date2.toString();
     date = date.chopped(13);

     model->insertColumn(2, QModelIndex());
     model->setData(model->index(0,2), date, Qt::DisplayRole);

     //date = QDateTime::currentDateTime()::toString()


    QStringListModel *model = new QStringListModel();
    model->setData(pol1->dane_lotu);
    ui->tabelaLotow->setModel(model);

    */

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_label_linkHovered(const QString &link)
{

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


