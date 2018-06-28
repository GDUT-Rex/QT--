#ifndef SEARCH_H
#define SEARCH_H
#include"graph.h"
#include <QDialog>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    void getMessage(graph g,int index);
    explicit Search(QWidget *parent = 0);
    ~Search();
signals:
    void sendData(int);   //用来传递数据的信号
private slots:
    void on_back_clicked();

    void on_search_clicked();

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
