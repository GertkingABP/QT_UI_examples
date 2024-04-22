#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QValidator *ev = new ExampleValidator(this);
    ui->text->setValidator(ev);

    connect(ui->checkButton,SIGNAL(clicked()),this,SLOT(is_Ok()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::is_Ok()
{
    if(ui->text->hasAcceptableInput())
        QMessageBox::information(this,"Корректность строки", "Пол введён правильно");
    else
        QMessageBox::warning(this,"Корректность строки", "Пол введён неправильно");
}
