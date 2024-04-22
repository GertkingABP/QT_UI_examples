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

//Новые слоты для 3 лабы
    void on_create_1_clicked();

    void on_create_10_clicked();

    void on_delete1_clicked();

    void on_list_itemSelectionChanged();

    void on_redact_clicked();

    void on_search_in_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
