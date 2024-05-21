#ifndef PERSONFILTERPROXYMODEL_H
#define PERSONFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class PersonFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT

public:
    explicit PersonFilterProxyModel(QObject *parent = nullptr);

public slots:
    void setFilter(const QString &filter);

protected:
    virtual bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

private:
    QString m_filter{};
};

#endif // PERSONFILTERPROXYMODEL_H
