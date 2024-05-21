#include "personrepository.h"

PersonRepository::PersonRepository(DBHelper *helper) :
    AbstractRepository(helper) {}

QList<Person> PersonRepository::persons() {
    return m_persons;
}

bool PersonRepository::add(Person &p) {
    if (!hasPerson(p)) {

        /// TODO Добавление Person в БД
        // Фейковая реализация

        int id = m_persons.size();
        p.setId(id);
        m_persons.append(p);
        return true;

        // ==================================
    }

    return false;
}

/// @return Возвращает True при успешном обновлении записи, иначе False
bool PersonRepository::update(const Person &person) {
    if (!person.isValid()) return false;
    int id = person.id();
    for (auto &p : m_persons) {
        if (p.id() == id) {

            /// TODO Изменение Person в БД
            // Фейковая реализация

            p.setFamilyName(person.familyName());
            p.setName(person.name());
            p.setSurName(person.surName());
            p.setBirthDay(person.birthDay());
            p.setPassport(person.passport());
            p.setLicense(person.license());
            return true;

            // ==================================
        }
    }

    return false;
}

bool PersonRepository::remove(int id) {
    for (auto &p : m_persons) {
        if (p.id() == id) {

            /// TODO Удаление Person из БД
            // Фейковая реализация

            return m_persons.removeOne(p);

            // ==================================
        }
    }
    return false;
}

Person PersonRepository::person(int id) const {
    for (const auto &p : m_persons) {
        if (p.id() == id) return p;
    }
    return Person();
}

bool PersonRepository::hasPerson(const Person &person) const {
    for (const auto &p : m_persons) {
        if (person == p) return true;
    }
    return false;
}
