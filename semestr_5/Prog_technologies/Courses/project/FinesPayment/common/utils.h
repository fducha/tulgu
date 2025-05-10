#ifndef UTILS_H
#define UTILS_H

#include <QDate>

class Utils
{
public:
    Utils();

    /// Конвертирует дату в целое (количество дней с 01.01.1900 года)
    /// @param [data] исходная дата
    /// @return количество дней
    static int dateToDB(const QDate &date);
    /// Конвертирует целое в дату (количество дней с 01.01.1900 года)
    /// @param количество дней
    /// @return дата через [date] дней
    static QDate dateFromDB(int date);

    static const QDate s_startDate;
};

#endif // UTILS_H
