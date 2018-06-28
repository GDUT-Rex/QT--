#include "modify.h"
#include "ui_modify.h"
#include"graph.h"
#include"QtDebug"
#include"QFile"
#include"QMessageBox"
#include"QList"
modify::modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify)
{
   //readData();
    ui->setupUi(this);
}

modify::~modify()
{
    delete ui;
}




void modify::on_pushButton_2_clicked()
{
    close();
}
