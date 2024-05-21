#include "signalswidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SignalsWidget w;
    w.show();
    return a.exec();
}
