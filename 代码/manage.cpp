#include "manage.h"
#include "ui_manage.h"
#include"adddata.h"
#include"modify_kind.h"
#include"navigation.h"

manage::manage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manage)
{
    //int flag=0;
    //int manage::flag=0;
    ui->setupUi(this);
}

manage::~manage()
{
    //manage::flag=1;
    delete ui;
}

void manage::on_pushButton_4_clicked()
{
    //返回键
    accept();
    close();
}


void manage::on_pushButton_clicked()
{

    addData add;
    add.exec();
}

void manage::on_pushButton_3_clicked()
{

   // int flag=1;
    navigation nav;
    nav.exec();
}
