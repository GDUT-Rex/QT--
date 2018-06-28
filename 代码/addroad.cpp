#include "addroad.h"
#include "ui_addroad.h"
#include"qdebug.h"
#include"QFile"
#include"QMessageBox"
#include"QString"
#include"QList"
#include"mainmenu.h"
addRoad::addRoad(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addRoad)
{
    ui->setupUi(this);
    ui->distance->setValidator(new QIntValidator(0, 1000, this));
    ui->point_1->setValidator(new QIntValidator(0, 1000, this));
    ui->point_2->setValidator(new QIntValidator(0, 1000, this));
    ui->type->setValidator(new QIntValidator(0, 1000, this));
}

addRoad::~addRoad()
{
    delete ui;
}
//取消按钮
void addRoad::on_pushButton_2_clicked()
{
    close();
}

void addRoad::on_add_clicked()
{
    int point1=ui->point_1->text().toInt(),
        point2=ui->point_2->text().toInt(),
        distance=ui->distance->text().toInt(),
        type=ui->type->text().toInt()
        ;


    QFile file("road.txt");

    if(!file.open(QFile::ReadWrite|QFile::Text)){
                QMessageBox::information(this,
                        tr("您配吗？"),
                        tr("file打开失败"),
                           QMessageBox::Yes);
   }else{
   //打开成功
    QTextStream stream(&file);
    QString str =stream.readAll();
    QList<QString> list = str.split('\n');

    ///判断每一行
    bool flag1,flag2;
    flag1=flag2=false;//道路相同的bool
    for(int k=0;k<list.length();k++){
        QList<QString> lst_str=list.at(k).split(" ");//分割每一行
        //2个端点是否同时符合
        if(lst_str.at(0).toInt()==point1||lst_str.at(1).toInt()==point1) flag1=true;
        if(lst_str.at(0).toInt()==point2||lst_str.at(1).toInt()==point2) flag2=true;
        if(flag1&&flag2)break;//重复终止循环
        flag1=flag2=false;
    }
    if(flag1&&flag2)//出现重复
    {
        QMessageBox::information(this,
                tr("您配吗？"),
                tr("道路重复？"),
                   QMessageBox::Yes);

    }else{
        QFile file2("point.txt");//判断顶点
        bool f1=false;
        bool f2=false;
        file2.open(QFile::ReadOnly|QFile::Text);
        QTextStream stream1(&file2);
        QString str = stream1.readAll();//分割每一行
        QList<QString> list =str.split('\n');
        qDebug()<<str;
        for(int k=0;k<list.length();k++){
            QList<QString> list2 = list.at(k).split(" ");
            //阅读每一行第一个
              qDebug()<<k;
            if(list2.at(0).toInt()==point1){//第一个端点
                f1=true;
               // break;
            }
            else{
                //表示不相同
            }
            if(list2.at(0).toInt()==point2){//第二个端点
                f2=true;
               // break;
            }
            else{
                //表示不相同
            }

        }
        qDebug()<<f1<<f2;
        if(f1&&f2){
            QMessageBox::information(this,"完成","你已经添加了",QMessageBox::Yes);
            stream.seek(file.size());//将当前读取文件指针移动到文件末尾
            stream<<"\n"<<point1<<' '<<point2<<' '<<distance<<' '<<type;

          }else{//存在有不存在的顶点
              QMessageBox::information(this,"失败","不可以链接不存在点",QMessageBox::Yes);
        }

        file2.close();

    }



   }

   file.close();
   close();


}
