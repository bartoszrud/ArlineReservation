#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "samolot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Samolot *sam1 = new Samolot;
}

MainWindow::~MainWindow()
{
    delete ui;
}
