#ifndef OWNERFILTERPROXYMODEL_H
#define OWNERFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class OwnerFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit OwnerFilterProxyModel(QObject *parent = nullptr);

public slots:
    void setFilter(const QString &filter);

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_filter{};
};

#endif // OWNERFILTERPROXYMODEL_H
