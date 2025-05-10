#include "fakepersongenerator.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

FakePersonGenerator::FakePersonGenerator() {
    readFile(m_fullNames, "fakes/full_names");
}

QList<Owner> FakePersonGenerator::getPersons() {
    QList<Owner> result;

    // QDate start(1950, 1, 1);
    // auto count_days = start.daysTo(QDate(2008, 1, 1));
    // int id = 0;

    // for (auto name : m_fullNames) {
    //     QStringList l = name.split(" ");
    //     auto birthday = start.addDays(rand() % count_days);
    //     auto pas = QString("%1 %2 %3")
    //             .arg(rand() % 90 + 10)
    //             .arg(rand() % 90 + 10)
    //             .arg(rand() % 900000 + 100000);
    //     result << Person(l[0], l[1], l[2], birthday, pas);
    // }

    return result;
}

void FakePersonGenerator::readFile(QStringList &list, const QString filename) {
    QFile file(filename);
    QTextStream in(&file);
    if (file.open(QIODevice::ReadOnly)) {
        while (!file.atEnd()) {
            auto str = QString(file.readLine()).simplified();
            list << str;
        }
        file.close();
        qDebug() << "File" << filename << "was read";
    } else {
        qCritical() << "Can't open file:" << filename;
    }
}
