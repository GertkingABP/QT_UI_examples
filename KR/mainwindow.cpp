#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QListWidget>
#include <QModelIndex>
#include <QStringListModel>
#include <QAbstractItemModel>

/*////////////ИВТ-263 Козякин Андрей, КР В-1////////////*/

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->human->setText(QString(""));

    ui->date_birth->setDate(QDate::currentDate());
    ui->date_birth->setMinimumDate(QDate::currentDate());

    QStringList list;
    QStringListModel *model = new QStringListModel();
    model->setStringList(list);

    ui->listView->setModel(model);



    //Сигналы по работе с перечнем
    connect(ui->save, SIGNAL(clicked()), this, SLOT(save_human()));
    connect(ui->delete_2, SIGNAL(clicked()), this, SLOT(delete_human()));
    connect(ui->addhuman, SIGNAL(clicked()), this, SLOT(add_human()));
    connect(ui->listView, SIGNAL(clicked(QModelIndex)), this, SLOT(get_human()));
    c_humans = new QList<Human*>();
}



MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::save_human()//сейв именинника
{
    int row = ui->listView->currentIndex().row();
    Human *p = c_humans->value(row);

    if (QDate::currentDate() < ui->date_birth->date())
        p->date_birth = ui->date_birth->date();

    else
        QMessageBox::warning(this, "Внимание", "День Рождения уже прошёл!");

    p->human = ui->human->text();

    QStringListModel *model = (QStringListModel *) ui->listView->model();
    QModelIndex i = model->index(row);
    QStringList list = model->stringList();
    list[row] = p->human;
    model->setStringList(list);

    ui->listView->setModel(model);
    ui->listView->setCurrentIndex(i);
}



void MainWindow::delete_human()//удалить из перечня именинника
{
    int rop = ui->listView->currentIndex().row();

    if(rop >= 0)
    {
        c_humans->removeOne(c_humans->value(rop));
        QStringListModel *model = (QStringListModel *) ui->listView->model();
        QStringList list = model->stringList(); 
        list.removeOne(list[rop]);
        model->setStringList(list);

        ui->listView->setModel(model);

        if(c_humans->count() <= 0)
        {
            ui->groupBox->setEnabled(false);
            ui->delete_2->setEnabled(false);
        }
    }
}



void MainWindow::add_human()//добавить именинника
{
    Human *p = new Human();//новый человек
    c_humans->append(p);

    QStringListModel *model = (QStringListModel *) ui->listView->model();
    QStringList list = model->stringList();
    list.append(p->human);
    model->setStringList(list);

    QModelIndex i = model->index(c_humans->count() - 1);
    ui->listView->setModel(model);

    ui->listView->setCurrentIndex(i);
    ui->groupBox->setEnabled(true);
    ui->delete_2->setEnabled(true);
    ui->listView->setFocus();

    get_human();
}



void MainWindow::get_human()//получить именинника
{
    int row = ui->listView->currentIndex().row();
    ui->human->setText(c_humans->value(row)->human);
    ui->date_birth->setDate(c_humans->value(row)->date_birth);
}
