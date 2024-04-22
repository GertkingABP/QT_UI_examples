#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "ClassAndEnum.h"

#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
#include "newmas.h"

#include <iostream>
#include <string>
#include <regex>
#include <QDebug>

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
    mas[r].getDate(ui->date->date());

    //СЕЙВ ДЛЯ РАДИОКНОПОК
    if (ui->electronic->isChecked())
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

    ui->string->setText(mas[z].string);
    ui->nobel->setChecked(mas[z].nobel);
    ui->patent->setChecked(mas[z].patent);
    ui->date->setDate(mas[z].date);
    ui->year->setValue(mas[z].giveYear());
    ui->date->setDate(mas[z].giveDate());

    //ПОКАЗ РАДИОКНОПОК
    if(mas[z].subj == 0)
    {
        ui->electronic->setChecked(1);
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
    //<<<<<<<<<<<<<<<<Это новое для 3 лабы>>>>>>>>>>>>>>>>//

    newMas maslist[100];
    int coun = 0;
    int but = 0;

    void MainWindow::on_create_1_clicked()//создать 1 запись
    {
         but++;

        //if(ui->list->currentRow() != 0)
        //{

    //Заполнение строки(как всей формы)
    maslist[coun].name = ui->name->text();
    maslist[coun].year = ui->year->value();
    maslist[coun].string=ui->string->text();
    maslist[coun].nobel = ui->nobel->isChecked();
    maslist[coun].patent = ui->patent->isChecked();
    maslist[coun].date = ui->date->date();

    if (ui->electronic->isChecked())
        maslist[coun].subj = 0;

    else if (ui->chemistry->isChecked())
        maslist[coun].subj = 1;

    else if (ui->phisics->isChecked())
        maslist[coun].subj = 2;

    else if (ui->biology->isChecked())
        maslist[coun].subj = 3;

    else
        maslist[coun].subj = 4;

    /*if(but > 50)
    {
        ui->sozd->setEnabled(0);
        ui->zapl->setEnabled(0);
    }

    if(but < 50)
    {
        ui->sozd->setEnabled(1);
        ui->zapl->setEnabled(1);
    }*/

    //Создание строки
    QString sub1;//здесь хранится выбранный предмет

    if(maslist[coun].subj == 0)
    {
        sub1 = "Электроника и ВТ";
        sub1.append(" ");
    }

    if(maslist[coun].subj == 1)
    {
        sub1 = "Химия";
        sub1.append("                  ");
    }

    if(maslist[coun].subj == 2)
    {
        sub1 = "Физика";
        sub1.append("                 ");
    }

    if(maslist[coun].subj == 3)
    {
        sub1 = "Биология";
        sub1.append("              ");
    }

    if(maslist[coun].subj == 4)
    {
        sub1 = "Математика";
        sub1.append("          ");
    }

    QString str1 = sub1 +"                                   "+ QString::number(maslist[coun].year)+"                                   "+maslist[coun].name;

    //Упорядочивание(если что, проверить)
    int index;

    //Цикл сортировки
    for(int i = 0; i <= coun; i++)
    {
        if(maslist[i].subj != maslist[coun].subj)//если области разные
        {
            if(maslist[coun].subj <= maslist[i].subj)//сортируем по ним
            {
                index = i;//переменная хранящая индекс, куда сохранять строку
                if(ui->list->currentRow() != 0)
                {
                    for(int j = coun; j >= i; j--)
                    {
                        maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1
                    }
                    coun++;
                    maslist[i] = maslist[coun];//присваиваем нужный элемент
                }
                break;
            }
        }
        //Если области одинаковы
        else
        {
            if(maslist[coun].year != maslist[i].year)
            {
            if(maslist[coun].year <= maslist[i].year)//сортируем по году
            {
                index = i;

                if(ui->list->currentRow()!=0)
                {
                    for(int j = coun; j >= i; j--)
                    {
                        maslist[j + 1]=maslist[j];//сдвигаем все элементы на 1
                    }
                    coun++;
                    maslist[i] = maslist[coun];//присваиваем нужный элемент
                }
                break;
             }
             }

            else//если год совпал
            {
                if(maslist[coun].name <= maslist[i].name)//сортируем по наименованию
                {
                    index = i;

                    if(ui->list->currentRow()!=0)
                    {
                        for(int j = coun; j >= i; j--)
                        {
                            maslist[j + 1]=maslist[j];//сдвигаем все элементы на 1
                        }
                        coun++;
                        maslist[i] = maslist[coun];//присваиваем нужный элемент
                    }
                    break;
                 }
            }

        }
    }






     ui->list->insertItem(index,str1);//вставка нужной записи

    //but++;

        if(but > 0)
        {
            ui->delete1->setEnabled(1);
            ui->redact->setEnabled(1);
        }

        if(but > 59)
        {
            ui->create_1->setEnabled(0);
            ui->create_10->setEnabled(0);
        }

        if(but < 59)
        {
            ui->create_1->setEnabled(1);
            ui->create_10->setEnabled(1);
        }


    }



   newMas maszaplist[10];

    void MainWindow::on_create_10_clicked()//заполнение 10 готовыми записями
    {
       but = but + 10;

       //10 ЗАПИСЕЙ

       //Заполнение 1 записи +
       maszaplist[0].subj = 4;
       maszaplist[0].name = "Пример из алгебры";
       maszaplist[0].year = 1985;
       maszaplist[0].string = "John Rey Smith";
       maszaplist[0].nobel = false;
       maszaplist[0].patent = true;
       QDate d0(2010,8,15);
       maszaplist[0].date = d0;

       //Заполнение 2 записи +
       maszaplist[4].subj = 3;
       maszaplist[4].name = "Нейтрон";
       maszaplist[4].year = 1932;
       maszaplist[4].string = "Sir James Chadwick";
       maszaplist[4].nobel = true;
       maszaplist[4].patent = false;
       QDate d4(1900,1,1);
       maszaplist[4].date = d4;

       //Заполнение 3 записи + 
       maszaplist[1].subj = 4;
       maszaplist[1].name = "Теоремы о неполноте";
       maszaplist[1].year = 1931;
       maszaplist[1].string = "Kurt Friedrich Godel";
       maszaplist[1].nobel = false;
       maszaplist[1].patent = true;
       QDate d1(1931,4,27);
       maszaplist[1].date = d1;

       //Заполнение 4 записи +
       maszaplist[7].subj = 0;
       maszaplist[7].name = "Прототип интернета";
       maszaplist[7].year = 1969;
       maszaplist[7].string = "The Network Arpanet";
       maszaplist[7].nobel = false;
       maszaplist[7].patent = false;
       QDate d7(1900,1,1);
       maszaplist[7].date = d7;

       //Заполнение 5 записи +
       maszaplist[6].subj = 1;
       maszaplist[6].name = "Ядерное деление в атомах урана и тория";
       maszaplist[6].year = 1938;
       maszaplist[6].string = "The Otto Hahn";
       maszaplist[6].nobel = false;
       maszaplist[6].patent = false;
       QDate d6(1900,1,1);
       maszaplist[6].date = d6;

       //Заполнение 6 записи +
       maszaplist[8].subj = 0;
       maszaplist[8].name = "Мультиварка";
       maszaplist[8].year = 1956;
       maszaplist[8].string = " Это Ёситада Минами";
       maszaplist[8].nobel = false;
       maszaplist[8].patent = true;
       QDate d8(1956,9,3);
       maszaplist[8].date = d8;

       //Заполнение 7 записи +
       maszaplist[5].subj = 2;
       maszaplist[5].name = "Пусто(как пример)";
       maszaplist[5].year = 2000;
       maszaplist[5].string = "Abc Def Ghi";
       maszaplist[5].nobel = true;
       maszaplist[5].patent = true;
       QDate d5(2000,2,6);
       maszaplist[5].date = d5;

       //Заполнение 8 записи +
       maszaplist[9].subj = 0;
       maszaplist[9].name = "Вычислительная машина Z3";
       maszaplist[9].year = 1941;
       maszaplist[9].string = "The Konrad Zuse";
       maszaplist[9].nobel = false;
       maszaplist[9].patent = true;
       QDate d9(1941,5,12);
       maszaplist[9].date = d9;

       //Заполнение 9 записи +
       maszaplist[3].subj = 3;
       maszaplist[3].name = "Секвенирование ДНК";
       maszaplist[3].year = 1977;
       maszaplist[3].string = "The Frederick Sanger, The Walter Gilbert, The Allan Maxem";
       maszaplist[3].nobel = false;
       maszaplist[3].patent = true;
       QDate d3(1977,1,1);
       maszaplist[3].date = d3;

       //Заполнение 10 записи +
       maszaplist[2].subj = 4;
       maszaplist[2].name = "Список 23 нерешённых задач";
       maszaplist[2].year = 1900;
       maszaplist[2].string = "The David Hilbert";
       maszaplist[2].nobel = false;
       maszaplist[2].patent = false;
       QDate d2(1900,1,1);
       maszaplist[2].date = d2;

       QString sub1;//здесь хранится выбранный предмет

       for (int i = 0; i < 10; i++)
       {

           if(ui->list->currentRow() != 0)
           {
           ui->name->setText(maslist[i].name);
           ui->year->setValue(maslist[i].year);
           ui->string->setText(maslist[i].string);
           ui->nobel->setChecked(maslist[i].nobel);
           ui->patent->setChecked(maslist[i].patent);
           ui->date->setDate(maslist[i].date);

           if(ui->patent->isChecked() == false)
           {
               ui->groupBox->setEnabled(0);
           }

           else if(ui->patent->isChecked() == true)
           {
               ui->groupBox->setEnabled(1);
           }

        maslist[coun].subj = maszaplist[i].subj;
        maslist[coun].name = maszaplist[i].name;
        maslist[coun].year = maszaplist[i].year;
        maslist[coun].string = maszaplist[i].string;
        maslist[coun].nobel = maszaplist[i].nobel;
        maslist[coun].patent = maszaplist[i].patent;
        maslist[coun].date = maszaplist[i].date;

        //Создание строки
        QString sub1;//здесь хранится выбранный предмет

        if(maslist[coun].subj == 0)
        {
            sub1 = "Электроника и ВТ";
            sub1.append(" ");
        }

        if(maslist[coun].subj == 1)
        {
            sub1 = "Химия";
            sub1.append("                  ");
        }

        if(maslist[coun].subj == 2)
        {
            sub1 = "Физика";
            sub1.append("                 ");
        }

        if(maslist[coun].subj == 3)
        {
            sub1 = "Биология";
            sub1.append("              ");
        }

        if(maslist[coun].subj == 4)
        {
            sub1 = "Математика";
            sub1.append("          ");
        }

        QString str1 = sub1 +"                                   "+ QString::number(maslist[coun].year)+"                                   "+maslist[coun].name;


        int index;
        for(int k = 0 ;k <= coun; k++)//цикл для обхода массива
        {
                if(maslist[coun].subj != maslist[k].subj)//если области разные
                {
                if(maslist[coun].subj <= maslist[k].subj)//сортируем по ним
                {
                    index = k;
                    if(ui->list->currentRow()!=0)
                    {
                        for(int j = coun; j >= k; j--)
                        {
                            maslist[j + 1]=maslist[j];//сдвигаем все элементы на 1 элемент
                        }
                        coun++;
                        maslist[k] = maslist[coun];//присваиваем выбранный элемент
                    }
                    break;
                  }
                }
                else//если области одинаковые
                {
                    if(maslist[coun].year != maslist[k].year)
                    {
                    if(maslist[coun].year <= maslist[k].year)//сортируем по году
                    {
                        index = k;
                        if(ui->list->currentRow()!=0)
                        {
                            for(int j = coun; j >= k; j--)
                            {
                                maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1 элемент
                            }
                            coun++;
                            maslist[k] = maslist[coun];//присваиваем выбранный элемент
                        }
                        break;
                    }
                    }
                    else//если годы одинаковые
                    {
                        if(maslist[coun].name <= maslist[k].name)//сортируем по наименованию
                        {
                            index = k;
                            if(ui->list->currentRow()!=0)
                            {
                                for(int j = coun; j >= k; j--)
                                {
                                    maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1 элемент
                                }
                                coun++;
                                maslist[k] = maslist[coun];//присваиваем выбранный элемент
                            }
                            break;
                        }
                    }
                }
        }


        coun++;

        ui->list->insertItem(index, str1);

        if(but > 0)
        {
            ui->delete1->setEnabled(1);
            ui->redact->setEnabled(1);
        }

        if(but > 50)
        {
            ui->create_1->setEnabled(0);
            ui->create_10->setEnabled(0);
        }

        if(but < 50)
        {
            ui->create_1->setEnabled(1);
            ui->create_10->setEnabled(1);
        }
       }
     }
  }

    void MainWindow::on_delete1_clicked()//удаление записи
    {
        but--;

        if(but > 0)
        {
            ui->delete1->setEnabled(1);//кнопка "удалить" активна
            ui->redact->setEnabled(1);//кнопка "редактировать" активна
        }

        if(but <= 0)
        {
            ui->delete1->setEnabled(0);//кнопка "удалить" активна
            ui->redact->setEnabled(0);//кнопка "редактировать" активна
        }

        if(but > 61)
        {
            ui->create_1->setEnabled(0);
            ui->create_10->setEnabled(0);
        }

        if(but < 61)
        {
            ui->create_1->setEnabled(1);
            ui->create_10->setEnabled(1);
        }

        for (int i = ui->list->currentRow(); i <= coun; i++)
        {
            maslist[i]=maslist[i + 1];
        }

        QListWidgetItem *item = ui->list->takeItem(ui->list->currentRow());
        delete item;
        coun--;
    }




    void MainWindow::on_list_itemSelectionChanged()//наведение на строку листа
    {
      if(ui->list->currentRow() >= 0)
      {
        if(maslist[ui->list->currentRow()].subj == 0)
            ui->electronic->setChecked(1);

        else if(maslist[ui->list->currentRow()].subj == 1)
            ui->chemistry->setChecked(1);

        else if(maslist[ui->list->currentRow()].subj == 2)
            ui->phisics->setChecked(1);

        else if(maslist[ui->list->currentRow()].subj == 3)
            ui->biology->setChecked(1);

        else if(maslist[ui->list->currentRow()].subj == 4)
            ui->maths->setChecked(1);

        ui->name->setText(maslist[ui->list->currentRow()].name);
        ui->year->setValue(maslist[ui->list->currentRow()].year);
        ui->string->setText(maslist[ui->list->currentRow()].string);
        ui->nobel->setChecked(maslist[ui->list->currentRow()].nobel);
        ui->patent->setChecked(maslist[ui->list->currentRow()].patent);
        ui->date->setDate(maslist[ui->list->currentRow()].date);
        qDebug() << maslist[ui->list->currentRow()].subj;

        if(ui->patent->isChecked() == false)
        {
            ui->groupBox->setEnabled(0);
        }

        if(ui->patent->isChecked() == true)
        {
            ui->groupBox->setEnabled(1);
        }
      }

    }




void MainWindow::on_redact_clicked()//редактирование 1 записи
{
    int selected = ui->list->currentRow();

    //чекни это
    if (ui->electronic->isChecked())
        maslist[selected].subj = 0;

    else if (ui->chemistry->isChecked())
        maslist[selected].subj = 1;

    else if (ui->phisics->isChecked())
        maslist[selected].subj = 2;

    else if (ui->biology->isChecked())
        maslist[selected].subj = 3;

    else if (ui->maths->isChecked())
        maslist[selected].subj = 4;


    if(maslist[selected].subj == 0)
        ui->electronic->setChecked(1);

    else if(maslist[selected].subj == 1)
        ui->chemistry->setChecked(1);

    else if(maslist[selected].subj == 2)
        ui->phisics->setChecked(1);

    else if(maslist[selected].subj == 3)
        ui->biology->setChecked(1);

    else if(maslist[selected].subj == 4)
        ui->maths->setChecked(1);

    //далее
    maslist[selected].name = ui->name->text();
    maslist[selected].year = ui->year->value();
    maslist[selected].string=ui->string->text();
    maslist[selected].nobel = ui->nobel->isChecked();
    maslist[selected].patent = ui->patent->isChecked();
    maslist[selected].date = ui->date->date();

    //для записи в строку, сразу нескольких полей строки
    QString str1;

    QString sub1;//добавим предмет в общую строку листа

    if(maslist[selected].subj == 0)
    {
        sub1 = "Электроника и ВТ";
        sub1.append(" ");
    }

    if(maslist[selected].subj == 1)
    {
        sub1 = "Химия";
        sub1.append("                  ");
    }

    if(maslist[selected].subj == 2)
    {
        sub1 = "Физика";
        sub1.append("                 ");
    }

    if(maslist[selected].subj == 3)
    {
        sub1 = "Биология";
        sub1.append("              ");
    }

    if(maslist[selected].subj == 4)
    {
        sub1 = "Математика";
        sub1.append("          ");
    }

    str1 = sub1;
    str1.append("                                   ");
    str1.append(QString::number(maslist[selected].year));
    str1.append("                                   ");
    str1.append(maslist[selected].name);

    maslist[coun].name = ui->name->text();
    maslist[coun].year = ui->year->value();
    maslist[coun].string = ui->string->text();
    maslist[coun].nobel = ui->nobel->isChecked();
    maslist[coun].patent = ui->patent->isChecked();
    maslist[coun].date = ui->date->date();

    maslist[coun].subj = maslist[selected].subj;

    if (selected >= 0) // проверка на то, что не выбрана "нулевая" строка (ее нельзя редактировать, в нее ничего не записывается)
    {
        for (int i = selected; i < coun ; i++)
        { // "временное РАСШИРЕНИЕ МАССИВА"
            maslist[i] = maslist[i + 1]; // смещение всех объектов массива вправо на 1 элемент, начиная с найденного
        }

    QListWidgetItem *item=ui->list->takeItem(selected); // удаление выбранной строки
    delete item;
    coun--;

    if (selected <= coun) // для корректного обхода при редактировании
        ui->list->setCurrentRow(ui->list->currentRow());

    else
        ui->list->setCurrentRow(ui->list->currentRow());
    }

    int index; // переменная для хранения индекса вставления строки после сортировки в браузер

    for (int i = 0; i <= coun; i++) //цикл для прохождения всего браузре построчно
    {
        if(maslist[coun].subj != maslist[i].subj)//сортировка по области
        {
            if(maslist[coun].subj <= maslist[i].subj)//если разные
            {
                index = i;
                if (selected >= 0)
                {
                    for (int j = coun; j >= i; j--) // цикл для сдвига на 1 элемент вправо в массиве объектов
                    {
                        maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1 элемент
                    }

                    coun++;

                    maslist[i] = maslist[coun]; // присвоение выбранного элемента в нужное место после сортировки
                }
                break;
            }
        }
            else//если области одинаковые
            {
                if(maslist[coun].year != maslist[i].year)
                {
                if(maslist[coun].year <= maslist[i].year)//сортировка по году
                {
                index = i;
                if (selected >= 0)
                {
                    for (int j = coun; j >= i ; j--)
                    {
                        maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1 элемент
                    }

                    coun++;

                    maslist[i] = maslist[coun]; // присвоение нужного
                }
                break;
                }
                }
                else//если годы одинаковые
                {
                    if(maslist[coun].name <= maslist[i].name)//сортировка по наименованию
                    {
                    index = i;
                    if (selected >= 0)
                    {
                        for (int j = coun; j >= i ; j--)
                        {
                            maslist[j + 1] = maslist[j];//сдвигаем все элементы на 1 элемент
                        }

                        coun++;

                        maslist[i] = maslist[coun]; // присвоение нужного
                    }
                    break;
                    }
               }

            }
     }

     ui->list->insertItem(index,str1); // вставка нужной строки в определенное место в браузере
}

// //////////////////////////////Модификация с поиском 3 записей/////////////////////////////////// //

QString search_;
newMas new_mas[100];//записи поиска(оттуда уже потом выводим 3 записи)
newMas end_mas[3];//конечный массив из 3 записей

void MainWindow::on_search_in_clicked()
{
    QString searching = ui-> search_string -> text();
    qDebug() << searching;
    int len_2 = searching.size();
    int count_massives =  ui->list->count(); //кол-во записей изначально
    qDebug() << count_massives;
    coun = 0;
    int i, j;

    ui->list->clear();//очистка самого листа перед 3 записями

    int count_new_mas = 0;//счётчик для нового массива

    //Цикл создания массива одной области
    for (i = 0; i < count_massives; i++)//пробежка по всем созданным записям
    {
        if(((searching == "Электроника и ВТ") && (maslist[i].subj == 0)) || ((searching == "Химия") && (maslist[i].subj == 1)) || ((searching == "Физика") && (maslist[i].subj == 2)) || ((searching == "Биология") && (maslist[i].subj == 3)) || ((searching == "Математика") && (maslist[i].subj == 4)))
        {
            new_mas[coun].subj = maslist[i].subj;
            new_mas[coun].name = maslist[i].name;
            new_mas[coun].year = maslist[i].year;
            new_mas[coun].string = maslist[i].string;
            new_mas[coun].nobel = maslist[i].nobel;
            new_mas[coun].patent = maslist[i].patent;
            new_mas[coun].date = maslist[i].date;

            coun--;
            count_new_mas++; //кол-во записей с одним предметом
         }
    }


    //Вывод 3 записей из нового массива
    coun = 0;

    if(count_new_mas <= 3)//если до 3, то просто все вывести
    {
        qDebug() << count_new_mas;
        //coun =  count_new_mas - 1;
        coun = 0;
        for (j = 0; j < count_new_mas; j++)//пробежка по всем созданным записям
        {
            end_mas[j].subj = new_mas[coun].subj;
            end_mas[j].name = new_mas[coun].name;
            end_mas[j].year = new_mas[coun].year;
            end_mas[j].string = new_mas[coun].string;
            end_mas[j].nobel = new_mas[coun].nobel;
            end_mas[j].patent = new_mas[coun].patent;
            end_mas[j].date = new_mas[coun].date;

            QString str1 = searching +"                                   "+ QString::number(end_mas[j].year)+"                                   "+end_mas[j].name;
            ui -> list -> insertItem(0, str1);    // вставка нужной строки в определенное место в браузере

            coun--;
        }

    }

    else//если более 3
    {
        qDebug() << count_new_mas;
        //coun =  count_new_mas - 1;
        coun = 0;
        for (i = 0; i < 3; i++)//пробежка по всем созданным записям
        {
            end_mas[i].subj = new_mas[coun].subj;
            end_mas[i].name = new_mas[coun].name;
            end_mas[i].year = new_mas[coun].year;
           /* end_mas[i].string = new_mas[coun].string;
            end_mas[i].nobel = new_mas[coun].nobel;
            end_mas[i].patent = new_mas[coun].patent;
            end_mas[i].date = new_mas[coun].date;*/

            QString str1 = searching +"                                   "+ QString::number(end_mas[i].year)+"                                   "+end_mas[i].name;
            ui -> list -> insertItem(0, str1);    // вставка нужной строки в определенное место в браузере


            coun++;
        }

    }
}


