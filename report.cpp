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



