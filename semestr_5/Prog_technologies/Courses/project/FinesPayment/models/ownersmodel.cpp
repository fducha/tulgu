#include "ownersmodel.h"
#include "../repository/repos.h"
#include "repository/ownerrepository.h"

OwnersModel::OwnersModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_repo = Repos::get().owners();
}

QVariant OwnersModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role != Qt::DisplayRole) return QVariant();
    if (orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return "id";
        case 1:
            return tr("Фамилия");
        case 2:
            return tr("Имя");
        case 3:
            return tr("Отчество");
        case 4:
            return tr("Дата\nрождения");
        case 5:
            return tr("Паспорт");
        case 6:
            return tr("Водительское\nудостоверение");
        default:
            return QVariant();
        }
    }
    return QVariant();
}

int OwnersModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_repo->owners().count();
}

int OwnersModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return 7;
}

QVariant OwnersModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return m_repo->owners().at(index.row())->id();
        case 1:
            return m_repo->owners().at(index.row())->familyName();
        case 2:
            return m_repo->owners().at(index.row())->name();
        case 3:
            return m_repo->owners().at(index.row())->surName();
        case 4:
            return m_repo->owners().at(index.row())->birthDay().toString("dd.MM.yyyy");
        case 5:
            return m_repo->owners().at(index.row())->passport();
        case 6:
            return m_repo->owners().at(index.row())->license();
        default:
            return QVariant();
        }
    }

    return QVariant();
}

void OwnersModel::refresh() {
    beginResetModel();
    endResetModel();
}

bool OwnersModel::removeRow(int row) {
    QModelIndex index = this->index(row,0);
    if (index.isValid()) {
        int id = index.data().toInt();
        bool result = m_repo->remove(id);
        beginResetModel();
        endResetModel();
        return result;
    }
    return false;
}

bool OwnersModel::add(Owner &owner) {
    bool result = m_repo->add(owner);
    beginResetModel();
    endResetModel();
    return result;
}

/// Метод изменяет объект Owner в модели
/// По полю id производится поиск старого объекта.
/// Значения полей найденного объекта изменяются на значения полей передано объекта
/// @param owner Объект Owner с внесенными изменениями
bool OwnersModel::update(const Owner &owner) {
    bool result = m_repo->update(owner);
    beginResetModel();
    endResetModel();
    return result;
}

/// Метод возвращает объект Owner по номеру строки
/// @param row Номер строки
/// @return возвращает константный объект Owner.
/// При указании некорректной строки вернет пустой Owner()
Owner OwnersModel::owner(int row) const {
    QModelIndex index = this->index(row,0);
    if (index.isValid()) {
        int id = index.data().toInt();
        return m_repo->owner(id);
    }
    return Owner();
}

/// Метод возвращает номер строки содержащей объект Owner
/// Поиск выполняется сравнением id объекта с данными модели
/// @param owner Искомый объект Owner
/// @return Возвращает номер строки или -1 при отсутствии объекта в модели.
int OwnersModel::row(const Owner &owner) const {
    if (owner.isValid()) {
        for (int i = 0; i < rowCount(); i++) {
            if (this->index(i,0).data().toInt() == owner.id()) return i;
        }
    }
    return -1;
}

bool OwnersModel::hasDublicates(const QString &passport, const QString &license) const {
    auto data = m_repo->owners();

    for (auto p : qAsConst(data)) {
        if (p->passport() == passport || p->license() == license) return true;
    }

    return false;
}
