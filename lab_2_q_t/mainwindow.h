#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "strvalidator.h"
#include "ClassAndEnum.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_first_data_clicked();

    void on_second_data_clicked();

    void on_save_clicked();

    void on_show_clicked();

    void is_Ok();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
