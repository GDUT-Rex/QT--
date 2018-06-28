#include "deletroad.h"
#include "ui_deletroad.h"
#include"QMessageBox"
#include"QFile"
#include"QTextStream"
#include"mainmenu.h"
deletroad::deletroad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::deletroad)
{
    ui->setupUi(this);
    ui->start->setValidator(new QIntValidator(0,1000,this));//限制只能输入数字
    ui->final_2->setValidator(new QIntValidator(0,1000,this));//限制只能输入数字
}

deletroad::~deletroad()
{
    delete ui;
}

void deletroad::on_pushButton_2_clicked()
{
    close();
  //  MainMenu a;
  //  a.exec();
}

void deletroad::on_pushButton_clicked()
{
    if(ui->start->text()==""||ui->final_2->text()==""){
        QMessageBox::information(
                    this,
                    tr("您配吗"),tr("您配吗"),QMessageBox::Yes
                    );
    }else{
        //读取lineedit
        int start=ui->start->text().toInt();
        int final=ui->final_2->text().toInt();
        QFile file("road.txt");
        if(!file.open(QFile::ReadWrite|QFile::Text)){
            QMessageBox::information(
                        this,
                        tr("文件不存在"),tr("您配吗"),QMessageBox::Yes
                        );
        }else	{
            //打开文件
            bool isChange=false;//是否修改过的bool值
            QTextStream stream(&file);
            QString line_in;
            QList<QString> list;
            line_in=stream.readAll();
            list=line_in.split('\n');//分割行数
            int index=list.length();//行数
            if(index==0){//为0不操作
                file.close();
                QMessageBox::information(
                            this,
                            tr("道路不存在"),tr("您配吗"),QMessageBox::Yes
                            );
                return;
            }
            else{

                file.resize(0);//清空
                for(int n=0;n<index;n++){
                    bool flag1=false;//第一端点是否存在bool
                    bool flag2=false;//第二端点是否存在bool
                    QList<QString> l = list.at(n).split(' ');
                    if(l.at(0).toInt()==start||l.at(1).toInt()==start){ flag1=true;}//如果符合第一端点
                    if(l.at(0).toInt()==final||l.at(1).toInt()==final){ flag2=true;}//如果符合第二端点
                    if(flag1&&flag2)//同时2个端点存在
                    {
                        //删除数据
                         isChange=true;
                    }else{//不匹配写入
                         stream<<list.at(n);
                         if(n<index-1)//最后一行不换行
                         stream<<"\n";
                    }
                }
            }
            //判断是否改变了文件
            if(isChange){
                QMessageBox::information(
                            this,
                            tr("改变成功"),tr("改变成功"),QMessageBox::Yes
                            );
            }
            else{
                QMessageBox::information(
                            this,
                            tr("道路不存在"),tr("您配吗"),QMessageBox::Yes
                            );
            }
        }
        file.close();
    }
    close();
   // MainMenu a;
   // a.exec();
}
