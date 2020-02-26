#include "menu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Menu fenetre;
    fenetre.show();

    return app.exec();
}
