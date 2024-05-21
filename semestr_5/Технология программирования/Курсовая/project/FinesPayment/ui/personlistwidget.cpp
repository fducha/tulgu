#include "personlistwidget.h"
#include "ui_personlistwidget.h"
#include "../models/personsmodel.h"
#include "../models/personfilterproxymodel.h"
#include "../common/messages.h"
#include "personeditdialog.h"
#include <QKeyEvent>

PersonListWidget::PersonListWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PersonListWidget)
{
    ui->setupUi(this);
    m_model = new PersonsModel();
    m_filterModel = new PersonFilterProxyModel();
    m_filterModel->setSourceModel(m_model);

    connect(ui->leSearch, &QLineEdit::textChanged,
            m_filterModel, &PersonFilterProxyModel::setFilter);

    ui->tvPersons->setModel(m_filterModel);
    ui->tvPersons->setColumnHidden(0, true);
    ui->tvPersons->installEventFilter(this);

    enableCRUDButtons(false);

    connect(ui->tvPersons->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &PersonListWidget::personSelected);
    connect(ui->btnAddPerson, &QPushButton::clicked,
            this, &PersonListWidget::addBtnClicked);
    connect(ui->btnUpdatePerson, &QPushButton::clicked,
            this, &PersonListWidget::updateBtnClicked);
    connect(ui->tvPersons, &QTableView::doubleClicked,
            this, &PersonListWidget::updateBtnClicked);
    connect(ui->btnRemovePerson, &QPushButton::clicked,
            this, &PersonListWidget::removeBtnClicked);
}

PersonListWidget::~PersonListWidget() {
    delete ui;
    delete m_model;
    delete m_filterModel;
}

void PersonListWidget::addBtnClicked() {
    QSharedPointer<PersonEditDialog> dialog(new PersonEditDialog(this));
    auto p = dialog->start();
    if (!p.isEmpty()) {
        m_model->add(p);
        int row = m_model->row(p);
        ui->tvPersons->selectRow(row);
    }
}

void PersonListWidget::updateBtnClicked() {
    if (!ui->tvPersons->currentIndex().isValid()) return;

    int row = ui->tvPersons->currentIndex().row();
    auto p = m_model->person(row);
    QSharedPointer<PersonEditDialog> dialog(new PersonEditDialog(this));
    auto p_ch = dialog->start(p);
    if (p_ch.isValid()) {
        m_model->update(p_ch);
        ui->tvPersons->selectRow(row);
    }
}

void PersonListWidget::removeBtnClicked() {
    if (ui->tvPersons->currentIndex().isValid()) {
        int row = ui->tvPersons->currentIndex().row();
        auto p = m_model->person(row);
        if (Messages::okToDelete(
                this, tr("Удаление собственника"),
                tr("Удалить собственника %1 %2 %3 из списка?")
                    .arg(p.familyName(), p.name(), p.surName()),
                tr("Внимание! Будут удалены ВСЕ транспортные средства "
                   "зарегистрированные на данного собственника!"))) {
            m_model->removeRow(row);
            ui->tvPersons->selectionModel()->clearSelection();
        }
    }
}

void PersonListWidget::personSelected(const QModelIndex &current,
                                      const QModelIndex &previous) {
    Q_UNUSED(previous)
    enableCRUDButtons(current.isValid());
}

bool PersonListWidget::eventFilter(QObject *obj, QEvent *event) {
    if (obj == ui->tvPersons && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit ui->btnUpdatePerson->clicked();
            return true;
        }
    }
    return false;
}

void PersonListWidget::enableCRUDButtons(bool enable) {
    ui->btnUpdatePerson->setEnabled(enable);
    ui->btnRemovePerson->setEnabled(enable);
}
