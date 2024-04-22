#include "examplevalidator.h"

ExampleValidator::ExampleValidator(QObject* parent)
    : QValidator (parent)
{

}

ExampleValidator::~ExampleValidator()
{

}

QValidator::State ExampleValidator::validate(QString &string, int &pos) const
{
    //Блокировка цифр
    if(string.contains(QChar('0')) || string.contains(QChar('1')) || string.contains(QChar('2')) || string.contains(QChar('3')) || string.contains(QChar('4')) || string.contains(QChar('5')) || string.contains(QChar('6')) || string.contains(QChar('7')) || string.contains(QChar('8')) || string.contains(QChar('9'))) return QValidator::Invalid;

    //Блокировка знаков-разделителей
    if(string.contains(QChar('/')) || string.contains(QChar('\\')) || string.contains(QChar('.')) || string.contains(QChar(',')) || string.contains(QChar(';')) || string.contains(QChar(':')) || string.contains(QChar('\'')) || string.contains(QChar('"')) || string.contains(QChar('>')) || string.contains(QChar('<')) || string.contains(QChar('!')) || string.contains(QChar('@')) || string.contains(QChar('#')) || string.contains(QChar('$')) || string.contains(QChar('%')) || string.contains(QChar('&')) || string.contains(QChar('^')) || string.contains(QChar('?')) || string.contains(QChar('*')) || string.contains(QChar('(')) || string.contains(QChar(')')) || string.contains(QChar('-')) || string.contains(QChar('_')) || string.contains(QChar('+')) || string.contains(QChar('=')) || string.contains(QChar('{')) || string.contains(QChar('}')) || string.contains(QChar('[')) || string.contains(QChar(']')) || string.contains(QChar('~')) || string.contains(QChar('`')) || string.contains(QChar('|'))) return QValidator::Invalid;

    //Блокировка английского алфавита
    if(string.contains(QChar('a')) || string.contains(QChar('A')) || string.contains(QChar('b')) || string.contains(QChar('B')) || string.contains(QChar('c')) || string.contains(QChar('C')) || string.contains(QChar('d')) || string.contains(QChar('D')) || string.contains(QChar('e')) || string.contains(QChar('E')) || string.contains(QChar('f')) || string.contains(QChar('F')) || string.contains(QChar('g')) || string.contains(QChar('G')) || string.contains(QChar('h')) || string.contains(QChar('H')) || string.contains(QChar('i')) || string.contains(QChar('I')) || string.contains(QChar('j')) || string.contains(QChar('J')) || string.contains(QChar('k')) || string.contains(QChar('K')) || string.contains(QChar('l')) || string.contains(QChar('L')) || string.contains(QChar('m')) || string.contains(QChar('M')) || string.contains(QChar('n')) || string.contains(QChar('N')) || string.contains(QChar('o')) || string.contains(QChar('O')) || string.contains(QChar('p')) || string.contains(QChar('P')) || string.contains(QChar('q')) || string.contains(QChar('Q')) || string.contains(QChar('r')) || string.contains(QChar('R')) || string.contains(QChar('s')) || string.contains(QChar('S')) || string.contains(QChar('t')) || string.contains(QChar('T')) || string.contains(QChar('u')) || string.contains(QChar('U')) || string.contains(QChar('v')) || string.contains(QChar('V')) || string.contains(QChar('w')) || string.contains(QChar('W')) || string.contains(QChar('x')) || string.contains(QChar('X')) || string.contains(QChar('y')) || string.contains(QChar('Y')) || string.contains(QChar('z')) || string.contains(QChar('Z'))) return QValidator::Invalid;

    //Блокировка некоторых русских букв
    if(string.contains(QChar(L'а')) || string.contains(QChar(L'А')) || string.contains(QChar(L'б')) || string.contains(QChar(L'Б')) || string.contains(QChar(L'в')) || string.contains(QChar(L'В')) || string.contains(QChar(L'г')) || string.contains(QChar(L'Г')) || string.contains(QChar(L'д')) || string.contains(QChar(L'Д')) || string.contains(QChar(L'ё')) || string.contains(QChar(L'Ё')) || string.contains(QChar(L'з')) || string.contains(QChar(L'З')) || string.contains(QChar(L'л')) || string.contains(QChar(L'Л')) || string.contains(QChar(L'п')) || string.contains(QChar(L'П')) || string.contains(QChar(L'р')) || string.contains(QChar(L'Р')) || string.contains(QChar(L'т')) || string.contains(QChar(L'Т')) || string.contains(QChar(L'ф')) || string.contains(QChar(L'Ф')) || string.contains(QChar(L'х')) || string.contains(QChar(L'Х')) || string.contains(QChar(L'ц')) || string.contains(QChar(L'Ц')) || string.contains(QChar(L'ч')) || string.contains(QChar(L'Ч')) || string.contains(QChar(L'ш')) || string.contains(QChar(L'Ш')) || string.contains(QChar(L'щ')) || string.contains(QChar(L'Щ')) || string.contains(QChar(L'ъ')) || string.contains(QChar(L'Ъ')) || string.contains(QChar(L'ы'))|| string.contains(QChar(L'Ы')) || string.contains(QChar(L'ь')) || string.contains(QChar(L'Ь')) || string.contains(QChar(L'э')) || string.contains(QChar(L'Э')) || string.contains(QChar(L'ю')) || string.contains(QChar(L'Ю')) || string.contains(QChar(L'я')) || string.contains(QChar(L'Я'))) return QValidator::Invalid;

    //Блокировка заглавных букв, из которых можно получить "мужской" или "женский"
    if(string.contains(QChar(L'М')) || string.contains(QChar(L'У')) || string.contains(QChar(L'Ж')) || string.contains(QChar(L'С')) || string.contains(QChar(L'К')) || string.contains(QChar(L'О')) || string.contains(QChar(L'Й')) || string.contains(QChar(L'Е')) || string.contains(QChar(L'Н')) || string.contains(QChar(L'И'))) return QValidator::Invalid;

    //Правильные написания пола(м ИЛИ ж ИЛИ муж ИЛИ жен ИЛИ мужской ИЛИ женский)
    if((string == "муж") || (string == "жен") || (string == "м") || (string == "ж") || (string == "мужской") || (string == "женский")) return QValidator::Acceptable;

    if((string != "муж") || (string != "жен") || (string != "м") || (string != "ж") || (string != "мужской") || (string != "женский")) return QValidator::Intermediate;
}
