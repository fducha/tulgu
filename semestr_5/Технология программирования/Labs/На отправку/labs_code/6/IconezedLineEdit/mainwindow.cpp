#include "mainwindow.h"
#include "iconizedlineedit.h"
#include <QVBoxLayout>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QWidget{parent}
{
    createUi();
}

MainWindow::~MainWindow()
{
}

void MainWindow::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    ilEdit1->setText(fileName);
}

void MainWindow::createUi() {
    auto lytMain = new QVBoxLayout;
    setLayout(lytMain);

    ilEdit1 = new IconizedLineEdit();
    ilEdit1->setPlaceholderText("Нажмите, чтобы открыть файл");
    ilEdit1->setIconVisiblity(IconizedLineEdit::IconAlwaysVisible);
    ilEdit1->setIconPixmap(QPixmap("folder.png"));
    ilEdit1->setIconClickable(true);
    connect(ilEdit1, &IconizedLineEdit::iconPressed,
            this, &MainWindow::selectFile);
    lytMain->addWidget(ilEdit1);


    ilEdit2 = new IconizedLineEdit();
    ilEdit2->setPlaceholderText("Введите IP-адрес");
    ilEdit2->setIconPixmap(QPixmap("checkmark.png"));
    ilEdit2->setIconVisiblity(IconizedLineEdit::IconAlwaysVisible);
    lytMain->addWidget(ilEdit2);

    ilEdit3 = new IconizedLineEdit();
    ilEdit3->setPlaceholderText(" ");
    ilEdit3->setIconPixmap(QPixmap("question.png"));
    ilEdit3->setIconVisiblity(IconizedLineEdit::IconVisibleOnTextPresence);
    lytMain->addWidget(ilEdit3);

    ilEdit4 = new IconizedLineEdit();
    ilEdit4->setPlaceholderText("Не могу открыть ...");
    ilEdit4->setIconPixmap(QPixmap("warning.png"));
    ilEdit4->setIconVisiblity(IconizedLineEdit::IconVisibleOnEmptyText);
    lytMain->addWidget(ilEdit4);

    ilEdit5 = new IconizedLineEdit();
    ilEdit5->setPlaceholderText("Очищаемый");
    ilEdit5->setIconPixmap(QPixmap("XXX.png"));
    ilEdit5->setIconVisiblity(IconizedLineEdit::IconVisibleOnTextPresence);
    ilEdit5->setIconClickable(true);
    connect(ilEdit5, &IconizedLineEdit::iconPressed, ilEdit5,
            &IconizedLineEdit::clear);
    lytMain->addWidget(ilEdit5);
}

