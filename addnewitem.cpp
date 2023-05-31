#include "addnewitem.h"
#include "ui_addnewitem.h"
#include <QLineEdit>
#include "mainwindow.h"
#include <QGraphicsScene>
#include <QObject>


AddNewItem::AddNewItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewItem)
{
    ui->setupUi(this);
    /*
    QPushButton *button = ui->pushButtonAddItem;
    MainWindow *mw;
    connect(button, &QPushButton::clicked, mw, &MainWindow::addTableItem);
    connect(button, &QPushButton::clicked, [mw]{mw->addTableItem();});
    */
}

AddNewItem::~AddNewItem()
{
    delete ui;
}

void AddNewItem::on_pushButtonCancel_clicked()
{
    close();
}

void AddNewItem::on_pushButtonAddItem_clicked()
{
    /*
    textAddItem = ui->lineAddItem->text();
    MainWindow mw;
    mw.addTableItem();
    close();
    */
}

QString AddNewItem::get_text() {
    return textAddItem;
}
