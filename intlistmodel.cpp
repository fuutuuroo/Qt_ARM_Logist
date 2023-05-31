#include "intlistmodel.h"

IntListModel::IntListModel()
{

}

IntListModel::IntListModel (const QList<int>& list, QObject* pobj /*=0*/)
    : QAbstractListModel(pobj)
    , m_list(list) {}
