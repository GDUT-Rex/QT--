#include <graph.h>
#include<fstream>
#include <sstream>
#include "stdio.h"
#include "stdlib.h"
#include <ostream>

graph::graph(){
    for(int i=0;i<max;i++)
        for(int j=0;j<max;j++){
           // G.arcs[i][j].distans=0;
             G.vex[i].type=0;
             G.arcs[i][j].type=0;
             G.arcs[i][j].distans=30000;
        }

}
