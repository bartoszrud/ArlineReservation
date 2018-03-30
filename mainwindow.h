#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <adminwindow.h>

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

private:
    Ui::MainWindow *ui;
    AdminWindow *adminwin;
};

#endif // MAINWINDOW_H
