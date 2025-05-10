#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "models/ownersmodel.h"
#include "models/ownerfilterproxymodel.h"
#include "common/messages.h"
#include "ui/ownereditdialog.h"
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // === СОБСТВЕННИКИ === СОБСТВЕННИКИ === СОБСТВЕННИКИ ===

    m_mdlOwners = new OwnersModel();
    m_mdlProxyOwners = new OwnerFilterProxyModel();
    m_mdlProxyOwners->setSourceModel(m_mdlOwners);

    ui->tvOwners->setModel(m_mdlProxyOwners);
    ui->tvOwners->setColumnHidden(0, true);
    ui->tvOwners->installEventFilter(this);

    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 115);
    ui->tvOwners->setColumnWidth(1, 140);
    ui->tvOwners->setColumnWidth(1, 146);

    enableOwnerCRUDBtns(false);
    enableVehicleCRUDBtns(false);

    ui->tvOwners->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    connect(ui->leSearchOwner, &QLineEdit::textChanged,
            m_mdlProxyOwners, &OwnerFilterProxyModel::setFilter);
    connect(ui->tvOwners->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &MainWindow::handleSelectionOwner);
    connect(ui->tvOwners, &QTableView::doubleClicked,
            this, &MainWindow::handleClickUpdateOwnerBtn);
    connect(ui->btnAddOwner, &QPushButton::clicked,
            this, &MainWindow::handleClickAddOwnerBtn);
    connect(ui->btnUpdateOwner, &QPushButton::clicked,
            this, &MainWindow::handleClickUpdateOwnerBtn);
    connect(ui->btnRemoveOwner, &QPushButton::clicked,
            this, &MainWindow::handleClickRemoveOwnerBtn);


    // === ТС === ТС === ТС === ТС === ТС === ТС === ТС =====
    connect(ui->tvVehicles->selectionModel(), &QItemSelectionModel::currentChanged,
            this, &MainWindow::handleSelectionVehicle);
    connect(ui->tvVehicles, &QTableView::doubleClicked,
            this, &MainWindow::handleClickUpdateVehicleBtn);
    connect(ui->btnAddVehicle, &QPushButton::clicked,
            this, &MainWindow::handleClickAddVehicleBtn);
    connect(ui->btnUpdateVehicle, &QPushButton::clicked,
            this, &MainWindow::handleClickUpdateVehicleBtn);
    connect(ui->btnRemoveVehicle, &QPushButton::clicked,
            this, &MainWindow::handleClickRemoveVehicleBtn);


    // === ВЗАИМОДЕЙСТВИЕ === ВЗАИМОДЕЙСТВИЕ === ВЗАИМОДЕЙСТВИЕ ===
    connect(this, &MainWindow::ownerChanged, this,
            &MainWindow::handleOwnerChanging);
}

MainWindow::~MainWindow() {
    delete ui;
    delete m_mdlOwners;
    delete m_mdlProxyOwners;
}

void MainWindow::handleClickAddOwnerBtn() {
    QSharedPointer<OwnerEditDialog> dialog(new OwnerEditDialog(this));
    auto o = dialog->start();
    if (!o.isEmpty()) {
        if (m_mdlOwners->add(o)) {
            int row = m_mdlOwners->row(o);
            ui->tvOwners->selectRow(row);
        } else if (m_mdlOwners->hasDublicates(o.passport(), o.license())) {
            Messages::information(this, tr("Добавление собственника"),
                                  tr("Собственник не добавлен"),
                                  tr("Дублирование документов, удостоверяющих личность"));
        } else {
            Messages::information(this, tr("Добавление собственника"),
                                  tr("Собственник не добавлен"),
                                  tr("Неизвестная ошибка"));
        }
    }
}

void MainWindow::handleClickUpdateOwnerBtn() {
    if (!ui->tvOwners->currentIndex().isValid()) return;

    /// FIXME разные номера строк в основной и прокси моделях, на изменение отдается другой собственик
    int row = ui->tvOwners->currentIndex().row();
    auto o = m_mdlOwners->owner(row);
    QSharedPointer<OwnerEditDialog> dialog(new OwnerEditDialog(this));
    auto o2 = dialog->start(o);
    if (o2.isValid()) {
        if (m_mdlOwners->update(o2)) {
            //
        } else if (m_mdlOwners->hasDublicates(o.passport(), o.license())) {
            Messages::information(this, tr("Изменение собственника"),
                                  tr("Собственник не изменен"),
                                  tr("Дублирование документов, удостоверяющих личность"));
        } else {
            Messages::information(this, tr("Изменение собственника"),
                                  tr("Собственник не изменен"),
                                  tr("Неизвестная ошибка"));
        }
        ui->tvOwners->selectRow(row);
    }
}

void MainWindow::handleClickRemoveOwnerBtn() {
    /// FIXME разные номера строк в основной и прокси моделях, на удаление идет другой собственик
    if (ui->tvOwners->currentIndex().isValid()) {
        int row = ui->tvOwners->currentIndex().row();
        auto p = m_mdlOwners->owner(row);
        if (Messages::okToDelete(
                this, tr("Удаление собственника"),
                tr("Удалить собственника %1 %2 %3 из списка?")
                    .arg(p.familyName(), p.name(), p.surName()),
                tr("Внимание! Будут удалены ВСЕ транспортные средства "
                   "зарегистрированные на данного собственника!"))) {
            if (m_mdlOwners->removeRow(row)) {
                ui->tvOwners->selectionModel()->clearSelection();
            } else {
                Messages::information(this, tr("Удаление собственника"),
                                      tr("Собственник не удален"),
                                      tr("Неизвестная ошибка"));
            }
        }
    }
}

void MainWindow::handleSelectionOwner(const QModelIndex &current,
                                      const QModelIndex &previous) {
    Q_UNUSED(previous)
    enableOwnerCRUDBtns(current.isValid());
    if (current.isValid()) {
        emit ownerChanged(m_mdlProxyOwners->index(current.row(), 0).data().toInt());
    }
}

void MainWindow::handleClickAddVehicleBtn() {
    /// TODO handleClickAddVehicleBtn

    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 170);
    ui->tvOwners->setColumnWidth(1, 115);
    ui->tvOwners->setColumnWidth(1, 140);
    ui->tvOwners->setColumnWidth(1, 146);
    for (int col = 1; col <= 6; ++col) {
        qDebug() << m_mdlOwners->headerData(col, Qt::Horizontal) << ui->tvOwners->columnWidth(col);
    }

}

void MainWindow::handleClickUpdateVehicleBtn() {
    /// TODO handleClickUpdateVehicleBtn
}

void MainWindow::handleClickRemoveVehicleBtn() {
    /// TODO handleClickRemoveVehicleBtn
}

void MainWindow::handleSelectionVehicle(const QModelIndex &current,
                                        const QModelIndex &previous) {
    Q_UNUSED(previous)
    enableVehicleCRUDBtns(current.isValid());
}

void MainWindow::handleOwnerChanging(int ownerId) {
    ui->leOwnerName->setText(tr("%1").arg(ownerId));
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {

    // === СОБСТВЕННИКИ === СОБСТВЕННИКИ === СОБСТВЕННИКИ ===

    if (obj == ui->tvOwners && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit ui->btnUpdateOwner->clicked();
            return true;
        }
        if (keyEvent->key() == Qt::Key_Tab) {
            ui->btnAddOwner->setFocus();
        }
    }

    // === ТС === ТС === ТС === ТС === ТС === ТС === ТС =====

    if (obj == ui->tvVehicles && event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if (keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter) {
            emit ui->btnUpdateVehicle->clicked();
            return true;
        }
        if (keyEvent->key() == Qt::Key_Tab) {
            ui->btnAddVehicle->setFocus();
        }
    }
    return false;
}

void MainWindow::enableOwnerCRUDBtns(bool enable) {
    ui->btnUpdateOwner->setEnabled(enable);
    ui->btnRemoveOwner->setEnabled(enable);
}

void MainWindow::enableVehicleCRUDBtns(bool enable) {
    ui->btnUpdateVehicle->setEnabled(enable);
    ui->btnRemoveVehicle->setEnabled(enable);
}
