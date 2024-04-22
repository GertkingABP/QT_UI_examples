#include "strvalidator.h"
#include "ClassAndEnum.h"

using namespace std;

strvalidator::strvalidator(QObject* parent)
    : QValidator (parent)
{

}

strvalidator::~strvalidator()
{

}

QValidator::State strvalidator::validate(QString &string, int &pos) const
{
    int len = string.size();//длина строки
    //bool check = true; //признак правильной строки(если строка верна, то true останется)

    //Если длина равна 0
    if(len == 0) return QValidator::Invalid;

    //Блокировка цифр
    if(string.contains(QChar('0')) || string.contains(QChar('1')) || string.contains(QChar('2')) || string.contains(QChar('3')) || string.contains(QChar('4')) || string.contains(QChar('5')) || string.contains(QChar('6')) || string.contains(QChar('7')) || string.contains(QChar('8')) || string.contains(QChar('9'))) {return QValidator::Invalid;}

    //Блокировка знаков-разделителей(кроме пробела и ,)
    if(string.contains(QChar('/')) || string.contains(QChar('\\')) || string.contains(QChar('.')) || string.contains(QChar(';')) || string.contains(QChar(':')) || string.contains(QChar('\'')) || string.contains(QChar('"')) || string.contains(QChar('>')) || string.contains(QChar('<')) || string.contains(QChar('!')) || string.contains(QChar('@')) || string.contains(QChar('#')) || string.contains(QChar('$')) || string.contains(QChar('%')) || string.contains(QChar('&')) || string.contains(QChar('^')) || string.contains(QChar('?')) || string.contains(QChar('*')) || string.contains(QChar('(')) || string.contains(QChar(')')) || string.contains(QChar('-')) || string.contains(QChar('_')) || string.contains(QChar('+')) || string.contains(QChar('=')) || string.contains(QChar('{')) || string.contains(QChar('}')) || string.contains(QChar('[')) || string.contains(QChar(']')) || string.contains(QChar('~')) || string.contains(QChar('`')) || string.contains(QChar('|'))) {return QValidator::Invalid;}

    //Блокировка некоторых сочетаний клавиш
    if(string.contains(QString(" ,")) || string.contains(QString("  ")) || string.contains(QString(",,"))) {return QValidator::Invalid;}

    //После большой буквы сразу большая или запятая или пробел
    for(int i = 0; i < len - 1; i++)
    {
        if(string[i].isUpper() && ((string[i + 1].isUpper()) || (string[i + 1].isPunct()) || (string[i + 1].isSpace()))) {return QValidator::Invalid;}
    }

    //Между 2 малыми буквами 1 большая
    for(int i = 1; i < len - 1; i++)
    {
        if((string[i].isUpper()) && (string[i - 1].isLower()) && (string[i + 1].isLower())) {return QValidator::Invalid;}
    }

    //После малой буквы сразу большая
    for(int i = 0; i < len - 1; i++)
    {
        if((string[i].isLower()) && (string[i + 1].isUpper())) {return QValidator::Invalid;}
    }

    //Кол-во больших букв в фио не делится на 3 нацело или больших букв больше чем малых
    int big_c = 0;
    int small_c = 0;

    for(int i = 0; i < len; i++)
    {
        if(string[i].isUpper())
        {
            big_c++;
        }

        else if(string[i].isLower())
        {
            small_c++;
        }
    }

    if(big_c % 3 != 0 || small_c < big_c) {return QValidator::Intermediate;}

    //Первая буква не большая или последняя не малая
    if((!string[0].isUpper()) || !(string[len - 1].isLower())) {return QValidator::Intermediate;}

    //Кол-во слов не делится на 3 нацело или запятые стоят не на месте
    int words = 0;
    int count_z = 0;

    if (string[0] != ' ')//самое первое слово
       words++;

    for(int i = 1; i < len - 1; i++)//последующие слова
    {
     if((string[i] == ' ') && (string[i + 1] != ' '))
        words++;
     if(string[i - 1] == ',')
        count_z++;

     //Если запятая не после 3, 6, 9 и т.д слов
     if ((words >= 1) && ((words % 3 == 1) || (words % 3 == 0)) && (((words - count_z) % 2) != 1) ) {return QValidator::Intermediate;}
    }

     if(words % 3 != 0) {return QValidator::Intermediate;}

     //Положение запятой(блокирование , между буквами)
     for(int i = 0; i < len; i++)
     {
         if((string[i] == ',') && (!string[i + 1].isSpace())) {return QValidator::Invalid;}
     }

     if(len < 8) return QValidator::Intermediate;

     //Если всё правильно
     return QValidator::Acceptable;
}
