#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "itemcountwindow.h"
#include "item.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("АРМ логиста в телекоммуникационной компании");
    ui->tableItems->setRowCount(item->get_size());      //указание кол-ва строк в зависимости от массива наименований
    ui->tableItems->setColumnCount(2);
    ui->tableItems->setHorizontalHeaderLabels(QStringList() << "Наименование" << "Идентификатор");
    ui->tableItems->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableItems->setSortingEnabled(true);            //включение возможноости сортировки таблицы
    vectorItems = item->set_vector_of_items();          //создание вектора с помощью соответствующей функции
    fillTable(vectorItems);                             //заполнение таблицы по данным из вектора
    //сокрытие элементов, которые не должны быть активны при начальном запуске окна
    ui->pushButtonEdit->setEnabled(0);
    ui->pushButtonOpen->setEnabled(0);
    ui->lineEdit->setEnabled(0);
    ui->pbAdd->hide();
    ui->pbSave->hide();
    ui->pbDelete->hide();
    ui->pbCancel->hide();
    ui->labelAdd->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//функция заполнения таблицы по полученным данным из вектора
void MainWindow::fillTable(QVector<Item> items) {
    for (int i = 0; i < items.size(); i++ ) {
        ui->tableItems->setItem(i, 0, new QTableWidgetItem(items[i].get_name()));
        ui->tableItems->setItem(i, 1, new QTableWidgetItem(items[i].get_id()));
    }
}
//обработка нажатия кнопки "Открыть" при выбранной ячейке таблицы, равносильна двойному клику по ячейку таблицы
void MainWindow::on_pushButtonOpen_clicked()
{   //сокрытие кнопок, которые не должны использоваться при открытой записи в таблице
    ui->lineEdit->setEnabled(0);
    ui->pbAdd->hide();
    ui->pbSave->hide();
    ui->pbDelete->hide();
    ui->pbCancel->hide();
    ui->labelAdd->hide();
    //создание нового окна типа ItemCountWindow и заполнение его информацией
    itemCountWind = new ItemCountWindow(this);
    itemCountWind->show();
    int row = ui->tableItems->currentRow();
    itemCountWind->vectorName = send_vector_name(row);
    itemCountWind->vectorID = send_vector_id(row);
    itemCountWind->fillTableCount(row);
}
//обработка двойного клика по ячейке, равносильна нажатию кнопки "Открыть" при выбранной ячейке таблицы
void MainWindow::on_tableItems_cellDoubleClicked(int row, int column)
{   //сокрытие кнопок, которые не должны использоваться при открытой записи в таблице
    ui->lineEdit->setEnabled(0);
    ui->pbAdd->hide();
    ui->pbSave->hide();
    ui->pbDelete->hide();
    ui->pbCancel->hide();
    ui->labelAdd->hide();
    //создание нового окна типа ItemCountWindow и заполнение его информацией
    itemCountWind = new ItemCountWindow(this);
    itemCountWind->show();
    itemCountWind->vectorName = send_vector_name(row);
    itemCountWind->vectorID = send_vector_id(row);
    itemCountWind->fillTableCount(row);
}
//обработка одинарного клика по ячейке таблицы
void MainWindow::on_tableItems_cellClicked(int row, int column)
{
    ui->pushButtonEdit->setEnabled(1);  //активация кнопок открытия и редактирования
    ui->pushButtonOpen->setEnabled(1);

    QString str;
    QTableWidgetItem *temp = ui->tableItems->item(row, 0);
    if (NULL != temp) {
        str = temp->text();
    }
    ui->lineEdit->setText(str);         //название из первого столбца дублируется в строку ниже
}   //даже если произошёл клик по второму столбцу, вниз тянется всё равно название, т.к. идентификатор нельзя изменить
//обработка кнопки "Добавить запись"
void MainWindow::on_pushButtonAdd_clicked()
{   //активация строки и необходимых для добавления кнопок
    ui->lineEdit->setEnabled(1);
    ui->lineEdit->clear();
    ui->labelAdd->show();
    ui->pbAdd->show();
    ui->pbCancel->show();
    ui->pbSave->hide();
    ui->pbDelete->hide();
}
//обработка кнопки "Редактировать запись"
void MainWindow::on_pushButtonEdit_clicked()
{   //активация строки и необходимых для редактирования кнопок
    QString str = ui->lineEdit->text();
    if (str != "") {    //редактирование запустится только если в строке есть содержимое
        ui->lineEdit->setText(str);
        ui->lineEdit->setEnabled(1);
        ui->pbAdd->hide();
        ui->pbSave->show();
        ui->pbDelete->show();
        ui->pbCancel->show();
        ui->labelAdd->hide();
    }
}
//обработки кнопки "Добавить" при создании новой записи
void MainWindow::on_pbAdd_clicked()
{
    bool check_name = 0;
    QString nameToAdd = ui->lineEdit->text();
    //проверка названия на уникальность, при повторе сработает флажок
    for (int i = 0; i <vectorItems.size(); i++) {
        if (nameToAdd == vectorItems[i].get_name()) {
            check_name = 1;
            break;
        }
    }
    //если не сработал флажок, и строка не пустая, то название записывается в элемент вектора
    if (ui->lineEdit->text() != "" && !check_name) {
        Item temp;
        temp.set_name(nameToAdd);

        QString idToAdd = temp.rand_id();                       //генерируется идентификатор
        bool check_str = 0;
        for (int i = 0; i < vectorItems.size(); i++) {          //проверка идентификатора на уникальность
            if (idToAdd == vectorItems[i].get_id()) {
                check_str = 1;
                break;
            }
        }
        while (check_str != 0) {
            check_str = 0;                                      //если при проверке сработал флажок, то
            idToAdd = temp.rand_id();                           //создание новой строки и её проверка,
            for (int i = 0; i < vectorItems.size(); i++) {      //пока она не будет уникальной
                if (idToAdd == vectorItems[i].get_id()) {
                    check_str = 1;
                    break;
                }
            }
        }

        temp.set_id(idToAdd);                                   //запись идентификатора в элемент вектора
        vectorItems.append(temp);
        int currentRow = ui->tableItems->rowCount();            //добавление строки в таблицу
        ui->tableItems->insertRow(currentRow);
        ui->tableItems->setItem(currentRow, 0, new QTableWidgetItem(vectorItems[currentRow].get_name()));
        ui->tableItems->setItem(currentRow, 1, new QTableWidgetItem(vectorItems[currentRow].get_id()));
    } else {    //если сработал первый флажок на дубль названия или строка пустая, то появится предупреждение
        QMessageBox::critical(this, "Некорректная строка!", "Строка пустая или дублирует уже существующую, введите корректную строку!");
    }
}
//обработка кнопки "Сохранить" при редактировании записи
void MainWindow::on_pbSave_clicked()
{   //создание QMessageBox для уточнения изменений
    msgBox.setWindowTitle("Изменение записи");
    msgBox.setText("Подтвердите изменение                               ");
    msgBox.setInformativeText("Вы уверены, что хотите изменить запись?");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int res = msgBox.exec();

    bool check_name = 0;
    QString nameToEdit = ui->lineEdit->text();  //взятие строки и проверка её на уникальность
    for (int i = 0; i <vectorItems.size(); i++) {
        if (nameToEdit == vectorItems[i].get_name()) {
            check_name = 1;
            break;
        }
    }
    //если не сработал флажок И получено подтверждение в окне, запись изменяется в векторе и таблице
    if (!check_name && res == QMessageBox::Ok) {
        int currentRow = ui->tableItems->currentRow();
        vectorItems[currentRow].set_name(nameToEdit);
        ui->tableItems->setItem(currentRow, 0, new QTableWidgetItem(vectorItems[currentRow].get_name()));
    } else if (res == QMessageBox::Cancel) {    //если нажата кнопка отмены, закрывается QMessageBox
        msgBox.close();
    } else {    //если сработал флажок на дубль названия или строка пустая, то появится предупреждение
        QMessageBox::critical(this, "Некорректная строка!", "Строка пустая или дублирует уже существующую, введите корректную строку!");
    }
}
//обработка кнопки "Удалить" при редактировании записи
void MainWindow::on_pbDelete_clicked()
{   //создание QMessageBox для подтверждения удаления
    msgBox.setWindowTitle("Удаление записи");
    msgBox.setText("Подтвердите удаление                ");
    msgBox.setInformativeText("Удаление записи необратимо, вы уверены?");
    msgBox.setIcon(QMessageBox::Warning);
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    int res = msgBox.exec();
    if (res == QMessageBox::Ok) {
        //удаление элемента вектора и строки таблицы
        int currentRow = ui->tableItems->currentRow();
        vectorItems.remove(currentRow);
        ui->tableItems->removeRow(ui->tableItems->currentRow());
    } else {
        msgBox.close();
    }
}
//обработка кнопки "Отмена" при редактировании/добавлении записи
void MainWindow::on_pbCancel_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit->setEnabled(0);
    ui->pbAdd->hide();
    ui->pbSave->hide();
    ui->pbDelete->hide();
    ui->pbCancel->hide();
    ui->labelAdd->hide();

}
//реализация поиска по наименованию по части строки
void MainWindow::on_lineName_textChanged(const QString &str)
{
    if (ui->lineName->text()== "") {
        ui->tableItems->setCurrentCell(0,0);
        ui->tableItems->clearSelection();
    }
    QTableWidgetItem *item;
    QList<QTableWidgetItem*> found = ui->tableItems->findItems(str, Qt::MatchContains);
    foreach (item, found)
    {
       if (item->column()==0)
       {
       ui->tableItems->clearSelection();
       ui->tableItems->setItemSelected(item, true);
       ui->tableItems->setCurrentCell(item->row(),item->column());
       break;
       }
    }
}
//реализация поиска по идентификатору по части строки
void MainWindow::on_lineID_textChanged(const QString &str)
{
    if (ui->lineName->text()== "") {
        ui->tableItems->setCurrentCell(0,1);
        ui->tableItems->clearSelection();
    }
    QTableWidgetItem *item;
    QList<QTableWidgetItem*> found = ui->tableItems->findItems(str, Qt::MatchContains);
    foreach (item, found)
    {
       if (item->column()==1)
       {
       ui->tableItems->clearSelection();
       ui->tableItems->setItemSelected(item, true);
       ui->tableItems->setCurrentCell(item->row(),item->column());
       break;
       }
    }
}
//функция для отправки имени элемента вектора с заданным индексом
QString MainWindow::send_vector_name(int i) {
    return vectorItems[i].get_name();
}
//функция для отправки идентификатора элемента вектора с заданным индексом
QString MainWindow::send_vector_id(int i) {
    return vectorItems[i].get_id();
}


