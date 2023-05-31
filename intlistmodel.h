#ifndef INTLISTMODEL_H
#define INTLISTMODEL_H
#pragma once
#include <QMainWindow>
#include <QAbstractListModel>

class IntListModel : public QAbstractListModel {
Q_OBJECT
private:
    QList<int> m_list;
public:
    IntListModel();
    IntListModel(const QList<int>& list, QObject* pobj = 0);
};

#endif // INTLISTMODEL_H
