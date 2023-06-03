- файл README.md, оформленный разметкой Markdown, со следующими разделами:
- постановка задачи;
- анализ задачи с разбором применения используемых структур данных, функций;
- скриншоты работы программы;
- диаграммы классов;
- визуализация решения;
- ссылка на видеоролик с закадровыми комментариями автора, загруженный на видеохостинг и публично доступный;
- структурированный исходный код проекта с подробными комментариями;

# Постановка задачи
- Графический интерфейс пользователя должен быть выполнен при помощи фреймворка Qt и управляться событиями.
- АРМ должен поддерживать ввод данных оператором, а также их преобразование, согласно заданному алгоритму, и вывод результатов преобразования в графический интерфейс с визуализацией (диаграммы, графики, таблицы, карты).
- Предусмотреть режим тестовой генерации событий при помощи генератора случайных чисел и/или общедоступных внешних данных.
- Если вариант предполагает использование общедоступных внешних данных (данные о погоде, курсах валют, карты), то дополнительные баллы будут начисляться за обновление данных в режиме онлайн.
- Если вариант предполагает АРМ оператора/диспетчера технологического процесса, то дополнительные баллы начисляются за SCADA-совместимый графический интерфейс.
# Анализ задачи 
### АРМ логиста телекоммуникационной компании
На главном экране приложения выводится таблица, элементы которой формируются на основе вектора, в котором хранятся экземпляры класса Item. У них есть 2 основных поля типа QString - name и id. Наименование задаётся на основе элементов массива, идентификатор - составляется из 8 цифр от 0 до 9, каждая сгенерирована случайным образом с помощью QRandomGenerator. Есть возможность добавить запись в вектор и таблицу вводом данных оператором, идентификатор при этом сгенерируется автоматически, в обоих случаях выполняется проверка на уникальность значений. Есть возможность изменить уже существующее наименование, или полностью удалить запись, при этом отображается дополнительное окно подтверждения намерений оператора. В верхней части главного окна расположены две строки для поиска по части строки, одна для поиска по наименованию, а вторая - по идентификатору, также таблица сортируется порядку по нажатию на её столбцы. При двойном клике на любую ячейку таблицы откроется дополнительное окно наличия товара в городах. В нём находится таблица, первый столбец - города, второй столбец - количество товара. Названия городов заполняются на основе элементов массива, количество генерируется от 0 до 20 с помощью функции qrand в зависимости от номера нажатой строки в таблице на прошлом окне. Если количество равно 0, то в третьем столбце таблицы в той же строке ячейка окрашивается в жёлтый цвет и появляется надпись "Заявка". По нажатию на такую ячейку открывается ещё одно окно для отправки заявки в отдел закупки для устранения нехватки этого товраа. В нём отображаются наименование товара и его идентификатор, строка для ввода необходимого количества товара, кнопки отправки и закрытия. В данной программе имеется 4 класса - 3 для работы с отображаемыми окнами, и один хранения данных и работы с ними. Взаимодействие с окнами и передача данных между ними реализованы с применением функций (слотов) и нажатий на кнопки (сигналов).
# Скриншоты работы программы
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/2f187715-f475-48ee-a841-89e28e6a49c0)
главное окно
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/c01ccff9-3152-497d-ba32-900a7e21036b)
главное окно при редактировании записи
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/bf27063d-a50b-4823-8e9c-6a1dcfee6cfd)
главное окно при добавлении записи
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/7d7e3e3e-8484-4649-9be6-186d5a52af91)
открытое окно наличия товара в городах
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/ba14d2f5-1a32-4ab9-8ab3-62870d281d0e)
открытое окно создания заявки в отдел закупки после введённого значения
# Диаграмма классов
проверяется
# Визуализация решения
не понятно
# Ссылка на видеоролик 
будет позже
# Cтруктурированный исходный код проекта с подробными комментариями
item.h
```C++
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
```
mainwindow.h
```C++
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
```
itemcountwindow.h
```C++
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
```
report.h
```
#ifndef REPORT_H
#define REPORT_H

#include <QDialog>
#include <QMessageBox>


namespace Ui {
class report;
}

class report : public QDialog
{
    Q_OBJECT

public:
    explicit report(QWidget *parent = nullptr);
    ~report();
    QString reportName;
    QString reportID;
    void setInfo();

private slots:
    void on_pushSend_clicked();
    void on_pushClose_clicked();

private:
    Ui::report *ui;

};

#endif // REPORT_H
```
