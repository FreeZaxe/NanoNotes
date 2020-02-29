#include "nouvellenote.h"

#include <iostream>
#include <fstream>
#include <QFile>

#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QString>

NouvelleNote::NouvelleNote() : QWidget()
{
    setFixedSize(720,480);


    //--------------bouton de sauvegarde-------------
    m_sauvegarder = new QPushButton("Sauvegarder", this);

    m_sauvegarder->setCursor(Qt::PointingHandCursor);  //https://doc.qt.io/qt-5/qt.html#CursorShape-enum pour avoir tout les types de curseurs
    m_sauvegarder->setToolTip("Sauvegarde votre Note");
    m_sauvegarder->move(630,10);

    QObject::connect(m_sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
    //-----------------------------------------------

    //---------------bouton pour quitter-------------
    m_quitter = new QPushButton("Quitter", this);

    m_quitter->setCursor(Qt::ForbiddenCursor);
    m_quitter->setToolTip("Ferme le logiciel !");
    m_quitter->move(630,50);

    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    //-----------------------------------------------


    //----------------Zone de texte------------------
    m_note = new QTextEdit(this);

    //m_note->setTextColor();       //ca peut etre utile par la suite
    //m_note->setFontFamily();      ca aussi
    m_note->setPlaceholderText("Ecrivez votre note ici");
    m_note->resize(580,400);
    m_note->move(20,10);

    //-----------------------------------------------
}

void NouvelleNote::sauvegarder() //fonction pour sauvegarder les notes
{
    std::string const fichierSauvegarde("debug/sauvegardes/save.txt");
    std::ofstream sauvegarde(fichierSauvegarde.c_str());

    if(sauvegarde)
    {
        //On peut créer ou modifier le fichier

        QString noteQt = m_note->toPlainText(); //met tout le texte de la note dans une variable QString
        std::string note = noteQt.toStdString(); //passe le texte d'une variable QString à une variable string

        sauvegarde << note; //met le texte de la variable string dans le fichier .txt

    }
    else
    {
        std::cout << "ERREUR : Impossible d'ouvrir le fichier." << std::endl;
    }
}
