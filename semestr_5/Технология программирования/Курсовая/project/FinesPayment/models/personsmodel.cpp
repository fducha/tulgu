#include "personsmodel.h"
#include "../repository/repos.h"

PersonsModel::PersonsModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    m_repo = Repos::get().persons();
}

QVariant PersonsModel::headerData(int section, Qt::Orientation orientation, int role) const {
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
            return tr("Дата рождения");
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

int PersonsModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return m_repo->persons().count();
}

int PersonsModel::columnCount(const QModelIndex &parent) const {
    Q_UNUSED(parent)
    return 7;
}

QVariant PersonsModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole) {
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    }
    if (role == Qt::DisplayRole) {
        switch (index.column()) {
        case 0:
            return m_repo->persons().at(index.row()).id();
        case 1:
            return m_repo->persons().at(index.row()).familyName();
        case 2:
            return m_repo->persons().at(index.row()).name();
        case 3:
            return m_repo->persons().at(index.row()).surName();
        case 4:
            return m_repo->persons().at(index.row()).birthDay().toString("dd.MM.yyyy");
        case 5:
            return m_repo->persons().at(index.row()).passport();
        case 6:
            return m_repo->persons().at(index.row()).license();
        default:
            return QVariant();
        }
    }

    return QVariant();
}

void PersonsModel::refresh() {
    beginResetModel();
    endResetModel();
}

void PersonsModel::removeRow(int row) {
    QModelIndex index = this->index(row,0);
    if (index.isValid()) {
        int id = index.data().toInt();
        beginResetModel();
        m_repo->remove(id);
        endResetModel();
    }
}

void PersonsModel::add(Person &person) {
    beginResetModel();
    m_repo->add(person);
    endResetModel();
}

/// Метод изменяет объект Person в модели
/// По полю id производится поиск старого объекта.
/// Значения полей найденного объекта изменяются на значения полей передано объекта
/// @param person Объект Person с внесенными изменениями
void PersonsModel::update(const Person &person) {
    beginResetModel();
    m_repo->update(person);
    endResetModel();
}

/// Метод возвращает объект Person по номеру строки
/// @param row Номер строки
/// @return возвращает константный объект Person.
/// При указании некорректной строки вернет пустой Person()
Person PersonsModel::person(int row) const {
    QModelIndex index = this->index(row,0);
    if (index.isValid()) {
        int id = index.data().toInt();
        return m_repo->person(id);
    }
    return Person();
}

/// Метод возвращает номер строки содержащей объект Person
/// @param person Искомый объект Person
/// @return Возвращает номер строки или -1 при отсутствии объекта в модели.
int PersonsModel::row(const Person &person) const {
    if (person.isValid()) {
        for (int i = 0; i < rowCount(); i++) {
            if (this->index(i,0).data().toInt() == person.id()) return i;
        }
    }
    return -1;
}
