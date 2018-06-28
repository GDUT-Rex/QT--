#ifndef MODIFY_H
#define MODIFY_H
#include"graph.h"
#include <QDialog>

namespace Ui {
class modify;
}

class modify : public QDialog
{
    Q_OBJECT

public:
    void show();

    explicit modify(QWidget *parent = 0);
    ~modify();

private slots:
    void on_pushButton_2_clicked();

private:
    Ui::modify *ui;
};

#endif // MODIFY_H
