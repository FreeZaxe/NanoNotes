#include "nouvellenote.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QPushButton>
#include <QFontComboBox>
#include <QTextEdit>
#include <QString>
#include <QColor>
#include <QSlider>

NouvelleNote::NouvelleNote() : QWidget()
{
    setFixedSize(720,480);



    //--------------bouton de sauvegarde-------------
    m_sauvegarder = new QPushButton("Sauvegarder", this);

    m_sauvegarder->setCursor(Qt::PointingHandCursor);  //https://doc.qt.io/qt-5/qt.html#CursorShape-enum pour avoir tout les types de curseurs
    m_sauvegarder->setToolTip("Sauvegarde votre Note");
    m_sauvegarder->move(540,10);

    QObject::connect(m_sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarder()));
    //-----------------------------------------------

    //---------------bouton pour quitter-------------
    m_quitter = new QPushButton("Quitter", this);

    m_quitter->setCursor(Qt::ForbiddenCursor);
    m_quitter->setToolTip("Ferme le logiciel !");
    m_quitter->move(630,10);

    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));

    //-----------------------------------------------


    //----------------Zone de texte------------------
    m_note = new QTextEdit(this);

    //m_note->setFontFamily();
    m_note->setPlaceholderText("Ecrivez votre note ici");
    m_note->resize(500,400);
    m_note->move(20,40);

    //-----------------------------------------------

    //-------------Choix de la police----------------
    m_boitePolice = new QFontComboBox(this);

    m_boitePolice->resize(120, 20);
    m_boitePolice->setEditable(false);
    m_boitePolice->move(20, 10);

    //-----------------------------------------------

    //-------------Choix de la couleur---------------

    m_sliderR = new QSlider(Qt::Horizontal, this);
    m_sliderG = new QSlider(Qt::Horizontal, this);
    m_sliderB = new QSlider(Qt::Horizontal, this);

    m_sliderR->setGeometry(550, 100, 145, 20);
    m_sliderG->setGeometry(550, 130, 145, 20);
    m_sliderB->setGeometry(550, 160, 145, 20);

    m_sliderR->setRange(0, 255);
    m_sliderG->setRange(0, 255);
    m_sliderB->setRange(0, 255);

    QObject::connect(m_sliderR, SIGNAL(valueChanged(int)), this, SLOT(changerCouleur()));
    QObject::connect(m_sliderG, SIGNAL(valueChanged(int)), this, SLOT(changerCouleur()));
    QObject::connect(m_sliderB, SIGNAL(valueChanged(int)), this, SLOT(changerCouleur()));

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

void NouvelleNote::changerCouleur(int r, int g, int b)
{
    m_note->setTextColor(QColor(r, g, b, 255));
}
