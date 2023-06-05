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
