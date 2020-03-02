#include "nouvellenote.h"

#include <iostream>
#include <fstream>
#include <QApplication>
#include <QPushButton>
#include <QFontComboBox>
#include <QTextEdit>
#include <QString>
#include <QColor>

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

    m_note->setTextColor("325, 255, 255");
    //m_note->setFontFamily();
    m_note->setPlaceholderText("Ecrivez votre note ici");
    m_note->resize(580,400);
    m_note->move(20,40);

    //-----------------------------------------------

    //-------------Choix de la police----------------
    m_boitePolice = new QFontComboBox(this);

    m_boitePolice->resize(120, 20);
    m_boitePolice->setEditable(false);
    m_boitePolice->move(20, 10);

    //-----------------------------------------------

    //-------------Choix de la couleur---------------
    m_boiteCouleur = new QComboBox(this);

    m_boiteCouleur->resize(120, 20);
    m_boiteCouleur->setEditable(false);
    m_boiteCouleur->move(150, 10);

    QString rouge = "Rouge";
    QString orange = "Orange";
    QString jaune = "Jaune";
    QString vert = "Vert";
    QString bleuClair = "Bleu Clair";
    QString bleuFonce = "Bleu Foncé";
    QString violet = "Violet";
    QString rose = "Rose";

    m_boiteCouleur->addItem(rouge);
    m_boiteCouleur->addItem(orange);
    m_boiteCouleur->addItem(jaune);
    m_boiteCouleur->addItem(vert);
    m_boiteCouleur->addItem(bleuClair);
    m_boiteCouleur->addItem(bleuFonce);
    m_boiteCouleur->addItem(violet);
    m_boiteCouleur->addItem(rose);

    QObject::connect(m_boiteCouleur, SIGNAL(currentTextChange()), this, SLOT(changerCouleur(c)));

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

void NouvelleNote::changerCouleur()
{
    std::cout << "c'estbon" << std::endl;
}
