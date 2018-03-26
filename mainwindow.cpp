#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "samolot.h"
#include "rezerwacje.h"
#include "admin.h"
#include <QTableWidget>
#include <QStandardItemModel>
#include <QDateTime>

 Lot *sam1 = new Lot;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    QPushButton *train_button = new QPushButton(this);
    train_button->setText(tr("something"));
    train_button->move(500, 500);
    train_button->show();

   // ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej
    ui->statusBar->addPermanentWidget(ui->pushButton); //Przycisk w StatusBar
    QStandardItemModel *model = new QStandardItemModel(1,4,this);
         model->setData(model->index(0,0), "samolocik", Qt::DisplayRole);
         model->setData(model->index(0,1), "leic sobie ", Qt::DisplayRole);
         ui->tableView->setModel(model);

         QDateTime date2 = QDateTime::currentDateTime();
         date2 = date2.addDays(1);
         QString date = date2.toString();
         date = date.chopped(13);

         model->insertColumn(2, QModelIndex());
         model->setData(model->index(0,2), date, Qt::DisplayRole);


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


