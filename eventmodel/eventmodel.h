#ifndef EVENTMODEL_H
#define EVENTMODEL_H

#include <QAbstractProxyModel>

class EventModel : public QAbstractItemModel
{
public:
    enum Roles
    {
        EventRole = Qt::UserRole + 1,
    };
    explicit EventModel(QObject* parent = nullptr);
    virtual  ~EventModel();
    virtual int rowCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual int columnCount(const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    virtual QModelIndex index(int row, int column, const QModelIndex& parentIndex = QModelIndex()) const override;
    virtual QModelIndex parent(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

private:
    QVector<QString> m_events;
};

#endif // EVENTMODEL_H
