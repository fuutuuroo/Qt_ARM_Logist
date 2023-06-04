#ifndef ITEM_H
#define ITEM_H

#include <QMainWindow>
#include <QString>
#include <QRandomGenerator>
#include <QVector>

class Item {

private:
    QString name;
    QString id;

public:
    Item();
    ~Item();
    QString get_name();
    QString get_id();
    QString rand_id();
    void set_name(QString);
    void set_id(QString);
    int get_size();
    int get_rand_count(int, int, int);
    QVector<Item> set_vector_of_items();

};

#endif // ITEM_H
