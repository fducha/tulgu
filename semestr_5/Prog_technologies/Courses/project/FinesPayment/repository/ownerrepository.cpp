#include "ownerrepository.h"
#include "../common/utils.h"

OwnerRepository::OwnerRepository(DBHelper *helper) :
    AbstractRepository(helper) {
    load();
}

OwnerRepository::~OwnerRepository() {
    qDeleteAll(m_owners);
}

QList<Owner*> OwnerRepository::owners() const {
    return m_owners;
}

bool OwnerRepository::add(Owner &p) {
    int id = db()->addOwner(toDataSet(p));
    if (id != -1) {
        p.setId(id);
        m_owners.append(new Owner(p));
        return true;
    }

    return false;
}

/// @return Возвращает true при успешном обновлении записи, иначе false
bool OwnerRepository::update(const Owner &owner) {
    if (!owner.isValid()) return false;
    int id = owner.id();
    for (auto p : qAsConst(m_owners)) {
        if (p->id() == id) {
            if (db()->updateOwner(toDataSet(owner))) {
                p->setFamilyName(owner.familyName());
                p->setName(owner.name());
                p->setSurName(owner.surName());
                p->setBirthDay(owner.birthDay());
                p->setPassport(owner.passport());
                p->setLicense(owner.license());
                return true;
            }
        }
    }

    return false;
}

bool OwnerRepository::remove(int id) {
    for (auto p : qAsConst(m_owners)) {
        if (p->id() == id) {

            /// TODO Удаление Person из БД. Необходима реализация удаления связанных записей из остальных таблиц

            if (db()->deleteOwner(id)) {
                m_owners.removeOne(p);
                return true;
            }
        }
    }
    return false;
}

Owner OwnerRepository::owner(int id) const {
    for (const auto p : m_owners) {
        if (p->id() == id) return Owner(*p);
    }
    return Owner();
}

void OwnerRepository::load() {
    auto data = db()->getAllOwners();

    qDeleteAll(m_owners);
    m_owners.clear();

    for (const auto &pds : qAsConst(data)) {
        auto p = new Owner(pds.familyName, pds.name, pds.surName,
                            Utils::dateFromDB(pds.birthDay), pds.passport,
                            pds.license);
        p->setId(pds.id);
        m_owners.append(p);
    }
}

OwnerDataSet OwnerRepository::toDataSet(const Owner &p) const {
    OwnerDataSet pds;
    pds.id = p.id();
    pds.familyName = p.familyName();
    pds.name = p.name();
    pds.surName = p.surName();
    pds.birthDay = Utils::dateToDB(p.birthDay());
    pds.passport = p.passport();
    pds.license = p.license();

    return pds;
}

// bool PersonRepository::hasPerson(const Person &person) const {
//     for (const auto p : qAsConst(m_persons)) {
//         if (person == *p) return true;
//     }
//     return false;
// }
