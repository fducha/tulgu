#include "vehiclerepository.h"

VehicleRepository::VehicleRepository(DBHelper *helper)
    : AbstractRepository(helper) {}

QList<Vehicle *> VehicleRepository::vehicles() const {
    return m_vehicles;
}

QList<Vehicle *> VehicleRepository::vehiclesByPersonId(int id) const {
    QList<Vehicle *> result{};

    for (auto v : qAsConst(m_vehicles)) {
        if (v->owner()->id() == id) {
            result << v;
        }
    }

    return result;
}

bool VehicleRepository::add(Vehicle &v) {
    /// TODO Fix fake

    if (v.isEmpty()) return false;

    v.setId(m_vehicles.count());
    m_vehicles.append(new Vehicle(v));
    return true;
}

bool VehicleRepository::update(const Vehicle &vehicle) {
    if (!vehicle.isValid()) return false;
    for (auto v : qAsConst(m_vehicles)) {
        if (v->id() == vehicle.id()) {
            v->setOwner(vehicle.owner());
            v->setVinCode(vehicle.vinCode());
            v->setCarMake(vehicle.carMake());
            v->setCarModel(vehicle.carModel());
            v->setCategory(vehicle.category());
            v->setType(vehicle.type());
            v->setYear(vehicle.year());
            v->setColor(vehicle.color());
            v->setPts(vehicle.pts());
            v->setSts(vehicle.sts());
            v->setRegistrationDate(vehicle.registrationDate());
            v->setRegistrationNumber(vehicle.registrationNumber());
            return true;
        }
    }
    return false;
}

bool VehicleRepository::remove(int id) {
    for (auto v : qAsConst(m_vehicles)) {
        if (v->id() == id) {
            m_vehicles.removeOne(v);
            return true;
        }
    }
    return false;
}
