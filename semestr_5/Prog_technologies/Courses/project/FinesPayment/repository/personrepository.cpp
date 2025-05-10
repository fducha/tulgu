#include "personrepository.h"
#include "../common/utils.h"

PersonRepository::PersonRepository(DBHelper *helper) :
    AbstractRepository(helper) {
    load();
}

PersonRepository::~PersonRepository() {
    qDeleteAll(m_persons);
}

QList<Person*> PersonRepository::persons() const {
    return m_persons;
}

bool PersonRepository::add(Person &p) {
    int id = db()->addPerson(toDataSet(p));
    if (id != -1) {
        p.setId(id);
        m_persons.append(new Person(p));
        return true;
    }

    return false;
}

/// @return Возвращает true при успешном обновлении записи, иначе false
bool PersonRepository::update(const Person &person) {
    if (!person.isValid()) return false;
    int id = person.id();
    for (auto p : qAsConst(m_persons)) {
        if (p->id() == id) {
            if (db()->updatePerson(toDataSet(person))) {
                p->setFamilyName(person.familyName());
                p->setName(person.name());
                p->setSurName(person.surName());
                p->setBirthDay(person.birthDay());
                p->setPassport(person.passport());
                p->setLicense(person.license());
                return true;
            }
        }
    }

    return false;
}

bool PersonRepository::remove(int id) {
    for (auto p : qAsConst(m_persons)) {
        if (p->id() == id) {

            /// TODO Удаление Person из БД
            // Фейковая реализация

            return m_persons.removeOne(p);

            // ==================================
        }
    }
    return false;
}

Person PersonRepository::person(int id) const {
    for (const auto p : m_persons) {
        if (p->id() == id) return Person(*p);
    }
    return Person();
}

void PersonRepository::load() {
    auto data = db()->getAllPersons();

    qDeleteAll(m_persons);
    m_persons.clear();

    for (const auto &pds : qAsConst(data)) {
        auto p = new Person(pds.familyName, pds.name, pds.surName,
                            Utils::dateFromDB(pds.birthDay), pds.passport,
                            pds.license);
        p->setId(pds.id);
        m_persons.append(p);
    }
}

PersonDataSet PersonRepository::toDataSet(const Person &p) const {
    PersonDataSet pds;
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
