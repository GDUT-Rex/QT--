#include "login2.h"
#include "ui_login2.h"
#include <QMessageBox>
#include"adddata.h"
login2::login2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login2)
{

    ui->setupUi(this);
}

login2::~login2()
{
    delete ui;
}

void login2::on_close_clicked()
{
    accept();
}

void login2::on_login_clicked()
{
    if(ui->password->text()==tr("")){
        addData ad;
        ad.exec();

    }else{
        QMessageBox::warning(this,
                tr("您配吗？"),
                tr("您配吗？"),
                   QMessageBox::Yes);

        //清楚内容
        ui->password->clear();
    }


}
