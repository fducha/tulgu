#ifndef VEHICLE_H
#define VEHICLE_H

#include "owner.h"

class Vehicle
{
public:
    Vehicle();
    Vehicle(Owner *owner, const QString &vinCode, const QString &carMake,
            const QString &carModel, short category, short type,
            unsigned short year, const QString &color, const QString &pts,
            const QString &sts, const QDate registrationDate,
            const QString &registrationNumber);

    int id() const;
    void setId(int id);

    Owner *owner() const;
    void setOwner(Owner *owner);

    QString vinCode() const;
    void setVinCode(const QString &vinCode);

    QString carMake() const;
    void setCarMake(const QString &carMake);

    QString carModel() const;
    void setCarModel(const QString &carModel);

    short category() const;
    void setCategory(short category);

    short type() const;
    void setType(short type);

    unsigned short year() const;
    void setYear(unsigned short year);

    QString color() const;
    void setColor(const QString &color);

    QString pts() const;
    void setPts(const QString &pts);

    QString sts() const;
    void setSts(const QString &sts);

    QDate registrationDate() const;
    void setRegistrationDate(const QDate &date);

    QString registrationNumber() const;
    void setRegistrationNumber(const QString &number);

    bool isEmpty() const;
    bool isValid() const;

private:
    // id ТС в БД
    int m_id{-1};
    // указатель на собственника ТС
    Owner *m_owner{nullptr};
    // вин код ТС
    QString m_vinCode{};
    // марка ТС
    QString m_carMake{};
    // модель
    QString m_carModel{};
    // категория ТС
    short m_category{-1};
    // тип ТС
    short m_type{-1};
    // год выпуска
    unsigned short m_year{0};
    // цвет
    QString m_color{};
    // номер ПТС
    QString m_pts{};
    // номер Свидетельства ТС
    QString m_sts{};
    // дата регистрации ТС
    QDate m_registrationDate{};
    // гос. номер ТС
    QString m_registrationNumber{};
};

#endif // VEHICLE_H
