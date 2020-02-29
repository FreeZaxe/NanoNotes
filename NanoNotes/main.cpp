#include "menu.h"
#include "nouvellenote.h"
#include <QApplication>
#include <QPalette>


//-----------Informations-----------
//la doc : https://doc.qt.io/

//Code couleur :
//  - Background (gris foncé): #494949

//----------------------------------


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Menu fenetreMenu;       //Crée la fenêtre du menu
    fenetreMenu.show();     //Ouvre cette fenêtre


    return app.exec();
}

