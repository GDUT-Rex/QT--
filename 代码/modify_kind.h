#ifndef MODIFY_KIND_H
#define MODIFY_KIND_H

#include <QDialog>

namespace Ui {
class modify_kind;
}

class modify_kind : public QDialog
{
    Q_OBJECT

public:
    explicit modify_kind(QWidget *parent = 0);
    ~modify_kind();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::modify_kind *ui;
};

#endif // MODIFY_KIND_H
