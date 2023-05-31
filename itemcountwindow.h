#ifndef ITEMCOUNTWINDOW_H
#define ITEMCOUNTWINDOW_H

#include <QDialog>
#include "item.h"
#include "report.h"

namespace Ui {
class ItemCountWindow;
}

class ItemCountWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ItemCountWindow(QWidget *parent = nullptr);
    ~ItemCountWindow();

    void fillTableCount(int);

    QString vectorName;
    QString vectorID;

private slots:
    void on_pushButtonClose_clicked();
    void on_tableItemCount_cellClicked(int row, int column);

private:
    Ui::ItemCountWindow *ui;
    Item *item;

    report *reportWind;
    void addReport();

};

#endif // ITEMCOUNTWINDOW_H
