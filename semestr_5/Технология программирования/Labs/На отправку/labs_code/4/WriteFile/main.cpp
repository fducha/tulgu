#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>
#include <math.h>

int main()
{
    QFile file("/study/ТулГу/semestr_5/Технология программирования/Labs/4/projects/data.txt");
    QTextStream in(&file);

    if (file.open(QIODevice::WriteOnly)) {
        for (int i = 1; i <= 10; i++) {
            QString result = QString("%1_%2\n").arg(i).arg(QString::number(sqrt(i), 'f', 4));
            in << qPrintable(result);
        }
        file.close();
    } else {
        qDebug() << "Error: Не могу открыть файл, прости";
    }

    return 0;
}
