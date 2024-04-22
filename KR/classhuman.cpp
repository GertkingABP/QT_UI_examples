#include "classhuman.h"

Human::Human()
{
    human = "Новый человек";
    date_birth = QDate::currentDate().addDays(1);
}
