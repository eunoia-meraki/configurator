#include <QDebug>
#include <QElapsedTimer>
#include <QXmlStreamReader>
#include <QFile>
#include "eventmodel.h"
#include "treeitem.h"

EventModel::EventModel(QObject *parent) : QAbstractItemModel(parent)
{
    QFile file(":/tree/Дерево Сириус-ПДС версия 1.04.xml");
    file.open(QIODevice::ReadOnly);

    QXmlStreamReader xml;
    xml.setDevice(&file);

    while (xml.attributes().value("name") != "Событие")
    {
        xml.readNext();
    }

    while (xml.readNextStartElement())
    {
        if (xml.name() == QLatin1String("param"))
        {
            QString name = xml.attributes().value("name").toString();

            m_events.append(name.right(name.size() - name.indexOf(" ") - 1));

            xml.skipCurrentElement();
        }
        else
            xml.skipCurrentElement();
    }
}

EventModel::~EventModel()
{
}

int EventModel::rowCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);
    return 1;
}

int EventModel::columnCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);
    return m_events.size();
}

QHash<int, QByteArray> EventModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;

    roleNames[EventRole] = "event";

    return roleNames;
}

QVariant EventModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role)
    {
        case EventRole:
            return m_events.at(index.column());
    }

    return QVariant();
}

QModelIndex EventModel::index(int row, int column, const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    if (!hasIndex(row, column))
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex EventModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}
