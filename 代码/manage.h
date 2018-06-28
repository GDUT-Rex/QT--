#ifndef MANAGE_H
#define MANAGE_H
#include <QDialog>

namespace Ui {
class manage;
}

class manage : public QDialog
{
    Q_OBJECT

public:
   //static int flag;
    explicit manage(QWidget *parent = 0);
    ~manage();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::manage *ui;
};

#endif // MANAGE_H
