#ifndef NAVIGATION_H
#define NAVIGATION_H
#include<QPainter>
#include <QDialog>
#include <graph.h>
#include<QList>
#include<modify_point.h>
namespace Ui {
class navigation;
}

class navigation : public QDialog
{
    Q_OBJECT

    //传递消息
    //发生了查找高亮
    bool hasSearch;
   // modify_point *modify;
    bool flag,start_nav;
    int save_point[100];//保存导航经过的点
    int has_click;
    int point_1,point_2;
    int nav_kind;
    int search_type;
private slots:
    void receiveData(int data);   //接收传递过来的数据的槽
public:
    //查找
    void searchnearby(int i);
    //最短路径
    void searchpath(int num);
    void output(int target1, int target2);
    //辅助导航
    int assist[NUM][NUM];
    int P[NUM][NUM];  //  //
    long int D[NUM];  // 辅助变量存储最短路径长度
//选择最短
    void shortest();
    int index;
    void cheapest();//最便宜
    void lessway();//最少道路
    void freewayfirst();//告诉有优先
    void roadfirst();//普通道路优先
    void walk();

    explicit navigation(QWidget *parent = 0);
    ~navigation();
     void saveRoad(QList<QString> a);
     void saveData(QList<QString> a);
     void readData();
     void drawRoad(QPainter *p,int type,int x1,int y1,int x2,int y2);
     void drawPoint(QPainter *p,int type,int x,int y,int i);
     graph gra;
protected:
     void randomcrowd();
     void fastest();
void paintEvent(QPaintEvent *);
public slots:
    void nav_click(int i);
    void on_back_clicked();

    void on_modify_clicked();

private slots:
    void on_pushButton_clicked();

    void on_delet_clicked();

    void on_shortest_clicked();

    void on_cheapest_clicked();

    void on_lessway_clicked();

    void on_freeway_clicked();

    void on_roadfirst_clicked();

    void on_walk_clicked();

    void on_bimianyongdu_clicked();

    void on_search_clicked();

private:
    int modify_point_int;
    Ui::navigation *ui;
};

#endif // NAVIGATION_H
