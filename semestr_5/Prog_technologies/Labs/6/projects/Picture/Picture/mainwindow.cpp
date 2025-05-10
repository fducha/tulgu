#include "mainwindow.h"
#include "iconizedlineedit.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    m_layout = new QVBoxLayout;
    setLayout(m_layout);
    m_ileFileName = new IconizedLineEdit();
    m_ileFileName->setPlaceholderText("Нажмите, чтобы открыть файл");
    m_ileFileName->setIconVisiblity(IconizedLineEdit::IconAlwaysVisible);
    m_ileFileName->setIconPixmap(QPixmap("folder.png"));
    m_ileFileName->setIconClickable(true);
    connect(m_ileFileName, &IconizedLineEdit::iconPressed,
            this, &MainWindow::getFile);
    m_layout->addWidget(m_ileFileName);

    m_picture = new QLabel();
    m_layout->addWidget(m_picture);
}

MainWindow::~MainWindow() {
    delete m_layout;
    delete m_ileFileName;
    delete m_picture;
}

void MainWindow::getFile() {
    auto fileName = QFileDialog::getOpenFileName(this, "Открыть файл");
    m_ileFileName->setText(fileName);
    loadPicture(fileName);
}

void MainWindow::loadPicture(const QString &fileName) {
    m_picture->setPixmap(QPixmap(fileName).scaled(500, 500, Qt::KeepAspectRatio));
}

