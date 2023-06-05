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
