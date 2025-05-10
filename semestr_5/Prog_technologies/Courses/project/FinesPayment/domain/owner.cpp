#include "owner.h"

Owner::Owner(const QString &familyName, const QString &name,
             const QString &surName, const QDate &birthDay,
             const QString &passport, const QString &license)
    : m_familyName(familyName), m_name(name), m_surName(surName),
    m_birthDay(birthDay), m_passport(passport), m_license(license) {}

Owner::Owner() {}

const QString &Owner::familyName() const {
    return m_familyName;
}

void Owner::setFamilyName(const QString &familyName) {
    m_familyName = familyName;
}

const QString &Owner::name() const {
    return m_name;
}

void Owner::setName(const QString &name) {
    m_name = name;
}

const QString &Owner::surName() const {
    return m_surName;
}

void Owner::setSurName(const QString &surName) {
    m_surName = surName;
}

const QDate &Owner::birthDay() const {
    return m_birthDay;
}

void Owner::setBirthDay(const QDate &birthDay) {
    m_birthDay = birthDay;
}

const QString &Owner::passport() const {
    return m_passport;
}

void Owner::setPassport(const QString &passport) {
    m_passport = passport;
}

QString Owner::toString() const {
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

int Owner::id() const {
    return m_id;
}

void Owner::setId(int id) {
    m_id = id;
}

bool Owner::operator==(const Owner &right) const {
    return (this->familyName() == right.familyName()) &&
           (this->name() == right.name()) &&
           (this->surName() == right.surName()) &&
           (this->birthDay() == right.birthDay()) &&
           (this->passport() == right.passport()) &&
           (this->license() == right.license());
}

bool Owner::isValid() const { return id() != -1 && !isEmpty(); }

bool Owner::isEmpty() const {
    return familyName().isEmpty() || name().isEmpty() || surName().isEmpty() ||
           passport().isEmpty() || license().isEmpty();
}

QString Owner::license() const {
    return m_license;
}

void Owner::setLicense(const QString &license) {
    m_license = license;
}
