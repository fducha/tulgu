#include <QString>
#include <QDebug>

struct Person
{
    Person(const QString &name,
           const QString &phoneNumber,
           const QString &address) {
        this->name = name;
        this->phoneNumber = phoneNumber;
        this->address = address;
    }

    QString name;
    QString phoneNumber;
    QString address;
};

QDebug operator << (QDebug debug, const Person &person) {
    debug.nospace().noquote() << "Имя: " << person.name << " (телефон: "
                              << person.phoneNumber << ", адрес: " << person.address << ")";
    return debug;
}

int main()
{
    Person p("Иван Попов", "+79562354152", "Москва, ул. Тверская, д.3, кв.17");
    qDebug() << p;
    p.address = "Москва, ул. Тверская, д.3, кв. 27";
    qDebug() << p;
    return 0;
}
