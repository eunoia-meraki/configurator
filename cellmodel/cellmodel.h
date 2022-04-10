#ifndef CELLMODEL_H
#define CELLMODEL_H

#include <QAbstractItemModel>
#include "eventmodel.h"
#include "proxymodel.h"

class CellModel : public QAbstractItemModel
{
    Q_OBJECT
    Q_PROPERTY(QAbstractItemModel* eventModel WRITE setEventModel)
    Q_PROPERTY(QAbstractProxyModel* proxyModel WRITE setProxyModel)

public:
    enum Roles
    {
        CellRole = Qt::UserRole + 1,
    };
    explicit CellModel(QObject* parent = nullptr);
    virtual  ~CellModel();
    virtual int rowCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    virtual QModelIndex index(int row, int column, const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;
    void setEventModel(QAbstractItemModel* eventModel);
    void setProxyModel(QAbstractProxyModel* proxyModel);

private slots:
        void resetCells();

//signals:
//        void cellsReset();

private:
    QAbstractProxyModel* m_proxyModel;
    QAbstractItemModel* m_eventModel;
    QVector<bool> m_cells;
    QVector<int> m_markedColumns;
};

#endif // CELLMODEL_H
