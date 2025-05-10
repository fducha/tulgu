#ifndef OWNERSMODEL_H
#define OWNERSMODEL_H

#include <QAbstractTableModel>
#include "../domain/owner.h"

class OwnerRepository;

class OwnersModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit OwnersModel(QObject *parent = nullptr);

    QVariant headerData(int section,
                        Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    void refresh();

    bool removeRow(int row);
    bool add(Owner &owner);
    bool update(const Owner &owner);

    Owner owner(int row) const;
    int row(const Owner &owner) const;

    /// метод проверяет наличие дубликатов паспорта и ВУ в списке собственников
    /// при проверке по одному документу, второй задаем пустой строкой ""
    bool hasDublicates(const QString &passport, const QString &license) const;

private:
    OwnerRepository *m_repo;
};

#endif // OWNERSMODEL_H
