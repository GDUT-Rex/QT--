#ifndef ADDPOINT_H
#define ADDPOINT_H

#include <QDialog>

namespace Ui {
class addPoint;
}

class addPoint : public QDialog
{
    Q_OBJECT

public:
    explicit addPoint(QWidget *parent = 0);
    ~addPoint();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::addPoint *ui;
};

#endif // ADDPOINT_H
