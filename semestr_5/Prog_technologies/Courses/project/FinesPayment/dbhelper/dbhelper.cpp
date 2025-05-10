#include "dbhelper.h"
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>


DBHelper::DBHelper() {
    // qDebug() << QSqlDatabase::drivers();
    m_db = QSqlDatabase::addDatabase("SQLITECIPHER");
    m_db.setDatabaseName("data.sqlite");

    if (!m_db.open()) {
        qDebug() << "Can't open database" << m_db.lastError().driverText();
    }

    createOwnersTable();
}

DBHelper::~DBHelper() {
    m_db.close();
}

QList<OwnerDataSet> DBHelper::getAllOwners() const {
    QList<OwnerDataSet> result;

    QSqlQuery q(m_db);
    QString sql{"SELECT * FROM owners;"};

    if (q.exec(sql)) {
        while (q.next()) {
            OwnerDataSet person;
            // получаем id -> int
            person.id = q.value(0).toInt();
            // получаем фамилию -> QString
            person.familyName = q.value(1).toString();
            // получаем имя -> QString
            person.name = q.value(2).toString();
            // получаем отчество -> QString
            person.surName = q.value(3).toString();
            // получаем дату рождения -> int
            person.birthDay = q.value(4).toInt();
            // получаем паспорт -> QString
            person.passport = q.value(5).toString();
            // получаем вод. удостоверение -> QString
            person.license = q.value(6).toString();
            result << person;
        }
    }
    return result;
}

int DBHelper::addOwner(const OwnerDataSet &pds) {
    int result = -1;

    QSqlQuery q(m_db);
    q.prepare(
        "INSERT INTO owners (familyName, name, surName, birthDay, passport, "
        "license) "
        "VALUES (:familyName, :name, :surName, :birthDay, :passport, :license);");
    q.bindValue(":familyName", pds.familyName);
    q.bindValue(":name", pds.name);
    q.bindValue(":surName", pds.surName);
    q.bindValue(":birthDay", pds.birthDay);
    q.bindValue(":passport", pds.passport);
    q.bindValue(":license", pds.license);

    if (q.exec()) return q.lastInsertId().toInt();

    return result;
}

bool DBHelper::updateOwner(const OwnerDataSet &pds) {
    QSqlQuery q(m_db);

    q.prepare("UPDATE owners SET "
              "familyName=:familyName, "
              "name=:name, "
              "surName=:surName, "
              "birthDay=:birthDay, "
              "passport=:passport, "
              "license=:license "
              "WHERE id=:id;");
    q.bindValue(":familyName", pds.familyName);
    q.bindValue(":name", pds.name);
    q.bindValue(":surName", pds.surName);
    q.bindValue(":birthDay", pds.birthDay);
    q.bindValue(":passport", pds.passport);
    q.bindValue(":license", pds.license);
    q.bindValue(":id", pds.id);

    return q.exec();
}

bool DBHelper::deleteOwner(int id) {
    QSqlQuery q(m_db);

    q.prepare("DELETE FROM owners WHERE id=:id;");
    q.bindValue(":id", id);

    return q.exec();
}

bool DBHelper::createOwnersTable() {
    if (!m_db.isOpen()) return false;

    QString sql = "CREATE TABLE IF NOT EXISTS owners ("
                    "id         INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "familyName	TEXT NOT NULL, "
                    "name       TEXT NOT NULL, "
                    "surName	TEXT NOT NULL, "
                    "birthDay	INTEGER DEFAULT (0), "
                    "passport	TEXT UNIQUE NOT NULL, "
                    "license	TEXT UNIQUE NOT NULL);";

    QSqlQuery q(m_db);
    return q.exec(sql);
}
