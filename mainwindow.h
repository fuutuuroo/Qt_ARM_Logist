#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "itemcountwindow.h"
#include "item.h"
#include <QTableWidget>
#include <QVector>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void fillTable(QVector<Item>);
    void on_tableItems_cellClicked(int row, int column);
    void on_tableItems_cellDoubleClicked(int row, int column);
    void on_pushButtonOpen_clicked();
    void on_pushButtonEdit_clicked();
    void on_pushButtonAdd_clicked();
    void on_pbDelete_clicked();
    void on_pbCancel_clicked();
    void on_pbAdd_clicked();
    void on_pbSave_clicked();
    void on_lineName_textChanged(const QString &str);
    void on_lineID_textChanged(const QString &str);

private:
    Ui::MainWindow *ui;
    ItemCountWindow *itemCountWind;
    QMessageBox msgBox;
    Item *item;
    QVector<Item> vectorItems;
    QString send_vector_name(int);
    QString send_vector_id(int);
};

#endif // MAINWINDOW_H
