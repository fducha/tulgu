#ifndef DBHELPER_H
#define DBHELPER_H

#include <QtSql/QSqlDatabase>
#include <QVariant>

struct OwnerDataSet {
    int id{-1};
    QString familyName{};
    QString name{};
    QString surName{};
    int     birthDay{};
    QString passport{};
    QString license{};
};

class DBHelper
{
public:
    DBHelper();
    ~DBHelper();

    QList<OwnerDataSet> getAllOwners() const;

    /// добаляет собственника в БД
    /// @return при успешном добавлении возвращает id записи, иначе -1
    int addOwner(const OwnerDataSet &pds);
    /// обновляет данные собственника в БД
    /// @return true при успешном обновлении
    bool updateOwner(const OwnerDataSet &pds);
    /// удаляет собственника из БД
    /// @return true при успешном удалении
    bool deleteOwner(int id);

private:
    QSqlDatabase m_db;

    bool createOwnersTable();
};

#endif // DBHELPER_H
