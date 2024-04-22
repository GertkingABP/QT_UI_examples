#ifndef CLASSANDENUM_H
#define CLASSANDENUM_H
#include <QDate>

class data_base
{
public:
    int subj;//для сейва и показа радиокнопки
    QString name;
    int year;
    QString string;
    bool nobel;
    bool patent;
    QDate date;

    //Для корректного сохранения, сброса и показа года(числа) и даты патента
    void getYear(int year_in)
    {
        year = year_in;
    }

    int giveYear()
    {
        return year;
    }

    //Мода
    /*int giveAge(int year)
    {
        int age = 2021 - year;
        return age;
    }*/

    void getDate(QDate date_in)
    {
        date = date_in;
    }

    QDate giveDate()
    {
        return date;
    }


};

//data_base mas[2]; //массив из 2 записей

enum combobox_subjects //енам из радиокнопок
{
    electronic, //0
    chemistry, //1
    phisics, //2
    biology, //3
    maths, //4
};

#endif // CLASSANDENUM_H
