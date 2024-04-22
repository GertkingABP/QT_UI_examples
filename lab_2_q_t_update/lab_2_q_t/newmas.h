#ifndef NEWMAS_H
#define NEWMAS_H

#include <QString>
#include <QDate>

class newMas
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

    void getDate(QDate date_in)
    {
        date = date_in;
    }

    QDate giveDate()
    {
        return date;
    }
};

#endif // NEWMAS_H

