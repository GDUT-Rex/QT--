#ifndef DELETROAD_H
#define DELETROAD_H

#include <QDialog>

namespace Ui {
class deletroad;
}

class deletroad : public QDialog
{
    Q_OBJECT

public:
    explicit deletroad(QWidget *parent = 0);
    ~deletroad();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::deletroad *ui;
};

#endif // DELETROAD_H
