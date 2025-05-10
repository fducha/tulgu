#ifndef PERSONSMODEL_H
#define PERSONSMODEL_H

#include <QAbstractTableModel>
#include "../domain/person.h"

class PersonRepository;

class PersonsModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit PersonsModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void refresh();

    void removeRow(int row);
    void add(Person &person);
    void update(const Person &person);

    Person person(int row) const;
    int row(const Person &person) const;

private:
    PersonRepository *m_repo;
};

#endif // PERSONSMODEL_H
