#ifndef VEHICLEREPOSITORY_H
#define VEHICLEREPOSITORY_H

#include "abstractrepository.h"
#include "../domain/vehicle.h"

class VehicleRepository : public AbstractRepository
{
public:
    VehicleRepository(DBHelper *helper);

    QList<Vehicle*> vehicles() const;
    QList<Vehicle*> vehiclesByPersonId(int id) const;

    bool add(Vehicle &v);
    bool update(const Vehicle &vehicle);
    bool remove(int id);

    Vehicle vehicle(int id) const;

private:
    QList<Vehicle*> m_vehicles{};
};

#endif // VEHICLEREPOSITORY_H
