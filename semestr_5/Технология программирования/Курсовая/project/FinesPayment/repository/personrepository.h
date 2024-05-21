#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include "../domain/person.h"
#include "abstractrepository.h"

class PersonRepository : AbstractRepository
{
public:
    PersonRepository(DBHelper *helper);
    ~PersonRepository();

    QList<Person*> persons() const;

    // передаем ссылку, т.к. объекту будет установлен id
    // при добавлении в БД
    bool add(Person& p);
    bool update(const Person &person);
    bool remove(int id);

    Person person(int id) const;

private:
    QList<Person*> m_persons{};

    bool hasPerson(const Person &person) const;
};

#endif // PERSONREPOSITORY_H
