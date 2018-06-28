#include "modify_kind.h"
#include "ui_modify_kind.h"

#include"modify.h"

modify_kind::modify_kind(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_kind)
{
    ui->setupUi(this);
}

modify_kind::~modify_kind()
{
    delete ui;
}

void modify_kind::on_pushButton_3_clicked()
{
    close();

}

void modify_kind::on_pushButton_2_clicked()
{
    modify m;
    m.exec();
}
