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






    void on_PrzyciskAdmin_clicked();

    //void on_PrzyciskZaloguj_clicked();

    void on_przyciskDalej_clicked();

    void on_przyciskZaezadzaj_clicked();

    void on_przyciskPowrot_clicked();

    void on_przyciskSpr_clicked();

    void on_przyciskAkceptuj_clicked();

    void on_przyciskStrgl_clicked();



    void on_przyciskAkceptujZarezerw_clicked();

    void on_przyciskStrglZarezerw_clicked();

    void on_przyciskRezerwuj_clicked();

    void on_przyciskZaplac_clicked();

    void on_przyciskStrglRezerwacje_clicked();

    void on_przyciskDodajLot_clicked();

public slots:
    void on_PrzyciskZaloguj_clicked();
    void rezerwujLot();
     void wyswietlanie(Dostepne_polaczenia  pol[]);

    void closeEvent(QCloseEvent *event);

private:
    Ui::MainWindow *ui;

    void setupConnections();
public:
    void zapisywanieKart();
    void zapisywanieRezerw();
    void wczytywanieRezerw();
    void wczytywanieKart();

};

#endif // MAINWINDOW_H
