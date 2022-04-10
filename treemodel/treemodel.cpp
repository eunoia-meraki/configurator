#include <QDebug>
#include <QFile>
#include <QElapsedTimer>
#include "treemodel.h"
#include "nsdreader/nsdreader.h"
//#include "nsdreader/dataobject.h"
#include "builder/builder.h"
#include "builder/ldbuilder.h"
#include "builder/lnbuilder.h"
#include "builder/dobuilder.h"
#include "builder/dabuilder.h"


TreeModel::TreeModel(QObject* parent)
    : QAbstractItemModel(parent)
{
    m_nsd = new NsdData();
    NsdReader reader(m_nsd);

    QFile file1(":/nsd/IEC_61850-7-4_2007B3.nsd");
    file1.open(QIODevice::ReadOnly);
    reader.read(&file1);
    file1.close();

    QFile file2(":/nsd/IEC_61850-7-3_2007B3.nsd");
    file2.open(QIODevice::ReadOnly);
    reader.read(&file2);
    file2.close();

    QFile file3(":/nsd/IEC_61850-7-2_2007B3.nsd");
    file3.open(QIODevice::ReadOnly);
    reader.read(&file3);
    file3.close();

    m_rootItem = new TreeItem();
}

TreeModel::~TreeModel()
{
    delete m_nsd;
    delete m_rootItem;
}

int TreeModel::columnCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);
    return 1;
}


QHash<int, QByteArray> TreeModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;

    roleNames[NameRole] = "name";
    roleNames[DescriptionRole] = "description";
    roleNames[CheckableRole] = "checkable";
    roleNames[CheckedRole] = "checked";
    roleNames[EnabledRole] = "enabled";
    roleNames[ItemTypeRole] = "itemType";
    roleNames[QModelIndexRole] = "qModelIndex";

    return roleNames;
}

bool TreeModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    if (!index.isValid())
        return false;

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    switch (role)
    {
        case NameRole:
            item->setName(value.toString());
            break;
        case DescriptionRole:
            item->setDesc(value.toString());
            break;
        case CheckedRole:
            item->setChecked(value.toBool());
            break;
    }

    emit dataChanged(index, index);

    return true;
}

QVariant TreeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    switch (role)
    {
        case NameRole:
            return item->name();
            break;
        case CheckableRole:
            return item->checkable();
            break;
        case CheckedRole:
            return item->checked();
            break;
        case EnabledRole:
            return item->enabled();
            break;
        case ItemTypeRole:
            return item->itemType();
            break;
        case DescriptionRole:
            return item->desc();
            break;
        case QModelIndexRole:
            return index;
            break;
    }

    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex& parentIndex) const
{
    if (!hasIndex(row, column, parentIndex))
        return QModelIndex();

    TreeItem* parentItem;

    if (!parentIndex.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TreeItem*>(parentIndex.internalPointer());

    TreeItem* childItem = parentItem->child(row);

    if (childItem)
        return createIndex(row, column, childItem);

    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    TreeItem* childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem* parentItem = childItem->parent();

    if (parentItem == m_rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int TreeModel::rowCount(const QModelIndex& parentIndex) const
{
    TreeItem* parentItem;

    if (!parentIndex.isValid())
        parentItem = m_rootItem;
    else
        parentItem = static_cast<TreeItem*>(parentIndex.internalPointer());

    return parentItem->childCount();
}

void TreeModel::resetModel()
{
    beginResetModel();

    delete m_rootItem;
    m_rootItem = new TreeItem();

    endResetModel();
}


void TreeModel::setupModelData(QString fileUrl)
{
    fileUrl.remove(0, 8);
    QFile file(fileUrl);
    file.open(QIODevice::ReadOnly);

    QXmlStreamReader xml;
    xml.setDevice(&file);

    beginResetModel();

    delete m_rootItem;
    m_rootItem = new TreeItem();

    QVector<TreeItem*> parents;
    parents << m_rootItem;

    while (xml.name() != QLatin1String("IED"))
    {
        xml.readNext();
    }

    while (!(xml.isEndElement() && xml.name() == QLatin1String("IED")))
    {
        if (xml.readNextStartElement())
        {
            Builder* builder;

            if (xml.name() == QLatin1String("LDevice"))
            {
                builder = new LdBuilder();
            }
            else if (xml.name() == QLatin1String("LN"))
            {
                builder = new LnBuilder();
            }
            else if (xml.name() == QLatin1String("DO") || xml.name() == QLatin1String("SDO"))
            {
                builder = new DoBuilder();
            }
            else
            {
                builder = new DaBuilder();
            }

            TreeItem* item = builder->buildFromXml(xml);
            delete builder;

            item->setParent(parents.last());
            parents.last()->appendChild(item);
            parents << item;
        }
        else
        {
            parents.pop_back();
        }
    }

    endResetModel();
}

void TreeModel::addLd()
{
    int count = m_rootItem->childCount();

    beginInsertRows(QModelIndex(), count, count);

    LdItem* ldItem = new LdItem();

    ldItem->setName("LD");

    ldItem->setParent(m_rootItem);
    m_rootItem->appendChild(ldItem);

    endInsertRows();
}

void TreeModel::addLn(const QModelIndex& parentIndex, const QVariant& value)
{

    TreeItem* parentItem = static_cast<TreeItem*>(parentIndex.internalPointer());

    int count = parentItem->childCount();

    beginInsertRows(parentIndex, count, count);

    LnItem* lnItem = new LnItem();

    lnItem->setLnClass(value.toString());

    lnItem->setParent(parentItem);
    parentItem->appendChild(lnItem);

    writeLnType(value.toString(), lnItem);

    endInsertRows();
}

void TreeModel::deleteLd(const QModelIndex& index)
{
    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    int row = item->row();

    beginRemoveRows(QModelIndex(), row, row);

    m_rootItem->removeChild(row);

    delete item;

    endRemoveRows();
}

void TreeModel::deleteLn(const QModelIndex& index)
{

    TreeItem* item = static_cast<TreeItem*>(index.internalPointer());

    int row = item->row();

    TreeItem* parentItem = item->parent();

    QModelIndex parentIndex = createIndex(parentItem->row(), 0, parentItem);

    beginRemoveRows(parentIndex, row, row);

    parentItem->removeChild(row);

    delete item;

    endRemoveRows();
}


void TreeModel::writeLnType(const QString& type, TreeItem* parentItem)
{
    LnClass lnClass = m_nsd->lnClasses().value(type);

    for (const DataObject& dataObject : lnClass.dataObjects())
    {
        DoBuilder builder;
        TreeItem* doItem = builder.buildFromNsd(dataObject);

        doItem->setParent(parentItem);
        parentItem->appendChild(doItem);

        writeDoType(dataObject.type(), doItem);
    }
}

void TreeModel::writeDoType(const QString& type, TreeItem* parentItem)
{
    Cdc cdc = m_nsd->cdcs().value(type);

    for (const DataObject& subDataObject : cdc.subDataObjects())
    {
        DoBuilder builder;
        TreeItem* doItem = builder.buildFromNsd(subDataObject);

        doItem->setParent(parentItem);
        parentItem->appendChild(doItem);

        writeDoType(subDataObject.type(), doItem);
    }

    for (const DataAttribute& dataAttribute : cdc.dataAttributes())
    {
        DaBuilder builder;
        TreeItem* daItem = builder.buildFromNsd(dataAttribute);

        daItem->setParent(parentItem);
        parentItem->appendChild(daItem);

        if (dataAttribute.typeKind() == QLatin1String("CONSTRUCTED"))
        {
            writeDaType(dataAttribute.type(), daItem);
        }
    }
}

void TreeModel::writeDaType(const QString& type, TreeItem* parentItem)
{
    ConstructedAttribute constructedAttribute = m_nsd->constructedAttributes().value(type);

    for (const DataAttribute& subDataAttribute : constructedAttribute.subDataAttributes())
    {
        DaBuilder builder;
        TreeItem* daItem = builder.buildFromNsd(subDataAttribute);

        daItem->setParent(parentItem);
        parentItem->appendChild(daItem);

        if (subDataAttribute.typeKind() == QLatin1String("CONSTRUCTED"))
        {
            writeDaType(subDataAttribute.type(), daItem);
        }
    }
}










