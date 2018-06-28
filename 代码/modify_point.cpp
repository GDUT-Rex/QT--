#include "modify_point.h"
#include "ui_modify_point.h"
#include"navigation.h"
#include"graph.h"
#include"QString"
#include"QMessageBox"
#include"QDebug"
#include"QFile"
#include"QTextStream"
#include"mainmenu.h"
modify_point::modify_point(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modify_point)
{
    ui->setupUi(this);
    //只允许改为数字
    ui->position_x_m->setValidator(new QIntValidator(0, 1000, this));
    ui->position_y_m->setValidator(new QIntValidator(0, 1000, this));
}

modify_point::~modify_point()
{
    delete ui;
}

void modify_point::on_pushButton_2_clicked()
{
    close();
    //MainMenu ma;
   // ma.exec();
}
void modify_point::getMessage(graph g,int a){
    //接受数据开始修改
    ui->name->setText(g.G.vex[a].name);
    ui->position_x->setText(QString::number(g.G.vex[a].x));
    ui->position_y->setText(QString::number(g.G.vex[a].y));
    ui->type_d->setText(QString::number(g.G.vex[a].type));
    point_index=a;
}
void modify_point::on_modify_clicked()
{
    //确认修改
    //判读输入数字
    if(ui->position_x_m->text()==""||ui->position_y->text()==""||ui->name_m->text()==""||ui->type_2->text()==""){
        QMessageBox::warning(this,
                        tr("您配吗？"),
                        tr("请输入数据"),
                           QMessageBox::Yes);
    }else{
        //修改文件
        QFile file("point.txt");
        if(!file.open(QFile::ReadWrite|QFile::Text)){
            //打开失败
            QMessageBox::warning(this,
                            tr("您配吗？"),
                            tr("打开失败"),
                               QMessageBox::Yes);
        }else{

            QTextStream stream(&file);
             stream.setCodec("UTF-8");
            QString str = stream.readAll();
            QList<QString> list=str.split('\n');
            file.resize(0);//清空文件
            for(int i=0;i<list.length();i++){
                QList<QString> list_a = list.at(i).split(' ');
                qDebug()<<" "<<point_index<<list_a.at(0).toInt();
                if(point_index == list_a.at(0).toInt())//找到对应的信息 修改
                {
                   //找到对应的数据位置 将用户修改的数据写入
                    stream<<point_index<<" "<<ui->name_m->text()<<" "<<ui->type_2->text()<<" "<<ui->position_x_m->text()<<" "<<ui->position_y_m->text();
                }else
                {  //不相关的数据写入txt保存
                    stream<<list.at(i);
                }
                if(i!=list.length()-1)
                stream<<"\n";
            }//结束
            file.close();
            QMessageBox::warning(this,
                            tr("您配吗？"),
                            tr("修改成功"),
                               QMessageBox::Yes);
            close();
        }
    }
}
