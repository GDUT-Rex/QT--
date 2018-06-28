#include "mainmenu.h"
#include "ui_mainmenu.h"
#include"navigation.h"
#include"adddata.h"
#include"QDebug"
#include"search.h"
#include"login2.h"
MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
}

MainMenu::~MainMenu()
{
    delete ui;
}

void MainMenu::on_navgation_clicked()
{
    //导航键

    //close();
    navigation nav;
    //if(nav.exec()==QDialog::Accepted){
          nav.exec();
     //  }
}


void MainMenu::on_manage_clicked()
{

    close();
    login2 login;
    if(login.exec()==QDialog::Accepted){
     show();
    }

}
