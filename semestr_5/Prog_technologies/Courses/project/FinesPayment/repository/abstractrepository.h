#ifndef ABSTRACTREPOSITORY_H
#define ABSTRACTREPOSITORY_H

#include "../dbhelper/dbhelper.h"

class AbstractRepository
{
public:
    AbstractRepository(DBHelper *dbHelper);

protected:
    DBHelper* db();

private:
    DBHelper *m_dbHelper;
};

#endif // ABSTRACTREPOSITORY_H
