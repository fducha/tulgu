#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>

class Person
{
public:
    Person(const QString &familyName,
           const QString &name,
           const QString &surName,
           const QDate &birthDay,
           const QString &passport,
           const QString &license);

    Person();

    const QString &familyName() const;
    void setFamilyName(const QString &familyName);

    const QString &name() const;
    void setName(const QString &name);

    const QString &surName() const;
    void setSurName(const QString &surName);

    const QDate &birthDay() const;
    void setBirthDay(const QDate &birthDay);

    const QString &passport() const;
    void setPassport(const QString &passport);

    QString license() const;
    void setLicense(const QString &license);

    QString toString() const;

    int id() const;
    void setId(int id);

    bool operator== (const Person &right) const;
    bool operator!= (const Person &right) const {
        return !(*this == right);
    }

    /* Объект считается валидным, если идентификатор != -1 (значение по умолчанию),
     * и объект не пустой */
    bool isValid() const;
    /* Объект считается пустым, если хотя бы одно поле
     * кроме даты рождения пустое */
    bool isEmpty() const;

private:
    int m_id{-1};
    QString m_familyName{};
    QString m_name{};
    QString m_surName{};
    QDate m_birthDay{};
    QString m_passport{};
    QString m_license{};
};

#endif // PERSON_H
