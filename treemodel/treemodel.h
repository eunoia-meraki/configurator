#ifndef TREEMODEL_H
#define TREEMODEL_H

#include "treeitem.h"
#include "nsdreader/nsddata.h"
#include <QAbstractItemModel>
#include <QUrl>
#include "builder/builder.h"

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum Roles
    {
        NameRole = Qt::UserRole + 1,
        DescriptionRole,
        CheckableRole,
        CheckedRole,
        EnabledRole,
        ItemTypeRole,
        QModelIndexRole
    };
    Q_ENUMS(Roles)

    explicit TreeModel(QObject* parent = nullptr);
    virtual ~TreeModel();
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    virtual QModelIndex index(int row, int column, const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex& index) const override;
    virtual int rowCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    //мои методы
    Q_INVOKABLE void setupModelData(QString fileUrl);
    Q_INVOKABLE void resetModel();
    Q_INVOKABLE void addLd();
    Q_INVOKABLE void addLn(const QModelIndex& parentIndex, const QVariant& value);
    Q_INVOKABLE void deleteLd(const QModelIndex& index);
    Q_INVOKABLE void deleteLn(const QModelIndex& index);
    void writeLnType(const QString& type, TreeItem* parentItem);
    void writeDoType(const QString& type, TreeItem* parentItem);
    void writeDaType(const QString& type, TreeItem* parentItem);

private:
    NsdData* m_nsd;
    TreeItem* m_rootItem;
};

#endif // TREEMODEL_H
