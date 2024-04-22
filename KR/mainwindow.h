#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <classhuman.h>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QList<Human*> *c_humans;

private slots:
    void save_human();
    void delete_human();
    void add_human();
    void get_human();
};

#endif // MAINWINDOW_H
