#include "personeditdialog.h"
#include "ui_personeditdialog.h"
#include "../common/messages.h"

PersonEditDialog::PersonEditDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PersonEditDialog)
{
    ui->setupUi(this);

    ui->deBirthDate->setDate(QDate::currentDate());
}

PersonEditDialog::~PersonEditDialog()
{
    delete ui;
}

Person PersonEditDialog::start(const Person &person) {
    if (person.isValid()) {
        setWindowTitle(tr("Редактирование данных собственника"));
        ui->leFamilyName->setText(person.familyName());
        ui->leName->setText(person.name());
        ui->leSurName->setText(person.surName());
        ui->deBirthDate->setDate(person.birthDay());
        ui->lePassport->setText(person.passport());
        ui->leLicense->setText(person.license());
    } else {
        setWindowTitle(tr("Добавление собственника"));
    }
    ui->leFamilyName->setFocus();

    int code = exec();
    if (code == QDialog::Accepted) {
        auto p = Person(ui->leFamilyName->text(), ui->leName->text(),
                      ui->leSurName->text(), ui->deBirthDate->date(),
                      ui->lePassport->text(), ui->leLicense->text());
        p.setId(person.id());
        return p;
    }

    return Person();
}

void PersonEditDialog::accept() {
    if (ui->leFamilyName->text().isEmpty()) {
        Messages::information(this, "", tr("Не введена Фамилия собственника"));
        ui->leFamilyName->setFocus();
        return;
    }
    if (ui->leName->text().isEmpty()) {
        Messages::information(this, "", tr("Не введено Имя собственника"));
        ui->leName->setFocus();
        return;
    }
    if (ui->leSurName->text().isEmpty()) {
        Messages::information(this, "", tr("Не введено Отчество собственника"));
        ui->leSurName->setFocus();
        return;
    }
    if (ui->deBirthDate->date() > QDate::currentDate().addYears(-16)) {
        Messages::information(this, "", tr("Собственнику не исполнилось 16 лет."));
        ui->deBirthDate->setFocus();
        return;
    }
    if (ui->lePassport->text().isEmpty() || ui->lePassport->text().size() != 12) {
        Messages::information(this, "", tr("Не введен Паспорт собственника"));
        ui->lePassport->setFocus();
        return;
    }
    if (ui->leLicense->text().isEmpty() || ui->leLicense->text().size() != 12) {
        Messages::information(this, "", tr("Не введен Водительское удостоверение"));
        ui->leLicense->setFocus();
        return;
    }

    QDialog::accept();
}
