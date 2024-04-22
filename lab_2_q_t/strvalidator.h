#ifndef STRVALIDATOR_H
#define STRVALIDATOR_H

#include <QValidator>

class strvalidator : public QValidator
{
     Q_OBJECT
public:
    strvalidator(QObject *parent);
    ~strvalidator();

    QValidator::State validate(QString & string, int & pos) const;
};

#endif // STRVALIDATOR_H
