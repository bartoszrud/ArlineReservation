#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "samolot.h"
#include "rezerwacje.h"
#include "admin.h"
#include <QTableWidget>
#include <QStandardItemModel>

 Lot *sam1 = new Lot;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej

    QStandardItemModel *model = new QStandardItemModel(1,2,this);
    model->setData(model->index(0,0), sam1->wysw(), Qt::DisplayRole);
    model->setData(model->index(0,1), "locik", Qt::DisplayRole);
    ui->tableView->setModel(model);



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
