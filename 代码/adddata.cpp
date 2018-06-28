#include "adddata.h"
#include "ui_adddata.h"
#include"deletroad.h"
#include"addroad.h"
#include"addpoint.h"
#include"mainmenu.h"
addData::addData(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addData)
{
    ui->setupUi(this);
}

addData::~addData()
{
    delete ui;
}
//添加道路
void addData::on_addroad_clicked()
{
    //close();
    addRoad addroad;
    addroad.exec();
    //accept();

}
//返回键
void addData::on_back_clicked()
{
    //MainMenu man;
    accept();
    // close();
   // man.exec();

}

void addData::on_addpoint_clicked()
{
    addPoint addpoint;
    addpoint.exec();
}

void addData::on_pushButton_clicked()
{
    //删除道路
   // close();
    deletroad del;
    del.exec();
}
