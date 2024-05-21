#ifndef REPOS_H
#define REPOS_H

#include "personrepository.h"
#include "../dbhelper/dbhelper.h"

class Repos
{
public:
    static Repos& get() {
        static Repos rep;
        return rep;
    }

    PersonRepository *persons();

    Repos(const Repos&) = delete;
    Repos& operator= (const Repos&) = delete;

private:
    Repos();
    ~Repos();

    PersonRepository *m_personRep;
    DBHelper *m_dbHelper;
};

#endif // REPOS_H
