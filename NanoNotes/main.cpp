#include "menu.h"
#include "nouvellenote.h"
#include <QApplication>

//la doc : https://doc.qt.io/


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Menu fenetreMenu;       //Crée la fenêtre du menu
    fenetreMenu.show();     //Ouvre cette fenêtre


    return app.exec();
}

