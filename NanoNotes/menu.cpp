#include "menu.h"
#include "nouvellenote.h"
#include <QApplication>


Menu::Menu() : QWidget()
{
    setFixedSize(1080,720); //fixe la taille de la fenêtre

    //----------------bouton de nouvelle note---------------
    m_nouvelleNote = new QPushButton("Nouvelle note", this);

    m_nouvelleNote->setCursor(Qt::PointingHandCursor); //change le type curseur
    m_nouvelleNote->move(500, 450);
    m_nouvelleNote->setToolTip("Crée une nouvelle Note");

    QObject::connect(m_nouvelleNote, SIGNAL(clicked()), this, SLOT(ouvrirNote())); //connecte le bouton à la fonction ouvrirNote
    //------------------------------------------------------


    //il faut rajouter tout le texte et l'interface ici


}

void Menu::ouvrirNote() //fonction ouvrirNote, ouvre la fenêtre de création d'une nouvelle note
{
    NouvelleNote *fenetreNote = new NouvelleNote;
    fenetreNote->show();
}
