#include <QApplication>
#include"login2.h"
#include"navigation.h"
#include"mainmenu.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainMenu menu;
    //login2 k;
   // if(menu.exec()==QDialog::Accepted){

        menu.show();

        return a.exec();
   // }

   // menu.exec();

    //return a.exec();
}
