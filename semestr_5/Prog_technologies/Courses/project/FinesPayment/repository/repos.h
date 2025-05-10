#ifndef REPOS_H
#define REPOS_H

#include "../dbhelper/dbhelper.h"

class OwnerRepository;
class VehicleRepository;

class Repos
{
public:
    static Repos& get() {
        static Repos rep;
        return rep;
    }

    OwnerRepository *owners();
    VehicleRepository *vehicles();

    Repos(const Repos&) = delete;
    Repos& operator= (const Repos&) = delete;

private:
    Repos();
    ~Repos();

    OwnerRepository *m_personRep;
    VehicleRepository *m_vehicleRep;
    DBHelper *m_dbHelper;
};

#endif // REPOS_H
