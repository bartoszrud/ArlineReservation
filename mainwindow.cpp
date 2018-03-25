#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "samolot.h"
#include "rezerwacje.h"
#include "admin.h"

 Lot *sam1 = new Lot;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     ui->label->setText(sam1->wysw()); //wyświetla nazwę samolotu, ale będzie trzeba zaprzyjaźnić żeby nie robić osobnych funkcji dla kazdej zmiennej



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
