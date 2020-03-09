#include "menu.h"
#include "nouvellenote.h"
#include "quitter.h"

#include <QApplication>
#include <QLabel>
#include <QTimer>
#include <QTime>

Menu::Menu() : QWidget()
{
    setFixedSize(1080,720); //fixe la taille de la fenêtre
    //showMaximized()  //pour mettre en fullscreen



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
    QObject::connect(m_nouvelleNote, SIGNAL(clicked()), this, SLOT(ouvrirNote())); //connecte le bouton à la fonction ouvrirNote
    //------------------------------------------------------

    //--------------------Horloge-------------------------

    timer_1s = new QTimer(this);
    QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);

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

}

void Menu::UpdateTime()
{
    this->m_clock->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void Menu::ouvrirNote() //fonction ouvrirNote, ouvre la fenêtre de création d'une nouvelle note
{
    NouvelleNote *fenetreNote = new NouvelleNote;
    fenetreNote->show();

}

void Menu::ouvrirFenQuit() //fonction qui ouvre une fenetre pour demander si nous sommes bien sur de vouloir fermer le programme
{
    FenetreQuitter *fenetreQuitter = new FenetreQuitter;
    fenetreQuitter->show();
}
