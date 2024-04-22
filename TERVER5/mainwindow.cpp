#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <algorithm>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Кнопки построения полигонов частот
    connect(ui->V2_poli_ch, SIGNAL(clicked(bool)), this, SLOT(on_V2_poli_ch_clicked()));
    connect(ui->V5_poli_ch, SIGNAL(clicked(bool)), this, SLOT(on_V5_poli_ch_clicked()));
    connect(ui->V9_poli_ch, SIGNAL(clicked(bool)), this, SLOT(on_V9_poli_ch_clicked()));
}

//----------------------------------------Полигоны частот----------------------------------------//

void MainWindow::on_V2_poli_ch_clicked()
{
    ui->widget->clearPlottables();
    //(В-2)
    const int len = 40;
    float arr[len] = {4.3, 4.6, 4.5, 4.6, 4.7, 4.6, 4.6, 4.7, 4.5, 4.5,
                      4.6, 4.8, 4.9, 4.8, 4.4, 5.0, 4.8, 4.6, 4.4, 5.0,
                      4.5, 4.4, 4.6, 4.6, 4.5, 4.7, 4.5, 4.5, 4.5, 4.6,
                      4.4, 4.6, 4.7, 5.0, 4.5, 4.4, 4.5, 4.3, 4.5, 4.4};

    //Делаем вариационный(по порядку)
    sort(arr, arr + len);

    //Делаем статистические(без повторений) Xi и Ni
    float a;//для фиксации
    int N = 0;//для счёта размерности статистических рядов
    a = arr[0];
    int i = 0
            ;
    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        N++;
        a = arr[i];
    }

    float *x_arr = new float[N];//Xi
    int j = 0;//для индексов статистических Xi, Ni
    a = arr[0];
    i = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        x_arr[j] = arr[i - 1];
        j++;
        a = arr[i];
    }

    //Был ряд Xi
    int *n_arr = new int[N];//Ni
    int count = 0;//для счёта частот
    a = arr[0];
    i = 0;
    j = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
        {
            i++;
            count++;
        }
        n_arr[j] = count;
        j++;
        count = 0;
        a = arr[i];
    }

    //Это был ряд Ni
    //Находим максимальную частоту для Oy
    float max = 0;
    for (int i = 0; i < N; i++)
    {
        if(n_arr[i] > max)
            max = n_arr[i];
    }

    //Установка осей
    ui->widget->xAxis->setRange(0, x_arr[N - 1]);
    ui->widget->yAxis->setRange(0, max);

    //Отрисовка полигона по точкам
    for(int i = 0; i < N; i++)
    {
         x.push_back(x_arr[i]);
         y.push_back(n_arr[i]);
    }

    //Показать полигон
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

void MainWindow::on_V5_poli_ch_clicked()
{
    ui->widget->clearPlottables();

    //(В-5)
    const int len = 40;
    float arr[len] = {15, 9, 13, 16, 14, 16, 17, 12, 14, 17,
                      10, 16, 18, 13, 10, 14, 12, 16, 14, 18,
                      11, 13, 9, 15, 13, 15, 16, 15, 12, 13,
                      11, 14, 14, 14, 15, 14, 10, 13, 15, 14};

    //Делаем вариационный(по порядку)
    sort(arr, arr + len);

    //Делаем статистические(без повторений) Xi и Ni
    float a;//для фиксации
    int N = 0;//для счёта размерности статистических рядов
    a = arr[0];
    int i = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        N++;
        a = arr[i];
    }

    float *x_arr = new float[N];//Xi
    int j = 0;//для индексов статистических Xi, Ni
    a = arr[0];
    i = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        x_arr[j] = arr[i - 1];
        j++;
        a = arr[i];
    }

    //Был ряд Xi
    int *n_arr = new int[N];//Ni
    int count = 0;//для счёта частот
    a = arr[0];
    i = 0;
    j = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
        {
            i++;
            count++;
        }

        n_arr[j] = count;
        j++;
        count = 0;
        a = arr[i];
    }

    //Это был ряд Ni
    //Находим максимальную частоту для Oy
    float max = 0;

    for (int i = 0; i < N; i++)
    {
        if(n_arr[i] > max)
            max = n_arr[i];
    }

    //Установка осей
    ui->widget->xAxis->setRange(0, x_arr[N - 1]);
    ui->widget->yAxis->setRange(0, max);

    //Отрисовка полигона по точкам
    for(int i = 0; i < N; i++)
    {
         x.push_back(x_arr[i]);
         y.push_back(n_arr[i]);
    }

    //Показать полигон
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

void MainWindow::on_V9_poli_ch_clicked()
{
    ui->widget->clearPlottables();
    //Мой массив(В-9)
    const int len = 40;
    float arr[len] = {27, 32, 22, 32, 29, 26, 35, 31, 39, 31,
                      33, 27, 32, 26, 28, 35, 25, 35, 35, 40,
                      27, 34, 29, 30, 32, 25, 30, 31, 39, 25,
                      33, 29, 27, 32, 34, 30, 36, 31, 36, 36};

    //Делаем вариационный(по порядку)
    sort(arr, arr + len);

    //Делаем статистические(без повторений) Xi и Ni
    float a;//для фиксации
    int N = 0;//для счёта размерности статистических рядов
    a = arr[0];
    int i = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        N++;
        a = arr[i];
    }

    float *x_arr = new float[N];//Xi
    int j = 0;//для индексов статистических Xi, Ni
    a = arr[0];
    i = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
            i++;

        x_arr[j] = arr[i - 1];
        j++;
        a = arr[i];
    }

    //Был ряд Xi
    int *n_arr = new int[N];//Ni
    int count = 0;//для счёта частот
    a = arr[0];
    i = 0;
    j = 0;

    while (i < len)
    {
        while (a == arr[i] && i < len)
        {
            i++;
            count++;
        }

        n_arr[j] = count;
        j++;
        count = 0;
        a = arr[i];
    }

    //Это был ряд Ni

    //Находим максимальную частоту для Oy
    float max = 0;

    for (int i = 0; i < N; i++)
    {
        if(n_arr[i] > max)
            max = n_arr[i];
    }

    //Установка осей
    ui->widget->xAxis->setRange(0, x_arr[N - 1]);
    ui->widget->yAxis->setRange(0, max);

    //Отрисовка полигона по точкам
    for(int i = 0; i < N; i++)
    {
         x.push_back(x_arr[i]);
         y.push_back(n_arr[i]);
    }

    //Показать полигон
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(x, y);
    ui->widget->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clear_plot_clicked()
{
    ui->widget->clearPlottables();
}

