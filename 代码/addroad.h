#ifndef ADDROAD_H
#define ADDROAD_H

#include <QDialog>

namespace Ui {
class addRoad;
}

class addRoad : public QDialog
{
    Q_OBJECT

public:
    explicit addRoad(QWidget *parent = 0);
    ~addRoad();

private slots:
    void on_pushButton_2_clicked();

    void on_add_clicked();

private:
    Ui::addRoad *ui;
};

#endif // ADDROAD_H
