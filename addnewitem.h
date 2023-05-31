#ifndef ADDNEWITEM_H
#define ADDNEWITEM_H

#include <QDialog>
#include <QObject>

namespace Ui {
class AddNewItem;
}

class AddNewItem : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewItem(QWidget *parent = nullptr);
    ~AddNewItem();

    QString textAddItem;
    QString get_text();


public slots:

signals:
    //void on_pushButtonAddItem_clicked();


private slots:
    void on_pushButtonCancel_clicked();
    void on_pushButtonAddItem_clicked();

private:
    Ui::AddNewItem *ui;

};

#endif // ADDNEWITEM_H
