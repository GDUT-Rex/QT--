#include "addpoint.h"
#include "ui_addpoint.h"
#include"qdebug.h"
#include"graph.h"
#include"QFile"
#include"QMessageBox"
#include"QString"
#include"QList"
#include"mainmenu.h"
addPoint::addPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addPoint)
{
    ui->setupUi(this);
    ui->position_x->setValidator(new QIntValidator(0, 1000, this));
    ui->position_y->setValidator(new QIntValidator(0, 1000, this));
    ui->type->setValidator(new QIntValidator(0, 1000, this));
}

addPoint::~addPoint()
{
    delete ui;
}

void addPoint::on_pushButton_2_clicked()
{
    close();
    //MainMenu a;
   // a.exec();
}

void addPoint::on_pushButton_clicked()
{
        int index,
            pos_x=ui->position_x->text().toInt(),
            pos_y=ui->position_y->text().toInt(),
            type =ui->type->text().toInt();
         QString name=ui->name->text();
         if(name=="") {
             QMessageBox::information(this,
                     tr("您配吗？"),
                     tr("您配吗？"),
                        QMessageBox::Yes);
             return;
         }
        QFile file("point.txt");
        if(!file.open(QFile::ReadWrite|QFile::Text)){
                    QMessageBox::information(this,
                            tr("您配吗？"),
                            tr("您配吗？"),
                               QMessageBox::Yes);
       }else{
       //打开成功
        QTextStream stream(&file);
        stream.setCodec("UTF-8");
        QString line_in;
        QList<QString> list1;
        line_in=stream.readAll();
       //获取行数
        list1=line_in.split('\n');
        index = list1.length();//获取行数

        bool isNotHasSame=true;//判断是否缺少顶点的bool值
        for(int k =0;k<index;k++){
             QList<QString> list_str=list1.at(k).split(" ");//分割每一行
             file.resize(0);
            //寻找是否缺少编号
            if(k!=list_str.at(0).toInt()&&isNotHasSame)
            {
                //缺少了顶点编号 自动补上
                isNotHasSame=false;//表示这次新添加的顶点添加到中间 跳出判断 后面原有的顶点继续写入文件
                stream<<k<<' '<<name<<' '<<type<<' '<<pos_x<<' '<<pos_y;
            }else{
                //没有缺少顶点编号
                stream<<list1.at(k);
            }
            if(k<index-1) stream<<"\n";//最后一行不换行
        }
          if(isNotHasSame)  stream<<"\n"<<index<<' '<<name<<' '<<type<<' '<<pos_x<<' '<<pos_y;
       }

       file.close();
       QMessageBox::information(this,"完成","你已经添加了",QMessageBox::Yes);
       close();
      // MainMenu a;
      //a.exec();

}
