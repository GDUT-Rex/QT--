#include "navigation.h"
#include "ui_navigation.h"
#include"graph.h"
#include"QtDebug"
#include"QFile"
#include"QMessageBox"
#include<QMouseEvent>
#include<QPushButton>
#include<QSignalMapper>
#include "modify_point.h"
#include"mainmenu.h"
#include<QTextStream>
#include"search.h"

navigation::navigation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::navigation)
{
    hasSearch=false;//查找
    modify_point_int=-1;
    point_1=point_2=0;
    flag=false;
    has_click=0;
    ui->setupUi(this);
    start_nav=false;
    //初始化所有的导航高亮的点 save——point
    //最大化
    this->setWindowFlags(Qt::Dialog);
    this->showMaximized();
    nav_kind=1;//默认最短路径
    for(int i=0;i<100;i++)
        save_point[i]=-1;//-1表示无
}

navigation::~navigation()
{
    delete ui;
}
//导航
void navigation::searchpath(int num){
    int v, w, i, t;  // i、w和v为计数变量
        int final[NUM+1];
        int min;
        for (v = 0; v<NUM; v++)
        {
            final[v] = 0;  // 假设从顶点num到顶点v没有最短路径
            D[v] = assist[num][v];// 将与之相关的权值放入D中存放
            for (w = 0; w<NUM; w++) // 设置为空路径
                P[v][w] = 0;
            if (D[v]<30000)  // 存在路径
            {
                P[v][num] = 1; // 存在标志置为一
                P[v][v] = 1; // 自身到自身
            }
        }

        D[num] = 0;
        final[num] = 1;      // 初始化num顶点属于S集合
                             // 开始主循环，每一次求得num到某个顶点的最短路径，并将其加入到S集合
        for (i = 0; i<NUM; ++i)     // 其余G.vexnum-1个顶点
        {
            min = Max;     // 当前所知离顶点num的最近距离
            for (w = 0; w<NUM; ++w)
                if (!final[w])    // w顶点在v-s中
                    if (D[w]<min)   // w顶点离num顶点更近
                    {
                        v = w;
                        min = D[w];
                    }

                final[v] = 1;   // 离num顶点更近的v加入到s集合
            for (w = 0; w<NUM; ++w)  // 更新当前最短路径极其距离
                if (!final[w] && ((min + assist[v][w])<D[w]))// 不在s集合，并且比以前所找到的路径都短就更新当前路径 //
                {
                    D[w] = min + assist[v][w];
                    for (t = 0; t<NUM; t++)
                        P[w][t] = P[v][t];
                    P[w][w] = 1;
                }
        }
}
//随机拥堵
void navigation::randomcrowd()
{
    //time_t rawtime;
    //time(&rawtime);
    int ra;

    //int c = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j <100; j++)
        {
            ra = qrand() % 3 + 1;
            gra.G.arcs[i][j].crowd = ra;
            gra.G.arcs[j][i].crowd = ra;
        }
       // c++;
    }
}
void navigation::output(int target1, int target2){
    int a, b, c, d;
    a = target2;    // 将目标二赋值给a
    if (a != target1)    // 如果目标二不和目标一输入重合，则进行...
    {
        if (D[a] != 30000)
        {         
            //保存起始点到高亮数组的开头
            save_point[0]=target1;

            d = target1;      // 将目标一的编号赋值给d
            for (c = 0; c < NUM; ++c)
            {
                int k=1;
            gate:;        // 标号，可以作为goto语句跳转的位置
                P[a][target1] = 0;
                for (b = 0; b < NUM; b++)
                {
                    if (assist[d][b] < 30000 && P[a][b])  // 如果目标一和它的一个临界点之间存在路径且最短路径
                    {//得到最短路径

                        //经过的点保存到后面的数组
                        save_point[k]=b;

                        k++;
                        P[a][b] = 0;
                        d = b;
                        goto gate;
                    }
                }
            }
        }
        else
        {
            QMessageBox::warning(this,
                    tr("您配吗？"),
                    tr("找不到到达目标的道路"),
                       QMessageBox::Yes);
            qDebug() <<"找不到到达目标的道路"<< endl;
        }
    }
}
//最短路径
void navigation::shortest(){
    int v0,v1;
    v0=point_1,v1=point_2;
    //如果输入起点和结束都一样跳出
    if(v0==v1){
        QMessageBox::warning(this,
                        tr("您配吗？"),
                        tr("起点和结束点一致"),
                           QMessageBox::Yes);
    }
    qDebug()<<v0<<v1;

    for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                assist[i][j] = gra.G.arcs[i][j].distans;
            }
        }
    searchpath(v0);
    output(v0,v1);
    //高亮
    start_nav=true;

}
//金钱最少
void navigation::cheapest()//金钱最少
{
    int v0, v1;
    v0=point_1,v1=point_2;

    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (gra.G.arcs[i][j].type == 0)
            {
                assist[i][j] = 30000;
            }
            if (gra.G.arcs[i][j].type == 1)
            {
                assist[i][j] = 1;
            }
            if (gra.G.arcs[i][j].type == 2)
            {
                assist[i][j] = 50;
            }
        }
    }
    searchpath(v0);
    output(v0, v1);
     start_nav=true;
}
//经过道路最少
void navigation::lessway()
{
    int v0, v1;
    v0=point_1,v1=point_2;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (gra.G.arcs[i][j].type == 0)
            {
                assist[i][j] = Max;
            }
            else
            {
                assist[i][j] = 1;
            }
        }
    }
    searchpath(v0);
    output(v0, v1);
    start_nav=true;
}
//高速优先
void navigation::freewayfirst()
{
    int v0, v1;
     v0=point_1,v1=point_2;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (gra.G.arcs[i][j].type == 0)
            {
                assist[i][j] = Max;
            }
            if (gra.G.arcs[i][j].type == 1)
            {
                assist[i][j] = 100;
            }
            if (gra.G.arcs[i][j].type == 2)
            {
                assist[i][j] = 1;
            }
        }
    }
    searchpath(v0);
    output(v0, v1);
    start_nav=true;
}
//普通道路优先
void navigation::roadfirst()
{
    int v0, v1;
    v0=point_1,v1=point_2;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (gra.G.arcs[i][j].type == 0)
            {
                assist[i][j] = Max;
            }
            if (gra.G.arcs[i][j].type == 1)
            {
                assist[i][j] = 1;
            }
            if (gra.G.arcs[i][j].type == 2)
            {
                assist[i][j] = 100;
            }
        }
    }
    searchpath(v0);
    output(v0, v1);
    start_nav=true;
}
//人行走
void navigation::walk()
{
    int v0, v1;
    v0=point_1,v1=point_2;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (gra.G.arcs[i][j].type != 1)
            {
                assist[i][j] = 30000;
            }
            else
            {
                assist[i][j] = 1;
            }
        }
    }
    searchpath(v0);
    output(v0, v1);
    start_nav=true;
}
//避免拥堵
void navigation::fastest()
{
    randomcrowd();
    int v0, v1;
    v0=point_1,v1=point_2;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            assist[i][j] = gra.G.arcs[i][j].distans*gra.G.arcs[i][j].crowd;
        }
    }
    searchpath(v0);
    output(v0, v1);
    start_nav=true;
}


    //返回
void navigation::on_back_clicked()
{
    //返回
    accept();

}
//保存顶点数据
void navigation::saveData(QList<QString> a){
    gra.G.vexnum=a.length();//定点数
    for(int i=0;i<a.length();i++){
        //分割每一行
        QList<QString> save_list=a.at(i).split(' ');
        //顶点编号
        int inde = save_list.at(0).toInt();

         if(save_list.length()<4){//至少要4组数据
         }else{
            //顶点的所有信息
             gra.G.vex[inde].x=save_list.at(3).toInt();
             gra.G.vex[inde].y=save_list.at(4).toInt();
             gra.G.vex[inde].type=save_list.at(2).toInt();
             gra.G.vex[inde].number=inde;
             gra.G.vex[inde].name=save_list.at(1);
         }

    }
}
//保存道路数据
void navigation::saveRoad(QList<QString> a){
    gra.G.arcnum=a.length();//边数

    for(int i=0;i<a.length();i++){
        QList<QString> save_list=a.at(i).split(' ');//以空格分割每一行 保存到一个数组
        if(save_list.length()<4){}//如果小于4不输出 防止文件录入少了数据
        else{
            //保存权值 和道路的类型 双向图
            gra.G.arcs[save_list.at(0).toInt()][save_list.at(1).toInt()].distans=save_list.at(2).toInt();
            gra.G.arcs[save_list.at(1).toInt()][save_list.at(0).toInt()].distans=save_list.at(2).toInt();
            gra.G.arcs[save_list.at(0).toInt()][save_list.at(1).toInt()].type=save_list.at(3).toInt();
            gra.G.arcs[save_list.at(1).toInt()][save_list.at(0).toInt()].type=save_list.at(3).toInt();           
        }
    }
}
//打开文件
void navigation::readData(){

    QFile file("point.txt");
    QFile file2("road.txt");
    if(!file.open(QFile::ReadOnly|QFile::Text)||!file2.open(QFile::ReadOnly|QFile::Text)){//打开失败
                QMessageBox::warning(this,
                        tr("您配吗？"),
                        tr("您配吗？"),
                           QMessageBox::Yes);
   }else{
//打开成功
    QString str=file.readAll();
    QString str2=file2.readAll();
    QList<QString> list=str.split('\n');//分割每一行
    QList<QString> list2=str2.split('\n');//分割每一行
    saveData(list);//把顶点写入图
    saveRoad(list2);//把道路写入图
   }
//文件关闭
   file2.close();
   file.close();
   return  ;
}

//按键事件 导航
void navigation::nav_click(int i){
        modify_point_int=i;//保存修改的点
        //显示数据
        QString type_str;
        ui->name->setText(gra.G.vex[i].name);
        switch (gra.G.vex[i].type) {
        case 1:
            type_str="商店";
            break;
        case 2:
            type_str="酒店";
            break;
        case 3:
            type_str="饭店";
            break;
        case 4:
            type_str="道路";
        break;
        default:
            break;
        }
        //显示顶点信息
        ui->type->setText(type_str);
        ui->number->setText(QString::number(gra.G.vex[i].number,10));
        ui->x->setText(QString::number(gra.G.vex[i].x,10));
        ui->y->setText(QString::number(gra.G.vex[i].y,10));
        //点击次数 点击第二次启用导航
        if(has_click==0){//第一次 记录第一个点
            //重置保存的顶点
            for(int k=0;k<100;k++) save_point[k]=-1;
            start_nav=false;//取消刷新
            point_1=i;
            QMessageBox::information(this,
                    tr("您配吗？"),
                    tr("选取第一个地点\n%1").arg(gra.G.vex[i].name),
                       QMessageBox::Yes);
           // qDebug()<<point_1;
        }
        if(has_click==1){//记录第二个点

            point_2=i;
            has_click=-1;//重置
            modify_point_int=-1;//重置
            QMessageBox::information(this,
                    tr("您配吗？"),
                    tr("选取第二个点\n%1").arg(gra.G.vex[i].name),
                       QMessageBox::Yes);

            //判断导航类型
            switch (nav_kind) {
            case 1:
                shortest();//出发导航
                break;
            case 2:
        //最便宜
                cheapest();
                break;
            case 3:
//最少道路
                lessway();
                break;

            case 4:
//高速优先
                freewayfirst();
                break;
            case 5:
//道路优先
                roadfirst();
                break;
            case 6:
//人
                walk();
                break;
            case 7:
 //避免拥堵
                fastest();
                break;
            default:
                break;
            }//导航种类


}else{}

            has_click++;
          //qDebug()<<i<<has_click;
}
//画顶点
void navigation::drawPoint(QPainter *p,int type,int x,int y,int i){
              //按钮事件
    if(type==0)return;
        QSignalMapper *Qmap;
        Qmap =new QSignalMapper();
        QPushButton *ptb;//按钮指针
        //顶点类型
        QIcon icon("circle.png"),icon_shop("shop.png"),icon_rect("rect.png"),icon_posi("position.png");
       //添加新的按钮
        ptb =new QPushButton(this);
        //判断类型 设置按钮的图片
         switch (type) {
         case 1:
            ptb->setIcon(icon);
             break;
         case 2:
             ptb->setIcon(icon_rect);
             break;
         case 3:
             ptb->setIcon(icon_shop);
             break;
         case 4:
             ptb->setIcon(icon_posi);
             break;
         default:
             break;
         }
         //事件时间
         connect(ptb,SIGNAL(clicked()),Qmap,SLOT(map()));//连接转接器
         ptb->setIconSize(QSize(16,16));//按钮大小
         ptb->setFlat(true);//按钮是否显示
         ptb->setGeometry(x+100-8,y+100-8,16,16);//按钮位置
         ptb->setVisible(true);//按钮是否启用
         Qmap->setMapping(ptb,i);//按钮事件
        //连接按钮和按钮事件
         connect(Qmap,SIGNAL(mapped(int)),this,SLOT(nav_click(int)));

}
//画路
void navigation::drawRoad(QPainter *p,int type,int x1,int y1,int x2,int y2){
     QPen pen;
    switch (type) {
    case 1://普通道路
        pen.setColor(QColor(206,252,202));
        pen.setWidth(3);
        break;
    case 2://高速公路
        pen.setColor(QColor(206,252,202));
        pen.setWidth(6);
        break;
    case 3://高亮部分
        pen.setColor(QColor(255,255,0));
        pen.setWidth(7);
        break;
    default:

        break;
    }


    p->setPen(pen);
    p->drawLine(QPointF(x1*1+100, y1*1+100), QPointF(x2*1+100, y2*1+100));
}
void navigation:: paintEvent(QPaintEvent *){//画图函数
    QPainter painter(this);
    painter.setBrush(QColor(82,82,82));
    painter.drawRect(this->rect());
    if(!flag){//每次打开只执行一次
          flag=true;
          readData();//读取数据 并且保存到图上
          for(int i=0;i<gra.max;i++){
              if(gra.G.vex[i].type!=0){
                  //画顶点
                  drawPoint(&painter,gra.G.vex[i].type,gra.G.vex[i].x,gra.G.vex[i].y,i);
              }
          }

    };;

    int max=gra.max;
    for(int i=0;i<gra.max;i++){
       for(int j=0;j<max;j++){
           if(gra.G.arcs[i][j].type!=0){
              drawRoad(&painter,gra.G.arcs[i][j].type,gra.G.vex[i].x,gra.G.vex[i].y,gra.G.vex[j].x,gra.G.vex[j].y);
              //画道路
           }
       }
       max--;//只需要阅读一半的矩阵
   }
    //画顶点
    if(start_nav){//导航事件
        //导航高亮
        for(int i=1;i< 100;i++){    
         if(save_point[i]==-1){return;}//不存在跳出循环
         drawRoad(&painter,3,gra.G.vex[save_point[i-1]].x,gra.G.vex[save_point[i-1]].y,gra.G.vex[save_point[i]].x,gra.G.vex[save_point[i]].y);
         //画道路
        }

    }

}
//查找 接受到类型和顶点后
void navigation::searchnearby(int i)
    {
    qDebug()<<search_type;
    int x=gra.G.vex[i].x, y=gra.G.vex[i].y,type=search_type;
    int s = 0;
    QString str;
    bool hasType=false;

    for (int i = 0; i < NUM; i++)
    {
        //查找一定的距离 这个距离为以查找为圆心 半径为S的圆所有存在的顶点
        s = (gra.G.vex[i].x - x)*(gra.G.vex[i].x - x) + (gra.G.vex[i].y - y)*(gra.G.vex[i].y - y);
        if (s < 10000&& gra.G.vex[i].type==type)//如果同时满足则记录
        {         

            str.append(" ");
            str.append(gra.G.vex[i].name);
            hasType=true;//判断是否存在附近需要查找的点
        }
    }
    if(hasType)//显示附近的信息
    QMessageBox::information(this,tr("您配吗"),tr("该类型附近的点有%1").arg(str),QMessageBox::Yes);
}
//修改事件
void navigation::on_modify_clicked()
{
    if(modify_point_int==-1){
        return;
    }
    //修改
    modify_point *abs=new modify_point();
    abs->getMessage(gra,modify_point_int);//传递窗口消息 把修改的顶点编号传到新的窗口
    abs->exec();
    modify_point_int=-1;//重置
}
//返回事件
void navigation::on_pushButton_clicked()
{
   // accept();
    close();
}
//删除
void navigation::on_delet_clicked()
{
    //没有点击返回空
    if(modify_point_int==-1){
        return;
    }
    //删除定点
    QFile file("point.txt");
    if(!file.open(QFile::ReadWrite|QFile::Text)){
        QMessageBox::warning(this,
                tr("您配吗？"),
                tr("打开失败"),
                   QMessageBox::Yes);
        close();
        return;
   }else{
        QTextStream stream(&file);
         stream.setCodec("UTF-8");
        QString str=stream.readAll();
        QList<QString> list=str.split('\n');
        //分割每一行
        if(list.length()==0){
            file.close();
            return;
        }
        file.resize(0);//清空
        for(int k=0;k<list.length();k++){
            QList<QString> list_a=list.at(k).split(' ');
            //分割每一个
            if(list_a.at(0).toInt()==modify_point_int){
                //如果找到了保存的地方 不保存               
            }else{//如果不是的话就保存
                stream<<list.at(k);
                if(k<list.length()-1)stream<<"\n";//最后一行不换行
            }
        }
        file.close();
  // QWidget::update();
    }
    QFile file2("road.txt");//删除道路相关的点
    if(!file2.open(QFile::ReadWrite|QFile::Text)){
        QMessageBox::warning(this,
                tr("您配吗？"),
                tr("打开失败"),
                   QMessageBox::Yes);
        file2.close();
        close();
        return;
    }else{
        QTextStream stream(&file2);
        QString str=stream.readAll();
        QList<QString> list=str.split('\n');    //分割每一行
        file2.resize(0);//清空
        if(list.length()==0){ file2.close();return;}else{
           for(int k=0;k<list.length();k++){
               QList<QString> list_a=list.at(k).split(' ');
               //分割每一个
               if(list_a.at(0).toInt()== modify_point_int||list_a.at(1).toInt()== modify_point_int){
                   //如果找到了保存的地方 不保存
               }else{//如果不是的话就保存
                   stream<<list.at(k);
                   if(k<list.length()-1)stream<<"\n";//最后一行不换行
               }
           }
        }
    }
    file2.close();
    has_click=0;//重新点击
    //删除之后重新读数据
    QMessageBox::information(this,
            tr("您配吗？"),
            tr("你已经删除 麻烦出去 我给你画多一张图 好吧"),
               QMessageBox::Yes);
    close();
}
//导航权值修改
void navigation::on_shortest_clicked()
{
    nav_kind=1;
     if(has_click==1){//点过一次了
         point_1=-1;
          has_click=0;
          modify_point_int=-1;//重置
     }
}

void navigation::on_cheapest_clicked()
{
    nav_kind=2;
    if(has_click==1){//点过一次了
        point_1=-1;
         has_click=0;
         modify_point_int=-1;//重置
    }
}

void navigation::on_lessway_clicked()
{
     nav_kind=3;
     if(has_click==1){//点过一次了
         point_1=-1;
          has_click=0;
          modify_point_int=-1;//重置
     }
}

void navigation::on_freeway_clicked()
{
    nav_kind=4;
    if(has_click==1){//点过一次了
        point_1=-1;
         has_click=0;
         modify_point_int=-1;//重置
    }
}

void navigation::on_roadfirst_clicked()
{
    nav_kind=5;
    if(has_click==1){//点过一次了
        point_1=-1;
         has_click=0;
         modify_point_int=-1;//重置
    }
}

void navigation::on_walk_clicked()
{
    nav_kind=6;
    if(has_click==1){//点过一次了
        point_1=-1;
         has_click=0;
         modify_point_int=-1;//重置
    }
}

void navigation::on_bimianyongdu_clicked()
{
    nav_kind=7;
    if(has_click==1){//点过一次了
        point_1=-1;
         has_click=0;
         modify_point_int=-1;//重置
    }
}
//查找点击事件
void navigation::on_search_clicked()
{
    //查找
    int index;
    if(has_click==1){//点击一次
        Search *sea=new Search;
        index=point_1;
        sea->getMessage(gra,index);//传递消息到新的窗口
        connect(sea,SIGNAL(sendData(int)),this, SLOT(receiveData(int)));//连接窗口
        sea->exec();
        searchnearby(index);//从新窗口接受新的消息
    }else{
        return;
    }
}
//接受信息
 void navigation::receiveData(int data){
        search_type=data;
 }
