#ifndef PERSONEDITDIALOG_H
#define PERSONEDITDIALOG_H

#include <QDialog>
#include "../domain/person.h"

namespace Ui {
class PersonEditDialog;
}

class PersonEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonEditDialog(QWidget *parent = nullptr);
    ~PersonEditDialog();

    Person start(const Person &person = Person());

private slots:
    virtual void accept() override;

private:
    Ui::PersonEditDialog *ui;
};

#endif // PERSONEDITDIALOG_H
