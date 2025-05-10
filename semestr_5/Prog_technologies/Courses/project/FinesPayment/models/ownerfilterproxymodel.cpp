#include "ownerfilterproxymodel.h"

OwnerFilterProxyModel::OwnerFilterProxyModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{}

void OwnerFilterProxyModel::setFilter(const QString &filter) {
    m_filter = filter.toLower();
    invalidateFilter();
}

bool OwnerFilterProxyModel::filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const {
    if (m_filter.isEmpty()) return true;

    QModelIndex familyNameIndex = sourceModel()->index(sourceRow, 1, sourceParent);
    QModelIndex nameIndex = sourceModel()->index(sourceRow, 2, sourceParent);
    QModelIndex surNameIndex = sourceModel()->index(sourceRow, 3, sourceParent);
    QModelIndex passportIndex = sourceModel()->index(sourceRow, 5, sourceParent);
    QModelIndex licenseIndex = sourceModel()->index(sourceRow, 6, sourceParent);

    return (sourceModel()->data(familyNameIndex).toString().toLower().contains(m_filter)) ||
           (sourceModel()->data(nameIndex).toString().toLower().contains(m_filter)) ||
           (sourceModel()->data(surNameIndex).toString().toLower().contains(m_filter)) ||
           (sourceModel()->data(passportIndex).toString().toLower().contains(m_filter)) ||
           (sourceModel()->data(licenseIndex).toString().toLower().contains(m_filter));
}


