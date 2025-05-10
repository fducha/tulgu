#include "utils.h"

Utils::Utils() {}

const QDate Utils::s_startDate = QDate(1900, 1, 1);

int Utils::dateToDB(const QDate &date) {
    return s_startDate.daysTo(date);
}

QDate Utils::dateFromDB(int date) {
    return s_startDate.addDays(date);
}
