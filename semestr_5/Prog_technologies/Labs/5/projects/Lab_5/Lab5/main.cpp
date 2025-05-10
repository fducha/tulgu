#include <QApplication>
#include <QLabel>
#include <QFont>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label;
    label.setText("Я простой Виджет!");
    label.setGeometry(200, 200, 300, 150);
    label.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    QFont blackFont("Arial", 12);
    label.setFont(blackFont);
    label.show();

    return app.exec();
}
