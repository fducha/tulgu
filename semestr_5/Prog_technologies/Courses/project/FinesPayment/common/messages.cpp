#include "messages.h"

#include <QMessageBox>
#include <QPushButton>
#include <QtCore/QSharedPointer>
#include <QApplication>

bool Messages::okToDelete(QWidget *parent, const QString &title, const QString &text, const QString &detailedText)
{
    QSharedPointer<QMessageBox> msgBox(new QMessageBox(parent));
    if (parent)
        msgBox->setWindowModality(Qt::WindowModal);
    msgBox->setIcon(QMessageBox::Question);
    msgBox->setWindowTitle(QString("%1 - %2")
                               .arg(QApplication::applicationName())
                               .arg(title));
    msgBox->setText(text);
    if (!detailedText.isEmpty()) msgBox->setInformativeText(detailedText);
    QPushButton *btnDelete = msgBox->addButton(QObject::tr("&Remove"), QMessageBox::AcceptRole);
    QPushButton *btnCancel = msgBox->addButton(QObject::tr("&Cancel"), QMessageBox::RejectRole);
    msgBox->setDefaultButton(btnCancel);
    msgBox->exec();
    return msgBox->clickedButton() == btnDelete;
}

void Messages::information(QWidget *parent, const QString &title, const QString &text, const QString &detailedText)
{
    QSharedPointer<QMessageBox> msgBox(new QMessageBox(parent));
    if (parent)
        msgBox->setWindowModality(Qt::WindowModal);
    msgBox->setIcon(QMessageBox::Information);
    msgBox->setWindowTitle(QString("%1 - %2")
                               .arg(QApplication::applicationName())
                               .arg(title));
    msgBox->setText(text);
    if (!detailedText.isEmpty()) msgBox->setInformativeText(detailedText);
    msgBox->addButton(QMessageBox::Ok);
    msgBox->exec();
}
