#include "repos.h"
#include "ownerrepository.h"
#include "vehiclerepository.h"

Repos::Repos() {
    m_dbHelper = new DBHelper();
    m_personRep = new OwnerRepository(m_dbHelper);
    m_vehicleRep = new VehicleRepository(m_dbHelper);
}

Repos::~Repos() {
    delete m_personRep;
    delete m_vehicleRep;
    delete m_dbHelper;
}

OwnerRepository *Repos::owners() {
    return m_personRep;
}

VehicleRepository *Repos::vehicles() {
    return m_vehicleRep;
}
