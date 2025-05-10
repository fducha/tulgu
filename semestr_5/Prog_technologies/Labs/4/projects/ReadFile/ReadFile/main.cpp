#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <QDebug>

int main()
{
    QFile file("/study/ТулГу/semestr_5/Технология программирования/Labs/4/projects/data.txt");
    QTextStream in(&file);

    if (file.open(QIODevice::ReadOnly)) {
        while (!in.atEnd()) {
            QString raw = in.readLine();
            QStringList results = raw.split("_");
            int number = results[0].toInt();
            float data = results[1].toFloat();
            qDebug() << number << ": " << data;
        }
        file.close();
    } else {
        qCritical() << "Не могу открыть файл, прости";
        return 1;
    }

    return 0;
}
