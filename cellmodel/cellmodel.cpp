#include "cellmodel.h"

CellModel::CellModel(QObject *parent) : QAbstractItemModel(parent)
{
}

CellModel::~CellModel()
{
}

void CellModel::setEventModel(QAbstractItemModel* eventModel)
{
    beginResetModel();

    if (m_eventModel)
    {
        disconnect(m_eventModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
        disconnect(m_eventModel, SIGNAL(modelReset()), this, SLOT(resetCells()));
    }


    m_eventModel = eventModel;

    connect(m_eventModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
    connect(m_eventModel, SIGNAL(modelReset()), this, SLOT(resetCells()));

    endResetModel();
}

void CellModel::setProxyModel(QAbstractProxyModel* proxyModel)
{
    beginResetModel();

    if (m_proxyModel)
    {
        disconnect(m_proxyModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
        disconnect(m_proxyModel, SIGNAL(modelReset()), this, SLOT(resetCells()));
    }


    m_proxyModel = proxyModel;

    connect(m_proxyModel, SIGNAL(modelReset()), this, SIGNAL(modelReset()));
    connect(m_proxyModel, SIGNAL(modelReset()), this, SLOT(resetCells()));

    endResetModel();
}


int CellModel::rowCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    if (m_proxyModel)
        return m_proxyModel->rowCount();

    return 0;
}

int CellModel::columnCount(const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    if (m_eventModel)
        return m_eventModel->columnCount();

    return 0;
}

QHash<int, QByteArray> CellModel::roleNames() const
{
    QHash<int, QByteArray> roleNames;

    roleNames[CellRole] = "cell";

    return roleNames;
}

QVariant CellModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() && role != CellRole)
        return QVariant();

    return m_cells.at(index.row() * m_eventModel->columnCount() + index.column());

    //return false;
}

bool CellModel::setData(const QModelIndex& index, const QVariant& value, int role)
{
    Q_UNUSED(value);

    if (!index.isValid() && role != CellRole)
        return false;

    int row = index.row();
    int column = index.column();
    int width = m_eventModel->columnCount();
    bool boolValue = value.toBool();

    QModelIndex proxyIndex = m_proxyModel->index(row, 0);
    QModelIndex dataIndex = m_proxyModel->mapToSource(proxyIndex);
    DaItem* daItem = static_cast<DaItem*>(dataIndex.internalPointer());

    if (boolValue)
    {
        if (m_markedColumns.at(row) != -1)
            m_cells[row * width + m_markedColumns.at(row)] = !boolValue;

        m_cells[row * width + column] = boolValue;
        m_markedColumns[row] = column;

        daItem->setEvent(column + 1);
    }
    else
    {
        m_cells[row * width + column] = boolValue;
        m_markedColumns[row] = -1;

        daItem->setEvent(0);
    }

    emit dataChanged(this->index(row, 0), this->index(row, width - 1));

    return true;
}

void CellModel::resetCells()
{   
    if (!(m_proxyModel && m_eventModel))
        return;

    beginResetModel();

    int height = m_proxyModel->rowCount();
    int width = m_eventModel->columnCount();

    m_markedColumns = QVector<int>(height, -1);
    m_cells = QVector<bool>(height * width, false);

    for (int row = 0; row < height; row++)
    {
        QModelIndex proxyIndex = m_proxyModel->index(row, 0);
        QModelIndex dataIndex = m_proxyModel->mapToSource(proxyIndex);
        DaItem* daItem = static_cast<DaItem*>(dataIndex.internalPointer());

        int event = daItem->event();

        if (event)
        {
            m_markedColumns[row] = event - 1;
            m_cells[row * width + event - 1] = true;
        }
    }

    endResetModel();
}

QModelIndex CellModel::index(int row, int column, const QModelIndex& parentIndex) const
{
    Q_UNUSED(parentIndex);

    if (!hasIndex(row, column))
        return QModelIndex();

    return createIndex(row, column);
}

QModelIndex CellModel::parent(const QModelIndex& index) const
{
    Q_UNUSED(index);
    return QModelIndex();
}
