#ifndef PROXYMODEL_H
#define PROXYMODEL_H

#include <QAbstractProxyModel>
#include "treeitem.h"

class ProxyModel : public QAbstractProxyModel
{
    Q_OBJECT

public:
    enum Roles
    {
        DataRole = Qt::UserRole + 1,
    };
    explicit ProxyModel(QObject* parent = nullptr);
    virtual ~ProxyModel();
    virtual int rowCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& proxyIndex, int role = Qt::DisplayRole) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    virtual void setSourceModel(QAbstractItemModel* newModel) override;
    virtual QModelIndex	mapToSource(const QModelIndex& proxyIndex) const override;
    virtual QModelIndex	mapFromSource(const QModelIndex& sourceIndex) const override;

    QString	reference(TreeItem* item) const;
};

#endif // PROXYMODEL_H
