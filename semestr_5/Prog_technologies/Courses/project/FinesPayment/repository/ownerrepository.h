#ifndef OWNERREPOSITORY_H
#define OWNERREPOSITORY_H

#include "../domain/owner.h"
#include "abstractrepository.h"

class OwnerRepository : AbstractRepository
{
public:
    OwnerRepository(DBHelper *helper);
    ~OwnerRepository();

    QList<Owner*> owners() const;

    // передаем ссылку, т.к. объекту будет установлен id
    // при добавлении в БД
    bool add(Owner& p);
    bool update(const Owner &owner);
    bool remove(int id);

    Owner owner(int id) const;

private:
    QList<Owner*> m_owners{};

    /// Загружает собственников из БД
    void load();
    // bool hasPerson(const Owner &person) const;

    OwnerDataSet toDataSet(const Owner &p) const;
};

#endif // OWNERREPOSITORY_H
