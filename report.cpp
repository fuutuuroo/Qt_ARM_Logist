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

void report::on_pushSend_clicked()      //кнопка отправки
{
    QMessageBox::information(this, "Информация", "Заявка была успешно отправлена!");
    close();
}

void report::on_pushClose_clicked()     //кнопка закрытия
{
    close();
}

void report::setInfo() {                //функция для записи информации в лэйблы
    ui->labelName->setText(reportName);
    ui->labelID->setText("id: " + reportID);
}
