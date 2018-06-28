#include "search.h"
#include "ui_search.h"
#include"QDebug"
Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    //ui->type->
}

Search::~Search()
{
    delete ui;
}

void Search::on_back_clicked()
{
    //返回
    close();
}
 void Search::getMessage(graph g,int index){
        qDebug()<<index;
 }

void Search::on_search_clicked()
{
     emit sendData(ui->type->text().toInt());  //获取lineEdit的输入并且传递出去
     close();
}
