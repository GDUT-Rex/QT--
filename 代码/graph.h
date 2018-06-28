#ifndef GRAPH_H
#define GRAPH_H

#include<stdio.h>
#include "stdlib.h"

#include<QString.h>
#define Max 30000
#define NUM 100
class graph{

public:
    int max=100;
typedef struct ArcCell {
    int distans;  // 相邻接的目标之间的路程
    int type;//顶点的类型
    int crowd;//拥堵系数
}ArcCell;   // 定义边的类型
typedef struct VertexType {
    int number;  // 目标编号
    int x,y;//目标坐标
    int type = 0;//判断目标，不存在为0
   QString name;// 目标名称
   QString description; // 目标描述
}VertexType;   // 定义顶点的类型
typedef struct {
    VertexType vex[NUM]; // 图中的顶点，即为目标
    ArcCell arcs[NUM][NUM]; // 图中的边，即为目标间的距离
    int vexnum, arcnum; // 顶点数，边数
}MGraph;   // 定义图的类型
MGraph G;//全局图
graph();

};

#endif // GRAPH_H



