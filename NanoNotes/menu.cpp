#include "menu.h"

Menu::Menu() : QWidget()
{
    setFixedSize(1080,720);

    //bouton de nouvelle note
    m_nouvelleNote = new QPushButton("Nouvelle note", this);

    m_nouvelleNote->setCursor(Qt::PointingHandCursor);
    m_nouvelleNote->move(990, 670);
    m_nouvelleNote->setToolTip("Crée une nouvelle Note");

    QObject::connect(m_nouvelleNote, SIGNAL(clicked()), qApp, SLOT(ouvrirNote()));
    //------------------------------------------------------



}

void Menu::ouvrirNote()
{
    //créer une fenètre où l'on peut écrire la note
    //et un bouton pour la sauvegarder
}
