#ifndef TREEITEM_H
#define TREEITEM_H

#include <QVariant>
#include <QVector>


class TreeItem /*: public QObject*/
{

   // Q_OBJECT

public:
    TreeItem() {}

    virtual ~TreeItem()
    {
        qDeleteAll(m_childItems);
    }

    enum ItemType { None = 0, LD, LN, DO, DA }; /*Q_ENUMS(ItemType)*/

    TreeItem* setParent(TreeItem* parentItem = nullptr)
    {
        return m_parentItem = parentItem;
    }

    TreeItem* parent()
    {
        return m_parentItem;
    }

    TreeItem* child(int row)
    {
        if (row < 0 || row >= m_childItems.size())
            return nullptr;

        return m_childItems.at(row);
    }

    void appendChild(TreeItem* childItem)
    {
        m_childItems.append(childItem);
    }

    int childCount() const
    {
        return m_childItems.count();
    }

    int row() const
    {
        if (m_parentItem)
            return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));

        return 0;
    }

    bool removeChild(int position)
    {
        if (position < 0 || position > m_childItems.size())
            return false;

        m_childItems.remove(position);

        return true;
    }

    virtual QString desc() const
    {
        return QString();
    }

    virtual  void setDesc(const QString& desc)
    {
        Q_UNUSED(desc)
    }

    virtual QString name() const
    {
        return QString();
    }

    virtual void setName(const QString& name)
    {
        Q_UNUSED(name)
    }

    virtual bool checked() const
    {
        return false;
    }

    virtual void setChecked(bool checked)
    {
        Q_UNUSED(checked)
    }

    virtual bool checkable() const
    {
        return false;
    }

    virtual bool enabled() const
    {
        return true;
    }

    virtual ItemType itemType() const
    {
        return None;
    }

private:
    TreeItem* m_parentItem;
    QVector<TreeItem*> m_childItems;

};

class TreeItemDescribed : public TreeItem
{

public:
    TreeItemDescribed() {}

    virtual ~TreeItemDescribed() {}

    virtual QString desc() const override
    {
        return m_desc;
    }

    virtual void setDesc(const QString& desc) override
    {
        m_desc = desc;
    }

private:
    QString m_desc;

};

class TreeItemCheckable : public TreeItemDescribed
{

public:
    TreeItemCheckable() {}

    virtual ~TreeItemCheckable() {}

    virtual bool checkable() const override
    {
        return true;
    }

    virtual bool checked() const override
    {
        return m_checked;
    }

    virtual void setChecked(bool checked) override
    {
        m_checked = checked;
    }

    void setChecked(const QString& checked)
    {
        if (checked == QLatin1String("true"))
            m_checked = true;
        else
            m_checked = false;
    }

    virtual bool enabled() const override
    {
        if (m_presCond != QLatin1String("M"))
            return true;
        else
            return false;
    }

    QString presCond() const
    {
        return m_presCond;
    }

    virtual void setPresCond(const QString& presCond)
    {
        m_presCond = presCond;
    }

private:
    bool m_checked;
    QString m_presCond;

};

class LdItem : public TreeItemDescribed
{

public:
    LdItem() {}

    virtual ~LdItem() {}

    virtual ItemType itemType() const override
    {
        return LD;
    }

    virtual QString name() const override
    {
        return m_inst;
    }

    virtual void setName(const QString& name) override
    {
        m_inst = name;
    }

private:
    QString m_inst;

};

class LnItem : public TreeItemDescribed
{

public:
    LnItem() {}

    virtual ~LnItem() {}

    virtual ItemType itemType() const override
    {
        return LN;
    }

    virtual QString name() const override
    {
        return m_prefix + m_lnClass + m_inst;
    }

    void setPrefix(const QString& prefix)
    {
        m_prefix = prefix;
    }

    void setLnClass(const QString& lnClass)
    {
        m_lnClass = lnClass;
    }

    void setInst(const QString& inst)
    {
        m_lnClass = inst;
    }

private:
    QString m_prefix;
    QString m_lnClass;
    QString m_inst;

};

class DoItem : public TreeItemCheckable
{

public:
    DoItem() {}

    virtual ~DoItem() {}

    virtual ItemType itemType() const override
    {
        return DO;
    }

    QString cdc() const
    {
        return m_cdc;
    }

    void setCdc(const QString& cdc)
    {
        m_cdc = cdc;
    }

    virtual QString name() const override
    {
        return m_name;
    }

    virtual void setName(const QString& name) override
    {
        m_name = name;
    }

private:
    QString m_name;
    QString m_cdc;
};

class DaItem : public TreeItemCheckable
{

public:
    DaItem() {}

    virtual ~DaItem() {}

    virtual ItemType itemType() const override
    {
        return DA;
    }

    virtual QString name() const override
    {
        return m_name;
    }

    virtual void setName(const QString& name) override
    {
        m_name = name;
    }

    QString fc()
    {
        return m_fc;
    }

    void setFc(const QString& fc)
    {
        m_fc = fc;
    }

    bool dchg()
    {
        return m_dchg;
    }

    void setDchg(bool dchg)
    {
        m_dchg =  dchg;
    }

    void setDchg(const QString& dchg)
    {
        if (dchg == QLatin1String("true"))
            m_dchg = true;
        else
            m_dchg = false;
    }

    bool qchg()
    {
        return m_qchg;
    }

    void setQchg(bool qchg)
    {
        m_qchg = qchg;
    }

    void setQchg(const QString& qchg)
    {
        if (qchg == QLatin1String("true"))
            m_qchg = true;
        else
            m_qchg = false;
    }

    bool dupd()
    {
        return m_dupd;
    }

    void setDupd(bool dupd)
    {
        m_dupd = dupd;
    }

    void setDupd(const QString& dupd)
    {
        if (dupd == QLatin1String("true"))
            m_dupd = true;
        else
            m_dupd = false;
    }

    //!!! добавил

    QString type()
    {
        return m_type;
    }

    void setType(const QString& type)
    {
        m_type = type;
    }

    int event()
    {
        return m_event;
    }

    void setEvent(int event)
    {
        m_event = event;
    }

    void setEvent(const QString& event)
    {
        m_event = event.toInt();
    }

private:
    QString m_name;
    QString m_fc;
    bool m_dchg;
    bool m_qchg;
    bool m_dupd;

    //!!! добавил
    QString m_type;
    int m_event;
};

#endif // TREEITEM_H
