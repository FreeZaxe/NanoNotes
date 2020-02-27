#include "menu.h"
#include "nouvellenote.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);


    Menu fenetreMenu;       //Crée la fenêtre du menu
    fenetreMenu.show();     //Ouvre cette fenêtre

    NouvelleNote fenetreNote;      //Ces 2 lignes seront à enlever par la suite, elles sont juste là
    fenetreNote.show();            //Pour pouvoir faire des modifs sur la fenêtre nouvelleNote

    return app.exec();
}

