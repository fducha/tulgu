#include "vehicle.h"

Vehicle::Vehicle(Owner *owner, const QString &vinCode, const QString &carMake,
                 const QString &carModel, short category, short type,
                 unsigned short year, const QString &color, const QString &pts,
                 const QString &sts, const QDate registrationDate,
                 const QString &registrationNumber)
    : m_owner(owner), m_vinCode(vinCode), m_carMake(carMake),
    m_carModel(carModel), m_category(category), m_type(type), m_year(year),
    m_color(color), m_pts(pts), m_sts(sts),
    m_registrationDate(registrationDate),
    m_registrationNumber(registrationNumber) {}

int Vehicle::id() const {
    return m_id;
}

void Vehicle::setId(int id) {
    m_id = id;
}

Owner *Vehicle::owner() const {
    return m_owner;
}

void Vehicle::setOwner(Owner *owner) {
    m_owner = owner;
}

QString Vehicle::vinCode() const {
    return m_vinCode;
}

void Vehicle::setVinCode(const QString &vinCode) {
    m_vinCode = vinCode;
}

QString Vehicle::carMake() const {
    return m_carMake;
}

void Vehicle::setCarMake(const QString &carMake) {
    m_carMake = carMake;
}

QString Vehicle::carModel() const {
    return m_carModel;
}

void Vehicle::setCarModel(const QString &carModel) {
    m_carModel = carModel;
}

short Vehicle::category() const {
    return m_category;
}

void Vehicle::setCategory(short category) {
    m_category = category;
}

short Vehicle::type() const {
    return m_type;
}

void Vehicle::setType(short type) {
    m_type = type;
}

unsigned short Vehicle::year() const {
    return m_year;
}

void Vehicle::setYear(unsigned short year) {
    m_year = year;
}

QString Vehicle::color() const {
    return m_color;
}

void Vehicle::setColor(const QString &color) {
    m_color = color;
}

QString Vehicle::pts() const {
    return m_pts;
}

void Vehicle::setPts(const QString &pts) {
    m_pts = pts;
}

QString Vehicle::sts() const {
    return m_sts;
}

void Vehicle::setSts(const QString &sts) {
    m_sts = sts;
}

QDate Vehicle::registrationDate() const {
    return m_registrationDate;
}

void Vehicle::setRegistrationDate(const QDate &date) {
    m_registrationDate = date;
}

QString Vehicle::registrationNumber() const {
    return m_registrationNumber;
}

void Vehicle::setRegistrationNumber(const QString &number) {
    m_registrationNumber = number;
}

bool Vehicle::isEmpty() const {
    return owner() || vinCode().isEmpty() || carMake().isEmpty() ||
           carModel().isEmpty() || category() == -1 || type() == -1 ||
           year() == 0 || color().isEmpty() || pts().isEmpty() ||
           sts().isEmpty() || !registrationDate().isValid() ||
           registrationNumber().isEmpty();
}

bool Vehicle::isValid() const {
    return id() != -1 && !isEmpty();
}
