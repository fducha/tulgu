#include "mainwindow.h"

#include <QApplication>
#include <QDebug>

#include "repository/repos.h"


// #include "fakes/fakepersongenerator.h"

int main(int argc, char *argv[])
{
    // Person p1("Иванов", "Иван", "Иванович", QDate(1980, 1, 10), "12 05 256854", "85 ПР 916649");
    // Person p2("Петров", "Дмитрий", "Сергеевич", QDate(1984, 4, 15), "05 67 589452", "64 66 692353");
    // Person p3("Сидорова", "Наталья", "Николаевна", QDate(1979, 10, 19), "24 26 984562", "98 ЫЛ 346464");
    // Person p4("Калашников", "Семен", "Игоревич", QDate(1993, 12, 7), "11 35 167521", "13 55 967491");
    // Person p5("Бабаева", "Татьяна", "Александровна", QDate(2001, 7, 1), "24 52 345677", "96 ЛА 346656");

    // Repos::get().persons()->add(p1);
    // Repos::get().persons()->add(p2);
    // Repos::get().persons()->add(p3);
    // Repos::get().persons()->add(p4);
    // Repos::get().persons()->add(p5);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
