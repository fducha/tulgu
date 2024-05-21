#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QValidator>
#include <QMessageBox>
#include "iconizedlineedit.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    createUi();
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
    // Логин пользователя с заглавной буквы
    // длинной от 2 до 10 символов латинского алфавита
    m_ileLogin->setValidator(new QRegExpValidator(QRegExp("[A-Z][a-z]{1,9}")));
    lytMain->addWidget(m_ileLogin);

    m_ilePassword = new IconizedLineEdit(this);
    m_ilePassword->setPlaceholderText("Введите пароль");
    m_ilePassword->setIconVisiblity(IconizedLineEdit::IconVisibleOnEmptyText);
    m_ilePassword->setIconPixmap(QPixmap("unlock.png"));
    m_ilePassword->setIconClickable(false);
    m_ilePassword->setEchoMode(QLineEdit::Password);
    // пароль пользователя пин-код длинной 6 цифр
    m_ilePassword->setValidator(new QRegExpValidator(QRegExp("[0-9]{6}")));
    lytMain->addWidget(m_ilePassword);

    connect(m_ileLogin, &IconizedLineEdit::textEdited,
            this, &MainWindow::onValidate);
    connect(m_ilePassword, &IconizedLineEdit::textEdited,
            this, &MainWindow::onValidate);

    auto lytButtons = new QHBoxLayout;

    lytButtons->addStretch();
    m_btnLogin = new QPushButton("&Вход");
    m_btnLogin->setEnabled(false);
    lytButtons->addWidget(m_btnLogin);
    m_btnClose = new QPushButton("&Закрыть");
    lytButtons->addWidget(m_btnClose);

    lytMain->addLayout(lytButtons);

    connect(m_btnClose, &QPushButton::clicked,
            this, &MainWindow::close);
    connect(m_btnLogin, &QPushButton::clicked,
            this, &MainWindow::logined);
}

void MainWindow::onValidate() {
    m_btnLogin->setEnabled(m_ileLogin->hasAcceptableInput() &&
                           m_ilePassword->hasAcceptableInput());

}

void MainWindow::logined() {
    QMessageBox::information(nullptr, "Вход в систему", "Выполнен успешный вход в систему");
    close();
}

