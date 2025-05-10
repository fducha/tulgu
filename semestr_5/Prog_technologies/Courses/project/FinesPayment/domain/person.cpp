#include "person.h"

Person::Person(const QString &familyName,
               const QString &name,
               const QString &surName,
               const QDate &birthDay,
               const QString &passport,
               const QString &license) :
    m_familyName(familyName), m_name(name),
    m_surName(surName), m_birthDay(birthDay),
    m_passport(passport), m_license(license)
{}

Person::Person() {}

const QString &Person::familyName() const {
    return m_familyName;
}

void Person::setFamilyName(const QString &familyName) {
    m_familyName = familyName;
}

const QString &Person::name() const {
    return m_name;
}

void Person::setName(const QString &name) {
    m_name = name;
}

const QString &Person::surName() const {
    return m_surName;
}

void Person::setSurName(const QString &surName) {
    m_surName = surName;
}

const QDate &Person::birthDay() const {
    return m_birthDay;
}

void Person::setBirthDay(const QDate &birthDay) {
    m_birthDay = birthDay;
}

const QString &Person::passport() const {
    return m_passport;
}

void Person::setPassport(const QString &passport) {
    m_passport = passport;
}

QString Person::toString() const {
    return QString("id %1, %2 %3 %4, %5 г.р., паспорт %6, водительское "
                   "удостоверение %7")
        .arg(id())
        .arg(familyName())
        .arg(name())
        .arg(surName())
        .arg(birthDay().toString("dd.MM.yyyy"))
        .arg(passport())
        .arg(license());
}

int Person::id() const {
    return m_id;
}

void Person::setId(int id) {
    m_id = id;
}

bool Person::operator==(const Person &right) const {
    return (this->familyName() == right.familyName()) &&
           (this->name() == right.name()) &&
           (this->surName() == right.surName()) &&
           (this->birthDay() == right.birthDay()) &&
           (this->passport() == right.passport()) &&
           (this->license() == right.license());
}

bool Person::isValid() const {
    return id() != -1 && !isEmpty();
}

bool Person::isEmpty() const {
    return familyName().isEmpty() || name().isEmpty() || surName().isEmpty() ||
           passport().isEmpty() || license().isEmpty();
}

QString Person::license() const {
    return m_license;
}

void Person::setLicense(const QString &license) {
    m_license = license;
}
