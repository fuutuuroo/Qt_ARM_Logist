# Автоматизированное рабочее место специалиста
<details>
    <summary>Требования к отчёту</summary>
    
- файл README.md, оформленный разметкой Markdown, со следующими разделами:
- постановка задачи;
- анализ задачи с разбором применения используемых структур данных, функций;
- скриншоты работы программы;
- диаграммы классов;
- ссылка на видеоролик с закадровыми комментариями автора, загруженный на видеохостинг и публично доступный;
- структурированный исходный код проекта с подробными комментариями;
    
</details>

## Постановка задачи
### Реализовать автоматизированное рабочее место специалиста с учётом этих требований:
- Графический интерфейс пользователя должен быть выполнен при помощи фреймворка Qt и управляться событиями.
- АРМ должен поддерживать ввод данных оператором, а также их преобразование, согласно заданному алгоритму, и вывод результатов преобразования в графический интерфейс с визуализацией (диаграммы, графики, таблицы, карты).
- Предусмотреть режим тестовой генерации событий при помощи генератора случайных чисел и/или общедоступных внешних данных.
- Если вариант предполагает использование общедоступных внешних данных (данные о погоде, курсах валют, карты), то дополнительные баллы будут начисляться за обновление данных в режиме онлайн.
- Если вариант предполагает АРМ оператора/диспетчера технологического процесса, то дополнительные баллы начисляются за SCADA-совместимый графический интерфейс.

## Анализ задачи 
### АРМ логиста телекоммуникационной компании

В данной программе имеется 4 класса:
- Item - хранение данных и работы с ними;
- MainWindow - отображение главного окна;
- ItemCountWindow - отображение окна с таблицей наличия товара в городах;
- Report - отображение окна с отправкой заявки.
<br>Взаимодействие с окнами и передача данных между ними реализованы с применением функций (слотов) и нажатий на кнопки (сигналов).<br>
На главном окне программы выводится таблица с помощью виджета QTableWidget. Элементы таблицы формируются на основе вектора QVector, в котором хранятся экземпляры класса Item. У них есть 2 основных поля типа QString - name и id. Наименование задаётся на основе предзаполенных элементов массива, идентификатор - составляется из восьми цифр от 0 до 9, каждая сгенерирована случайным образом с помощью QRandomGenerator. Есть возможность добавить запись в вектор и таблицу вводом данных оператором, идентификатор при этом сгенерируется автоматически, в обоих случаях выполняется проверка на уникальность значений. Также есть возможность изменить уже существующее наименование, или полностью удалить запись, при этом отображается дополнительное окно QMessageBox подтверждения намерений оператора. В верхней части главного окна расположены две строки для поиска по части строки, одна для поиска по наименованию, а вторая - по идентификатору, также таблица сортируется по нажатию на её столбцы.<br>
При двойном клике на любую ячейку таблицы откроется дополнительное окно наличия товара в городах. В нём находится таблица, первый столбец - города, второй столбец - количество товара. Названия городов заполняются на основе элементов массива, количество генерируется от 0 до 20 с помощью функции qrand в зависимости от номера нажатой строки в таблице на прошлом окне. Если количество равно 0, то в третьем столбце таблицы в той же строке ячейка окрашивается в жёлтый цвет и появляется надпись "Заявка". <br>
По нажатию на такую ячейку открывается ещё одно окно для отправки заявки в отдел закупки для устранения нехватки этого товраа. В нём отображаются наименование товара и его идентификатор, строка для ввода необходимого количества товара, кнопки отправки и закрытия. 
## Скриншоты работы программы
Рисунок 1 - Главное окно при открытии программы<br>
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/2f187715-f475-48ee-a841-89e28e6a49c0)
<br>Рисунок 2 - Главное окно при редактировании записи<br>
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/c01ccff9-3152-497d-ba32-900a7e21036b)
<br>Рисунок 3 - Главное окно при добавлении записи<br>
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/bf27063d-a50b-4823-8e9c-6a1dcfee6cfd)
<br>Рисунок 4 - Открытое окно наличия товара в городах<br>
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/7d7e3e3e-8484-4649-9be6-186d5a52af91)
<br>Рисунок 5 - Открытое окно создания заявки в отдел закупки после введённого значения<br>
![image](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/ba14d2f5-1a32-4ab9-8ab3-62870d281d0e)

## Диаграмма классов
![ARM_Logist](https://github.com/fuutuuroo/Qt_ARM_Logist/assets/85291734/5dd0580c-10e7-403e-8697-c717c5f09a18)

## Ссылка на видеоролик 
[Qt Study Project - Logist - Solodov A.A.](https://youtu.be/O6twRPTyJvU)

## Cтруктурированный исходный код проекта с подробными комментариями
### Заголовочные файлы

<details>
    <summary>item.h</summary>
    
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

    QVector<Item> set_vector_of_items();

};

#endif // ITEM_H
```

</details>
<details>
    <summary>mainwindow.h</summary>
    
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
    
</details>
<details>
    <summary>itemcountwindow.h</summary>

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
    report *reportWind;
    void addReport();
    int get_rand_count(int, int, int);

};

#endif // ITEMCOUNTWINDOW_H
```

</details>
<details>
    <summary>report.h</summary>    

```C++
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
    QString reportCity;
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
    
</details>
    
### Исходные файлы
    
<details>
    <summary>main.cpp</summary>    

```C++
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
```

</details>
<details>
    <summary>item.cpp</summary>    

```C++
#include "item.h"

Item::Item() {}

Item::~Item() {}

QString Item::get_name() {
    return name;
}
QString Item::get_id() {
    return id;
}

void Item::set_name(QString str) {
    name = str;
}

void Item::set_id(QString str) {
    id = str;
}
//функция для получения рандомного идентификатора, тип QString выбран для того, чтобы было ровно 8 цифр
QString Item::rand_id() {
    QRandomGenerator *rand = QRandomGenerator::global();
    for (int i=0; i < 10; i++){
            rand->bounded(0,9);
    }
    QString digits[10] = { "0","1","2","3","4","5","6","7","8","9"};
    QString res =   digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)]+
                    digits[rand->bounded(0,9)] + digits[rand->bounded(0,9)];
    return res;
}
//массив с названиями оборудования
QString names[128] = {  "IP-телефон Avaya 1608", "IP-телефон Cisco CP-6901",
                        "IP-телефон Grandstream GXP2100", "IP-телефон Yealink SIP-T27G",
                        "Абонентский терминал InfiNet Smc/54.300.2x63.2x21-ODU", "Абонентский терминал GPON Dasan H645B",
                        "Адаптер POE Ubiquiti POE-24-24W", "Адаптер SNMP Powercom NetAgent II (BT506)",
                        "Аккумуляторная батарея Delta HRL 12-34W (12V 9Ah)", "Блок питания Juniper PWR-MX480-2400-DC-S",
                        "Блок питания Vermax-PS2U/AC", "Блок 8 розеток 19\"",
                        "Брандмауэр Cisco ASA 5525-X", "Видеокамера OMNY M64E 2812",
                        "Видеокамера Satvision SVI-D222-N", "Внешний радиоблок Ceragon IP-20C-E-18-L-H-ESS",
                        "Внешний радиоблок Siklu EH-2500FX-ODU-L-EXT", "Внутрений блок Ceragon FibeAir IP10-N-N",
                        "Делитель оптический 2*16", "Делитель оптический 1*4",
                        "ИБП APC Smart-UPS XL 2200 (SUA2200XLI)", "ИБП Inelt Monolith II 3000RMLT",
                        "ИБП SNR-UPS-ONRM-1500-X36", "Инжектор PoE Cambium ePMP 1000",
                        "Инжектор POE Powertone PI-600-1", "Кабель FTP 4 пары, кат. 5, для внешней прокладки",
                        "Кабель ВВГнг 3*10", "Кабель коаксиальный типа RG-11",
                        "Кабель оптический 128-волоконный 15 кН", "Кабель оптический 4-волоконный 2,7 кН, для внутренней прокладки",
                        "Кабельная сборка (RP-SMA male-RP-SMA female), 2м", "Коммутатор D-Link DGS-1008D",
                        "Коммутатор Allied Telesis AT-8000S/48", "Коммутатор Beward STW-16P8",
                        "Коммутатор Cisco Linksys SRW2016", "Коммутатор Cisco WS-C2950G-24-EI",
                        "Коммутатор Cisco WS-C2960S-48FPS-L", "Коммутатор Cisco WS-C2960-48PST-L",
                        "Коммутатор Cisco WS-C3524-XL-EN", "Коммутатор Cisco WS-C3750G-48TS-S",
                        "Коммутатор Cisco WS-C3560G-48PS-S", "Коммутатор TP-Link T2600G-28TS V4 DC",
                        "Коммутатор D-Link DES-1228ME", "Коммутатор D-Link DES-3200-52",
                        "Коммутатор D-Link DGS-1210-28XS/ME/B1", "Коммутатор D-Link DGS-3120-24TC",
                        "Коммутатор D-Link DXS-1210-12SC", "Коммутатор Eltex MES2324B",
                        "Коммутатор Eltex MES5248", "Коммутатор Extreme Summit X450-24x",
                        "Коммутатор Extreme Summit X670V-48x", "Коммутатор HP 1920-48G",
                        "Коммутатор Huawei S5320-28P-LI-AC", "Коммутатор Huawei S6320-54C-EI-48S-DC",
                        "Кросс оптический КРС-144-LC", "Кросс оптический ШКОН-4-SC",
                        "Маршрутизатор Cisco 2610", "Маршрутизатор Cisco 2811",
                        "Маршрутизатор Cisco 7603-S", "Маршрутизатор Ubiquiti EdgePoint-R8",
                        "Маршрутизатор D-Link DIR-100", "Маршрутизатор Eltex ESR-100",
                        "Маршрутизатор Juniper SRX210B", "Маршрутизатор Juniper MX150-R",
                        "Маршрутизатор Mikrotik hEX RB750Gr3", "Маршрутизатор Mikrotik CCR1009-8G-1S",
                        "Модем CDMA Skylink Airplus MCD-800", "Модем D-Link DSL-2500U",
                        "Модем GSM Teleofis RX 101-R4", "Модем Zyxel P-792H",
                        "Модуль Cisco VWIC2-1MFT-G703", "Модуль Juniper ES2-4GS1-MOD",
                        "Модуль компенсации дисперсии Huawei DCM-F (120км)", "Модуль питания Mean Well RCP-1000-48",
                        "Модуль управления Huawei TMF1SCC OSN9800", "Модуль-мультиплексор Qtech QBM-P2M1D6R1 v3",
                        "Мультиплексор ECI RBM 2004+E", "Мультиплексор SDH Huawei Optix 155/622H",
                        "Муфта оптическая МТОК-6/108", "Муфта-кросс оптическая 20/20-SC, 1 делитель 1*8",
                        "Оконечная станция InfiNet Mmxt/6.300.2x200.2x24-ODU", "Оконечная станция Ubiquiti AirFiber 24 HD",
                        "Патч-корд RJ45-RJ45 1,0 м", "Передатчик оптический Volius VS-5711",
                        "Переключатель KVM TRENDnet TK-EX2", "Переходник Ubiquiti airFiber Antenna Conversion Kit",
                        "Плата Alcatel-Lucent LKA1D ADM 16/1", "Плата Avaya TN771DP",
                        "Плата Ericsson ROJ 207 030/2 (RPBI-S)", "Плата Huawei FVPD (UMG8900)",
                        "Плата Nortel NTDK20KA", "Плата Samsung KP70D-BRG2/RUA",
                        "Преобразователь MOXA NPort 5630-16", "Приемник оптический FOROtel SHO 212A",
                        "Приемник оптический Vector Lambda Pro 51", "Приемник оптический Volius VS5793",
                        "Приемник цифровой PBI DCH-3100P-10S2", "Радиоблок Ceragon IP-20S-13-266A-5W8-TL-ESS",
                        "Радиоблок DragonWave Harmony Enhanced T562RL13B01S0.00", "Рефлектометр оптический KIWI-7212",
                        "Радиоблок E-Band E-Link Eagle EP Low", "Радиоблок Intracom UltraLink-FX80 (TDD)",
                        "Радиомост Ubiquiti GigaBeam Plus 60 GHz", "Система Wi-Fi Mesh Tenda MW3-3",
                        "Сектор базовой станции Cambium PMP-450m (Medusa)", "Сектор базовой станции InfiNet O/5.3-18-ODU",
                        "Система эл/питания Eltek FlatPack 2 48V 16kw 19\" 6U", "Система эл/питания Delta DPS 1600-48-4 6,4kw",
                        "Стойка каркасная(двухрамная) 19\" 54U", "Стойка 19\" 42U",
                        "Термошкаф ТШ-2", "Точка доступа MikroTik mANTBox 15s (RB921GS-5HPacD-15S)",
                        "Точка доступа Mikrotik SXT SA5 (RBSXTG-5HPnD-SAr2)", "Точка доступа Wi-Fi D-Link DAP-3690",
                        "Точка доступа Wi-Fi Huawei AP7050DE", "Точка доступа Wi-Fi Ruckus ZoneFlex 7762",
                        "Точка доступа Wi-Fi Ubiquiti UniFi AP Outdoor (UAP-Outdoor5)", "Усилитель UpNet EA62129 (18дБм*8п) 2AC",
                        "Усилитель оптический Huawei TN12OAU101 (20-31 дБ)", "Усилитель оптический TVBS EDFA1550HQ-33",
                        "Усилитель оптический Volius VS-5752", "Усилитель оптический Тарос EAU-800/16-C2-220-II",
                        "Шкаф напольный 19\" 24U 600*900", "Шкаф напольный 19\" 42U 800*1000",
                        "Шлюз D-Link DVG-2016S", "Шлюз TDM Зелакс (MM-116M-8E1-T-UPR)",
                        "Шнур оптический монтажный SM-3.0-SC/UPC-01.0", "Ящик телекоммуникационный пластиковый"};

//функция для получения размера массива с оборудованием, размер вектора изначально будет такой же
int Item::get_size() {
    return (sizeof(names) / sizeof(names[0]));
}
//функция для создания вектора для хранения Item'ов
QVector<Item> Item::set_vector_of_items() {
    QVector<Item> vectorItems;
    Item temp;
    for (int i = 0; i < get_size(); i++) {              //сначала инициализируем пустыми объектами
        vectorItems.append(temp);
    }
    for (int i = 0; i < vectorItems.size(); i++) {      //далее заполняем значениями
        vectorItems[i].name = names[i];
        vectorItems[i].id = rand_id();
    }
    return vectorItems;
}
```
    
</details>
<details>
    <summary>mainwindow.cpp</summary> 

```C++
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
    if (!check_name && res == QMessageBox::Ok && ui->lineEdit->text() != "") {
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
```
    
</details>
<details>
    <summary>itemcountwindow.cpp</summary> 

```C++
#include "itemcountwindow.h"
#include "ui_itemcountwindow.h"
#include "item.h"

ItemCountWindow::ItemCountWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemCountWindow)
{
    ui->setupUi(this);
    setWindowTitle("Наличие товара в городах");
}

ItemCountWindow::~ItemCountWindow()
{
    delete ui;
}

void ItemCountWindow::on_pushButtonClose_clicked()
{
    close();
}
//массив с названиями городов, которые будут записаны в первый столбец таблицы
QString towns[32] = {   "Москва", "Санкт-Петербург", "Новосибирск", "Екатеринбург",
                        "Казань", "Нижний Новгород", "Челябинск", "Омск",
                        "Краснодар", "Ростов-на-Дону", "Уфа", "Красноярск",
                        "Пермь", "Воронеж", "Волгорад", "Самара",
                        "Саратов", "Тюмень", "Тольятти", "Ижевск",
                        "Барнаул", "Иркутск", "Ульяновск", "Хабаровск",
                        "Ярославль", "Владивосток", "Томск", "Оренбург",
                        "Кемерово", "Новокузнецк", "Рязань", "Астрахань"
                    };
//функция для получения рандомного количества в городах, зависит от сида, в его роли выступит номер строки таблицы
int ItemCountWindow::get_rand_count(int seed, int min, int max) {
    qsrand(seed);
    return (qrand() % ((max + 1) - min) + min);
}

//функция для заполнения таблицы наличия в городах
void ItemCountWindow::fillTableCount(int row) {
    int sizeTowns = sizeof(towns) / sizeof (towns[0]);
    ui->tableItemCount->setRowCount(sizeTowns);
    ui->tableItemCount->setColumnCount(3);
    ui->tableItemCount->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableItemCount->setHorizontalHeaderLabels(QStringList() << "Город" << "Количество" << "Заявка");
    ui->tableItemCount->setSortingEnabled(true);    //включение возможноости сортировки таблицы
    ui->labelName->setText(vectorName);

    for (int i = 0; i < sizeTowns; i++) {
        ui->tableItemCount->setItem(i, 0, new QTableWidgetItem(towns[i]));
        //заполнение столбца "Количество" псевдослучайными числами с зависимостью от номера строки
        ui->tableItemCount->setItem(i, 1, new QTableWidgetItem(QString::number(get_rand_count(row + i,0,20))));
    }
    addReport();
}
//функция для добавления данных в третий столбец "Заявка"
void ItemCountWindow::addReport() {
    for (int i = 0; i < ui->tableItemCount->rowCount(); i++) {
        QString str;
        QTableWidgetItem *item = ui->tableItemCount->item(i, 1);
        //взятие содержимого каждой ячейки столбца "Количество" и проверка на корректность
        if (NULL != item) {
           str = item->text();
        }
        //если во втором столбце встретился 0, то заполняем соседнюю ячейку
        if (str == "0") {
            ui->tableItemCount->setItem(i, 2, new QTableWidgetItem("Создать заявку"));
            ui->tableItemCount->item(i, 2)->setBackgroundColor(QColor("yellow"));
        }
    }
}
//обработка клика на ячейку таблицы
void ItemCountWindow::on_tableItemCount_cellClicked(int row, int column)
{
    QString str;
    QTableWidgetItem *item = ui->tableItemCount->item(row, column);
    //взятие содержимого кликнутой ячейки и проверка на корректность
    if (NULL != item) {
       str = item->text();
    }
    //если это измененная ячейка третьего столбца, то открывается новое окно с заявкой
    if (str == "Создать заявку") {
        reportWind = new report(this);
        QString str;                            //строка для передачи города в окно report
        QTableWidgetItem *item = ui->tableItemCount->item(row, 0);
        if (NULL != item) {
           str = item->text();
        }
        reportWind->reportCity = str;
        reportWind->reportName = vectorName;
        reportWind->reportID = vectorID;
        reportWind->setInfo();
        reportWind->show();
    }
}
```
    
</details>
<details>
    <summary>report.cpp</summary>

```C++
#include "report.h"
#include "ui_report.h"

report::report(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::report)
{
    ui->setupUi(this);
}

report::~report()
{
    delete ui;
}
void report::on_pushClose_clicked()     //кнопка закрытия
{
    close();
}
//функция для записи информации в лэйблы
void report::setInfo() {
    ui->labelCity->setText(reportCity);
    ui->labelName->setText(reportName);
    ui->labelID->setText("id: " + reportID);
}
//кнопка отправки
void report::on_pushSend_clicked()
{
    if (ui->lineEditCount->text() != "") {
        QMessageBox::information(this, "Информация", "Заявка была успешно отправлена!");
        close();
    } else {
        QMessageBox::critical(this, "Пустая строка", "Введите корректное количество товара!");
    }
}
```
    
</details>
    
### Формы
    
<details>
    <summary>mainwindow.ui</summary>

```html
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>MainWindow</class>
 <widget class="QMainWindow" name="MainWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>700</width>
    <height>1000</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>MainWindow</string>
  </property>
  <widget class="QWidget" name="centralwidget">
   <layout class="QVBoxLayout" name="verticalLayout_4">
    <item>
     <layout class="QHBoxLayout" name="horizontalLayout_2">
      <item>
       <layout class="QVBoxLayout" name="verticalLayout_2">
        <item>
         <widget class="QLabel" name="labelName">
          <property name="font">
           <font>
            <pointsize>10</pointsize>
           </font>
          </property>
          <property name="text">
           <string>Поиск по наименованию</string>
          </property>
         </widget>
        </item>
        <item>
         <widget class="QLineEdit" name="lineName"/>
        </item>
       </layout>
      </item>
      <item>
       <layout class="QVBoxLayout" name="verticalLayout_3">
        <item>
         <widget class="QLabel" name="labelID">
          <property name="font">
           <font>
            <pointsize>10</pointsize>
           </font>
          </property>
          <property name="text">
           <string>Поиск по идентификатору</string>
          </property>
         </widget>
        </item>
        <item>
         <widget class="QLineEdit" name="lineID">
          <property name="text">
           <string/>
          </property>
         </widget>
        </item>
       </layout>
      </item>
     </layout>
    </item>
    <item>
     <layout class="QVBoxLayout" name="verticalLayout">
      <item>
       <spacer name="verticalSpacer">
        <property name="orientation">
         <enum>Qt::Vertical</enum>
        </property>
        <property name="sizeType">
         <enum>QSizePolicy::Fixed</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>253</width>
          <height>22</height>
         </size>
        </property>
       </spacer>
      </item>
      <item>
       <widget class="QTableWidget" name="tableItems"/>
      </item>
      <item>
       <spacer name="verticalSpacer_2">
        <property name="orientation">
         <enum>Qt::Vertical</enum>
        </property>
        <property name="sizeType">
         <enum>QSizePolicy::Fixed</enum>
        </property>
        <property name="sizeHint" stdset="0">
         <size>
          <width>253</width>
          <height>22</height>
         </size>
        </property>
       </spacer>
      </item>
     </layout>
    </item>
    <item>
     <layout class="QHBoxLayout" name="horizontalLayout">
      <item>
       <widget class="QPushButton" name="pushButtonOpen">
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Открыть запись</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="pushButtonEdit">
        <property name="enabled">
         <bool>true</bool>
        </property>
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Редактировать запись</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="pushButtonAdd">
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Добавить запись</string>
        </property>
       </widget>
      </item>
     </layout>
    </item>
    <item>
     <spacer name="verticalSpacer_3">
      <property name="orientation">
       <enum>Qt::Vertical</enum>
      </property>
      <property name="sizeType">
       <enum>QSizePolicy::Fixed</enum>
      </property>
      <property name="sizeHint" stdset="0">
       <size>
        <width>253</width>
        <height>12</height>
       </size>
      </property>
     </spacer>
    </item>
    <item>
     <widget class="QLineEdit" name="lineEdit">
      <property name="enabled">
       <bool>true</bool>
      </property>
     </widget>
    </item>
    <item>
     <widget class="QLabel" name="labelAdd">
      <property name="font">
       <font>
        <pointsize>10</pointsize>
       </font>
      </property>
      <property name="text">
       <string>Идентификатор будет сгенерирован автоматически.</string>
      </property>
     </widget>
    </item>
    <item>
     <layout class="QHBoxLayout" name="horizontalLayout_3">
      <item>
       <widget class="QPushButton" name="pbAdd">
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Добавить</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="pbSave">
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Сохранить</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="pbDelete">
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Удалить</string>
        </property>
       </widget>
      </item>
      <item>
       <widget class="QPushButton" name="pbCancel">
        <property name="enabled">
         <bool>true</bool>
        </property>
        <property name="font">
         <font>
          <pointsize>10</pointsize>
         </font>
        </property>
        <property name="text">
         <string>Отмена</string>
        </property>
       </widget>
      </item>
     </layout>
    </item>
   </layout>
  </widget>
  <widget class="QStatusBar" name="statusbar"/>
 </widget>
 <resources/>
 <connections/>
</ui>
```
    
</details>
<details>
    <summary>itemcountwindow.ui</summary>

```html
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>ItemCountWindow</class>
 <widget class="QDialog" name="ItemCountWindow">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>600</width>
    <height>900</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Dialog</string>
  </property>
  <layout class="QVBoxLayout" name="verticalLayout">
   <item>
    <widget class="QLabel" name="labelName">
     <property name="font">
      <font>
       <pointsize>16</pointsize>
      </font>
     </property>
     <property name="text">
      <string>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:16pt;&quot;&gt;Название товара&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QTableWidget" name="tableItemCount"/>
   </item>
   <item>
    <widget class="QPushButton" name="pushButtonClose">
     <property name="font">
      <font>
       <pointsize>10</pointsize>
      </font>
     </property>
     <property name="text">
      <string>Закрыть</string>
     </property>
    </widget>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>
```
    
</details>
<details>
    <summary>report.ui</summary>

```html
<?xml version="1.0" encoding="UTF-8"?>
<ui version="4.0">
 <class>report</class>
 <widget class="QDialog" name="report">
  <property name="geometry">
   <rect>
    <x>0</x>
    <y>0</y>
    <width>400</width>
    <height>300</height>
   </rect>
  </property>
  <property name="windowTitle">
   <string>Заявка</string>
  </property>
  <layout class="QVBoxLayout" name="verticalLayout">
   <item>
    <widget class="QLabel" name="labelHead">
     <property name="font">
      <font>
       <pointsize>16</pointsize>
      </font>
     </property>
     <property name="text">
      <string>&lt;html&gt;&lt;head/&gt;&lt;body&gt;&lt;p&gt;&lt;span style=&quot; font-size:20pt;&quot;&gt;Заявка в отдел закупок&lt;/span&gt;&lt;/p&gt;&lt;/body&gt;&lt;/html&gt;</string>
     </property>
    </widget>
   </item>
   <item>
    <spacer name="verticalSpacer_2">
     <property name="orientation">
      <enum>Qt::Vertical</enum>
     </property>
     <property name="sizeType">
      <enum>QSizePolicy::Fixed</enum>
     </property>
     <property name="sizeHint" stdset="0">
      <size>
       <width>20</width>
       <height>30</height>
      </size>
     </property>
    </spacer>
   </item>
   <item>
    <widget class="QLabel" name="labelCity">
     <property name="font">
      <font>
       <pointsize>14</pointsize>
      </font>
     </property>
     <property name="text">
      <string>Город</string>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QLabel" name="labelName">
     <property name="font">
      <font>
       <pointsize>14</pointsize>
      </font>
     </property>
     <property name="text">
      <string>Название</string>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QLabel" name="labelID">
     <property name="font">
      <font>
       <pointsize>14</pointsize>
      </font>
     </property>
     <property name="text">
      <string>Идентификатор</string>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QLabel" name="labelCount">
     <property name="font">
      <font>
       <pointsize>10</pointsize>
      </font>
     </property>
     <property name="text">
      <string>Введите необходимое количество предметов для закупки</string>
     </property>
    </widget>
   </item>
   <item>
    <widget class="QLineEdit" name="lineEditCount"/>
   </item>
   <item>
    <spacer name="verticalSpacer">
     <property name="orientation">
      <enum>Qt::Vertical</enum>
     </property>
     <property name="sizeType">
      <enum>QSizePolicy::Fixed</enum>
     </property>
     <property name="sizeHint" stdset="0">
      <size>
       <width>20</width>
       <height>40</height>
      </size>
     </property>
    </spacer>
   </item>
   <item>
    <layout class="QHBoxLayout" name="horizontalLayout">
     <item>
      <widget class="QPushButton" name="pushSend">
       <property name="font">
        <font>
         <pointsize>10</pointsize>
        </font>
       </property>
       <property name="text">
        <string>Отправить заявку</string>
       </property>
      </widget>
     </item>
     <item>
      <widget class="QPushButton" name="pushClose">
       <property name="font">
        <font>
         <pointsize>10</pointsize>
        </font>
       </property>
       <property name="text">
        <string>Закрыть</string>
       </property>
      </widget>
     </item>
    </layout>
   </item>
  </layout>
 </widget>
 <resources/>
 <connections/>
</ui>
```
    
</details>
