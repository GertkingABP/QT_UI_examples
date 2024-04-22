#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ClassAndEnum.h"

#include <iostream>
#include <string>
#include <regex>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QValidator *ev = new strvalidator(this);
    ui->string->setValidator(ev);

    connect(ui->save,SIGNAL(clicked()),this,SLOT(is_Ok()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::is_Ok()//авторы
{
    if(ui->string->hasAcceptableInput())
    {
        ui->info->setText("Запись сохранена");
        QMessageBox::information(this,"Корректность строки", "Поле авторов введено правильно");
    }

    else
    {
        ui->info->setText("Поле не сохранено(используйте ФИО с заглавных букв)");
        QMessageBox::warning(this,"Корректность строки", "Поле авторов введено неправильно");
    }
}

data_base mas[2]; //массив из 2 записей

int selected_button;//ВЫБОР ЗАПИСИ

void MainWindow::on_first_data_clicked()//1 ЗАПИСЬ
{
  selected_button = 1;

  ui->name->setText("");
  QDate date (01,01,2000);
  ui->date->setDate(QDate(2000,01,01));
  ui->date->setDisabled(1);
  ui->year->setValue(1900);
  //ui->age_inv->setText("Возраст изобретения: 121");
  ui->string->setText("");
  ui->info->setText("Выбрана запись 1");
  ui->nobel->setChecked(false);
  ui->patent->setChecked(false);

  ui->first_data->setDisabled(true);
  ui->nobel->setDisabled(true);
  ui->maths->setChecked(1);//очистка поля при переходе к записи
  ui->second_data->setDisabled(false);
}

void MainWindow::on_second_data_clicked()//2 ЗАПИСЬ
{
   selected_button = 2;

   ui->name->setText("");
   QDate date (01,01,2000);
   ui->date->setDate(QDate(2000,01,01));
   ui->date->setDisabled(1);
   ui->year->setValue(1900);
   //ui->age_inv->setText("Возраст изобретения: 121");
   ui->string->setText("");
   ui->info->setText("Выбрана запись 2");
   ui->nobel->setChecked(false);
   ui->patent->setChecked(false);

   ui->second_data->setDisabled(true);
   ui->nobel->setDisabled(true);
   ui->maths->setChecked(maths);//очистка поля при переходе к записи
   ui->first_data->setDisabled(false);
}

void MainWindow::on_save_clicked()//СОХРАНИТЬ ЗАПИСЬ
{
    int r=selected_button-1;

    mas[r].name=ui->name->text();
    mas[r].date=ui->date->date();

    mas[r].string=ui->string->text();
    mas[r].nobel=ui->nobel->isChecked();
    mas[r].patent=ui->patent->isChecked();

    mas[r].getYear(ui->year->value());

    //Для моды
    //int age1 = (mas[r].giveAge(ui->year->value()));
    //ui->age_inv->setText("Возраст изобретения: " + QString::number(age1));

    mas[r].getDate(ui->date->date());

    //СЕЙВ ДЛЯ РАДИОКНОПОК
    if (ui->eletronic->isChecked())
        mas[r].subj = 0;

    else if (ui->chemistry->isChecked())
        mas[r].subj = 1;

    else if (ui->phisics->isChecked())
        mas[r].subj = 2;

    else if (ui->biology->isChecked())
        mas[r].subj = 3;

    else if (ui->maths->isChecked())
        mas[r].subj = 4;

    ui->info->setText("Запись сохранена");

    //Проверка корректности поля авторов
    QString str;
    str = mas[r].string;

    int len = str.size();
    bool check = true; //признак правильной строки(если строка верна, то true останется)

    //Регулярное выражение
    regex regular("[А-Я]{1}[а-я]+\s[А-Я]{1}[а-я]+\s[А-Я]{1}[а-я]+$");

    //ИТОГОВАЯ ПРОВЕРКА
    if (check == false)
    {
        mas[r].string="";
        ui->info->setText("Поле не сохранено(используйте ФИО с заглавных букв)");
    }
}

void MainWindow::on_show_clicked()//ПОКАЗАТЬ ЗАПИСЬ
{
    int z = selected_button-1;

    if(mas[z].patent==true)
    {
        ui->date->setEnabled(true);
    }

    ui->name->setText(mas[z].name);
    //ui->year->setValue(1900);
    ui->string->setText(mas[z].string);
    ui->nobel->setChecked(mas[z].nobel);
    ui->patent->setChecked(mas[z].patent);
    ui->date->setDate(mas[z].date);
    ui->year->setValue(mas[z].giveYear());

    //Для моды
    //int age1 = (mas[z].giveAge(ui->year->value()));
    //ui->age_inv->setText("Возраст изобретения: " + QString::number(age1));

    ui->date->setDate(mas[z].giveDate());

    //ПОКАЗ РАДИОКНОПОК
    if(mas[z].subj == 0)
    {
        ui->eletronic->setChecked(1);
    }

    else if(mas[z].subj == 1)
    {
        ui->chemistry->setChecked(1);
    }

    else if(mas[z].subj == 2)
    {
        ui->phisics->setChecked(1);
    }

    else if(mas[z].subj == 3)
    {
        ui->biology->setChecked(1);
    }

    else if(mas[z].subj == 4)
    {
        ui->maths->setChecked(1);
    }
}
