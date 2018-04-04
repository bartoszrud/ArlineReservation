#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dostepne_polaczenia.h>

class Dostepne_polaczenia;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_label_linkActivated(const QString &link);

    void on_label_linkHovered(const QString &link);

    void on_pushButton_clicked();

    void on_przyciskRezerwuj_clicked();


public slots:
    void rezerwujLot();
     void wyswietlanie(Dostepne_polaczenia & pol);

private:
    Ui::MainWindow *ui;

    void setupConnections();
};

#endif // MAINWINDOW_H
