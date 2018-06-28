#ifndef DELETE_POINT_H
#define DELETE_POINT_H

#include <QDialog>

namespace Ui {
class delete_point;
}

class delete_point : public QDialog
{
    Q_OBJECT

public:
    explicit delete_point(QWidget *parent = 0);
    ~delete_point();

private:
    Ui::delete_point *ui;
};

#endif // DELETE_POINT_H
