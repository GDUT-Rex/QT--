#include "delete_point.h"
#include "ui_delete_point.h"

delete_point::delete_point(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::delete_point)
{
    ui->setupUi(this);
}

delete_point::~delete_point()
{
    delete ui;
}
