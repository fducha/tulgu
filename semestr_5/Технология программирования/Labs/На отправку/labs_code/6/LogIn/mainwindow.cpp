#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include "iconizedlineedit.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createUi();

    connect(m_btnClose, &QPushButton::clicked,
            this, &MainWindow::close);
    connect(m_btnLogin, &QPushButton::clicked,
            this, &MainWindow::logined);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createUi() {
    auto lytMain = new QVBoxLayout;
    setLayout(lytMain);

    m_ileLogin = new IconizedLineEdit;
    m_ileLogin->setPlaceholderText("Введите логин");
    m_ileLogin->setIconVisiblity(IconizedLineEdit::IconVisibleOnEmptyText);
    m_ileLogin->setIconPixmap(QPixmap("user.png"));
    m_ileLogin->setIconClickable(false);
    m_ileLogin->setMinimumWidth(300);
    lytMain->addWidget(m_ileLogin);

    m_ilePassword = new IconizedLineEdit(this);
    m_ilePassword->setPlaceholderText("Введите пароль");
    m_ilePassword->setIconVisiblity(IconizedLineEdit::IconVisibleOnEmptyText);
    m_ilePassword->setIconPixmap(QPixmap("unlock.png"));
    m_ilePassword->setIconClickable(false);
    m_ilePassword->setEchoMode(QLineEdit::Password);
    lytMain->addWidget(m_ilePassword);

    auto lytButtons = new QHBoxLayout;

    lytButtons->addStretch();
    m_btnLogin = new QPushButton("&Вход");
    lytButtons->addWidget(m_btnLogin);
    m_btnClose = new QPushButton("&Закрыть");
    lytButtons->addWidget(m_btnClose);

    lytMain->addLayout(lytButtons);
}

void MainWindow::logined() {
    if (m_ileLogin->text().isEmpty() || m_ilePassword->text().isEmpty())
        QMessageBox::information(nullptr, "Вход в систему", "Не введен логин или пароль");
    else {
        QMessageBox::information(nullptr, "Вход в систему", "Выполнен успешный вход в систему");
        close();
    }
}

