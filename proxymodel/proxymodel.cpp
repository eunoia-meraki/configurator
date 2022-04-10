#include "proxymodel.h"
#include "treeitem.h"

ProxyModel::ProxyModel(QObject *parent) : QAbstractProxyModel(parent)
{
}

ProxyModel::~ProxyModel()
{
}

void ProxyModel::setSourceModel(QAbstractItemModel* newModel)
{
    beginResetModel();

    QAbstractItemModel* oldModel = sourceModel();

    if (oldModel)
    {
        disconnect(oldModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
        disconnect(oldModel, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(modelReset()));
        disconnect(oldModel, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(modelReset()));
    }

    QAbstractProxyModel::setSourceModel(newModel);

    connect(newModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
    connect(newModel, SIGNAL(rowsInserted(const QModelIndex&, int, int)), this, SIGNAL(modelReset()));
    connect(newModel, SIGNAL(rowsRemoved(const QModelIndex&, int, int)), this, SIGNAL(modelReset()));

    endResetModel();
}

QModelIndex ProxyModel::mapToSource(const QModelIndex& proxyIndex) const
{   
    if (!proxyIndex.isValid())
        return QModelIndex();

    QAbstractItemModel* model = sourceModel();

    if (!model)
        return QModelIndex();

    int row = proxyIndex.row();

    int order = -1;

    QModelIndex parent = QModelIndex();
    QModelIndex index = model->index(0, 0, parent);

    while (parent.isValid() || index.isValid())
    {
        if (index.isValid())
        {
            if (!model->hasChildren(index))
            {
                TreeItem* treeItem = static_cast<TreeItem*>(index.internalPointer());

                if (treeItem && treeItem->itemType() == TreeItem::DA)
                {
                    DaItem* daItem = static_cast<DaItem*>(treeItem);

                    if (daItem /*&& daItem->type() == QLatin1String("BOOLEAN") && daItem->fc() == QLatin1String("ST") && daItem->checked()*/)
                    {
                        order++;

                        if (order == row)
                            return index;

                    }
                }

                index = index.siblingAtRow(index.row() + 1);
            }
            else
            {
                parent = index;
                index = model->index(0, 0, parent);
            }
        }
        else
        {
            index = parent.siblingAtRow(parent.row() + 1);
            parent = parent.parent();
        }
    }

    return QModelIndex();
}

QModelIndex ProxyModel::mapFromSource(const QModelIndex& sourceIndex) const
{
    if (!sourceIndex.isValid())
        return QModelIndex();

    QAbstractItemModel* model = sourceModel();

    if (!model)
        return QModelIndex();

    int order = -1;

    QModelIndex parent = QModelIndex();
    QModelIndex index = model->index(0, 0, parent);

    while (parent.isValid() || index.isValid())
    {
        if (index.isValid())
        {
            if (!model->hasChildren(index))
            {
                TreeItem* treeItem = static_cast<TreeItem*>(index.internalPointer());

                if (treeItem && treeItem->itemType() == TreeItem::DA)
                {
                    DaItem* daItem = static_cast<DaItem*>(treeItem);

                    if (daItem /*&& daItem->type() == QLatin1String("BOOLEAN") && daItem->fc() == QLatin1String("ST") && daItem->checked()*/)
                    {
                        order++;

                        if (index == sourceIndex)
                            return this->index(order, 0);
                    }
                }

                index = index.siblingAtRow(index.row() + 1);
            }
            else
            {
                parent = index;
                index = model->index(0, 0, parent);
            }
        }
        else
        {
            index = parent.siblingAtRow(parent.row() + 1);
            parent = parent.parent();
        }
    }

    return QModelIndex();
}

int ProxyModel::rowCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    QAbstractItemModel* model = sourceModel();

    if (!model)
        return 0;

    int count = 0;

    QModelIndex parent = QModelIndex();
    QModelIndex index = model->index(0, 0, parent);

    while (parent.isValid() || index.isValid())
    {
        if (index.isValid())
        {
            if (!model->hasChildren(index))
            {
                TreeItem* treeItem = static_cast<TreeItem*>(index.internalPointer());

                if (treeItem && treeItem->itemType() == TreeItem::DA)
                {
                    DaItem* daItem = static_cast<DaItem*>(treeItem);

                    if (daItem /*&& daItem->type() == QLatin1String("BOOLEAN") && daItem->fc() == QLatin1String("ST") && daItem->checked()*/)
                    {
                        count++;
                    }
                }

                index = index.siblingAtRow(index.row() + 1);
            }
            else
            {
                parent = index;
                index = model->index(0, 0, parent);
            }
        }
        else
        {
            index = parent.siblingAtRow(parent.row() + 1);
            parent = parent.parent();
        }
    }

    return count;
}

int ProxyModel::columnCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);
    return 1;
}

QHash<int, QByteArray> ProxyModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;

    roleNames[DataRole] = "data";

    return roleNames;
}

QVariant ProxyModel::data(const QModelIndex& proxyIndex, int role) const
{
    if (!proxyIndex.isValid() && role != DataRole)
        return QVariant();

    QModelIndex sourceIndex = mapToSource(proxyIndex);

    TreeItem* item = static_cast<TreeItem*>(sourceIndex.internalPointer());

    return reference(item);

}

QString ProxyModel::reference(TreeItem *item) const
{
    QString reference;

    if (item)
    {
        QVector<QString> names;

        QString name = item->name();

        while (name != QLatin1String(""))
        {
            names << name;
            item = item->parent();
            item ? name = item->name() : name = "";
        }

        for (QVector<QString>::reverse_iterator i = names.rbegin(); i < names.rend(); i++)
        {
            reference = reference + "/" + *i;
        }

        reference.remove(0, 1);
    }

    return reference;
}

QModelIndex ProxyModel::index(int row, int column, const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    if (!hasIndex(row, column))
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex ProxyModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}
