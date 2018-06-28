#ifndef MODIFY_POINT_H
#define MODIFY_POINT_H
#include<graph.h>
#include <QDialog>
#include"QString"
namespace Ui {
class modify_point;
}

class modify_point : public QDialog
{
    Q_OBJECT

public:


    //接受信息
    void getMessage(graph g,int index);
    explicit modify_point(QWidget *parent = 0);
    ~modify_point();

private slots:
    void on_pushButton_2_clicked();

    void on_modify_clicked();

private:
    int point_index;
    Ui::modify_point *ui;
};

#endif // MODIFY_POINT_H
