#include "menu.h"
#include "premiereouverture.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <QApplication>
#include <QPalette>


//-----------Informations-----------
//la doc : https://doc.qt.io/

//Code couleur :
//  - Background (gris foncé): #494949

//----------------------------------

//-------------ERREURS--------------

//----------------------------------



int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::string const fichierFirstOp("debug/premiereouverture.txt");
    std::ifstream firstOpening(fichierFirstOp.c_str());

    if(firstOpening)
    {
        std::string s;
        firstOpening >> s;  //même méthode que dans nouvellenote.cpp pour la sauvegarde

        int i;
        std::istringstream(s) >> i;

        firstOpening.close();

        if(i==1)    //si le programme n'a jamais été ouvert, on ouvre la fenêtre de première ouverture
        {
            i -= 1;
            std::ofstream firstOpening(fichierFirstOp.c_str());
            firstOpening << i;
            firstOpening.close();

            PremiereOuverture *fenetreMenu = new PremiereOuverture;
            fenetreMenu->show();

        }
        else    //sinon, il a déjà été ouvert, on ouvre le menu normalement
        {
            Menu *fenetreMenu = new Menu;
            fenetreMenu->show();
        }
    }
    else
    {
        std::cout << "ERREUR [3] : Impossible d'ouvrir le fichier pour verifier la premiere ouverture." << std::endl;
    }


    return app.exec();

}

