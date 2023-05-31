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
    void set_name(QString);
    void set_id(QString);

    QString rand_id();
    int get_size();
    QVector<Item> set_vector_of_items();
    int get_rand_count(int, int, int);

};

#endif // ITEM_H
