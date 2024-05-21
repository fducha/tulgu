#include "repos.h"

Repos::Repos() {
    m_dbHelper = new DBHelper();
    m_personRep = new PersonRepository(m_dbHelper);
}

Repos::~Repos() {
    delete m_personRep;
    delete m_dbHelper;
}

PersonRepository *Repos::persons() {
    return m_personRep;
}
