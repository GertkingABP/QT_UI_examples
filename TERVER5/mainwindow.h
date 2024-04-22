#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_V2_poli_ch_clicked();

    void on_V5_poli_ch_clicked();

    void on_V9_poli_ch_clicked();


    void on_clear_plot_clicked();

private:

    Ui::MainWindow *ui;
    double xBegin, xEnd, h, X;
    int N;
    QVector<double> x, y;
    void graph_func(const int len, float *arr);
};
#endif // MAINWINDOW_H
