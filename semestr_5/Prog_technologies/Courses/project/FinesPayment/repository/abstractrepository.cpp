#include "abstractrepository.h"
#include <QDate>

AbstractRepository::AbstractRepository(DBHelper *dbHelper) :
    m_dbHelper(dbHelper) {}

DBHelper *AbstractRepository::db() {
    return m_dbHelper;
}
