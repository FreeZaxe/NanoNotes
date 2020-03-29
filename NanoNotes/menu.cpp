#include "menu.h"
#include "nouvellenote.h"
#include "quitter.h"

#include <sstream>
#include <iostream>
#include <fstream>
#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include <QTabWidget>

Menu::Menu() : QWidget()
{
    setFixedSize(1080,720); //fixe la taille de la fenêtre
    //showMaximized()  //pour mettre en fullscreen
    setWindowIcon(QIcon("debug/assets/icon.png")); //change l'icone de la fenêtre



    //-----------------Textes------------------------------
    m_nanoNoteTexte = new QLabel("NanoNotes", this);

    m_nanoNoteTexte->move(400, 20);
    m_nanoNoteTexte->setFont(QFont("Montserrat", 40));
    //-----------------------------------------------------

    //----------------bouton de nouvelle note---------------
    m_nouvelleNote = new QPushButton("Nouvelle note", this);

    m_nouvelleNote->setCursor(Qt::PointingHandCursor); //change le type curseur
    m_nouvelleNote->move(290, 650);
    m_nouvelleNote->setFixedWidth(500);
    m_nouvelleNote->setToolTip("Crée une nouvelle Note");
    QObject::connect(m_nouvelleNote, &QPushButton::clicked, this, [this](){
        this->ouvrirNote();


    }); //connecte le bouton à la fonction ouvrirNote
    //------------------------------------------------------

    //--------------------Horloge-------------------------

    m_timer = new QTimer(this);
    QObject::connect(m_timer, &QTimer::timeout, this, [this](){
        this->updateTime();
    });
    m_timer->start(1000);

    //- - - - - - - - - - Affichage - - - - - - - - - - - - -
    m_clock = new QLabel("Test", this);
    m_clock->move(1020, 800);
    m_clock->setFixedWidth(600);
    m_clock->setTextFormat(Qt::RichText);
    m_clock->setStyleSheet("font-weight: bold; color: black");
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - -

    //------------------------------------------------------

    //-----------------affichage txt ouvrir Note------------
    m_ouvrirNote = new QLabel("Ouvrir Une Note :", this);
    m_ouvrirNote->move(50,120);
    m_ouvrirNote->setFixedWidth(500);
    m_ouvrirNote->setStyleSheet("font-weight: bold; color: black");
    //------------------------------------------------------

    //---------------bouton pour quitter-------------
    m_quitter = new QPushButton("Quitter", this);

    m_quitter->setCursor(Qt::PointingHandCursor);
    m_quitter->setToolTip("Ferme le logiciel !");
    m_quitter->move(990,10);

    QObject::connect(m_quitter, &QPushButton::clicked, this, [this](){
        this->ouvrirFenQuit();
    });
    //-----------------------------------------------


    //----------système de gestion des notes------------




    //- - - - - - - - - - Récupération nombre de sauvegardes - - - - - - - - - - -

    std::string const fichierNombreSauvegarde("debug/sauvegardes/nbrSaves.txt");
    std::ifstream nbrSauvegardes(fichierNombreSauvegarde.c_str());

    if(nbrSauvegardes)
    {

        std::string nString;
        nbrSauvegardes >> nString;  //prend le numéro du nombre de notes

        int n;
        std::istringstream(nString) >> n;   //le transforme en int

        n -= 1; //enlève 1 car le numéro représente celui de la prochaine note
        nbrSauvegardes.close(); //ferme le fichier pour éviter les erreurs

    }
    else
    {
        std::cout << "ERREUR [1.2] : Impossible de lire le fichier du nombre de sauvegarde afin de les afficher dans le menu." << std::endl ;

    }

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    //- - - - - - - - - - - - - - - - Zone de notes - - - - - - - - - - - - - - -

    m_zoneNotes = new QTabWidget(this);





    //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -


    //--------------------------------------------------

}

void Menu::updateTime()
{
    this->m_clock->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void Menu::ouvrirNote() //fonction ouvrirNote, ouvre la fenêtre de création d'une nouvelle note
{
    NouvelleNote *fenetreNote = new NouvelleNote;
    fenetreNote->show();
    close();

}

void Menu::ouvrirFenQuit() //fonction qui ouvre une fenetre pour demander si nous sommes bien sur de vouloir fermer le programme
{
    FenetreQuitter *fenetreQuitter = new FenetreQuitter;
    fenetreQuitter->show();
}
