#include "abstractrepository.h"

AbstractRepository::AbstractRepository(DBHelper *dbHelper) :
    m_dbHelper(dbHelper) {}

DBHelper *AbstractRepository::db() {
    return m_dbHelper;
}
