#ifndef FAKEPERSONGENERATOR_H
#define FAKEPERSONGENERATOR_H

#include "../domain/person.h"

class FakePersonGenerator
{
public:
    static FakePersonGenerator& get() {
        static FakePersonGenerator fpg;
        return fpg;
    }

    FakePersonGenerator(const FakePersonGenerator&) = delete;
    FakePersonGenerator& operator= (const FakePersonGenerator&) = delete;

    QList<Person> getPersons();

private:
    FakePersonGenerator();
    ~FakePersonGenerator() {}

    QStringList m_fullNames{};

    void readFile(QStringList &list, const QString filename);
};

#endif // FAKEPERSONGENERATOR_H
