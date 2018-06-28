#ifndef ADDDATA_H
#define ADDDATA_H

#include <QDialog>

namespace Ui {
class addData;
}

class addData : public QDialog
{
    Q_OBJECT

public:
    explicit addData(QWidget *parent = 0);
    ~addData();

private slots:
    void on_addroad_clicked();

    void on_back_clicked();

    void on_addpoint_clicked();

    void on_pushButton_clicked();

private:
    Ui::addData *ui;
};

#endif // ADDDATA_H
