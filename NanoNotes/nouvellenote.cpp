#include "nouvellenote.h"
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>

NouvelleNote::NouvelleNote() : QWidget()
{
    setFixedSize(720,480);

    //--------------bouton de sauvegarde-------------
    m_sauvegarder = new QPushButton("Sauvegarder", this);

    m_sauvegarder->setCursor(Qt::PointingHandCursor);
    m_sauvegarder->setToolTip("Sauvegarde votre Note");
    m_sauvegarder->move(630,10);
    //-----------------------------------------------


    //----------------Zone de texte------------------
    m_note = new QTextEdit("Note", this);

    //m_note->setTextColor();       ca peut etre utile par la suite
    //m_note->setFontFamily();      ca aussi
    m_note->setText("Ecrivez votre note ici");
    m_note->move(20,40);

    //-----------------------------------------------
}

