#ifndef OWNEREDITDIALOG_H
#define OWNEREDITDIALOG_H

#include <QDialog>
#include "../domain/owner.h"

namespace Ui {
class OwnerEditDialog;
}

class OwnerEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit OwnerEditDialog(QWidget *parent = nullptr);
    ~OwnerEditDialog();

    Owner start(const Owner &person = Owner());

private slots:
    virtual void accept() override;

private:
    Ui::OwnerEditDialog *ui;
};

#endif // OWNEREDITDIALOG_H
