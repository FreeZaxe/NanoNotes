#include "nouvellenote.h"
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>

NouvelleNote::NouvelleNote() : QWidget()
{
    setFixedSize(1080,720);

    //--------------bouton de sauvegarde-------------
    m_sauvegarder = new QPushButton("Sauvegarder", this);

    m_sauvegarder->setCursor(Qt::PointingHandCursor);
    m_sauvegarder->setToolTip("Sauvegarde votre Note");
    m_sauvegarder->move(990,10);
    //-----------------------------------------------

    //----------------Zone de texte------------------
    m_note = new QTextEdit();

    m_note->move(0,0);
    //-----------------------------------------------

}
