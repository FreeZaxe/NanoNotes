#include "premiereouverture.h"
#include "menu.h"

#include <QApplication>
#include <QPushButton>
#include <QLabel>

PremiereOuverture::PremiereOuverture()
{
    setFixedSize(1080,720);
    setWindowIcon(QIcon("debug/assets/icon.png"));

    //---------------labels informations--------------------

    //- - - - - - - - - - Bienvenue - - - - - - - - - - - - -
    m_bienvenue = new QLabel("Bienvenue dans NanoNotes", this);

    m_bienvenue->move(260, 20);
    m_bienvenue->setFont(QFont("Montserrat", 30));
    //- - - - - - - - - - - - - - - - - - - - - - - - - - - -

    //- - - - - - - - - - Lignes - - - - - - - - - - - - - -

    //_1_

    m_ligne1 = new QLabel("NanoNote est un éditeur de notes gratuit et simple d'utilisation", this);
    m_ligne1->move(280, 150);
    m_ligne1->setFont(QFont("Montserrat", 12));

    //_2_

    m_ligne2 = new QLabel("Il vous permet de prendre des notes courtes ou longues, puis de les sauvegarder pour ne plus les oublier", this);
    m_ligne2->move(120, 180);
    m_ligne2->setFont(QFont("Montserrat", 12));

    //_3_

    m_ligne3 = new QLabel("", this);
    m_ligne3->move(140, 240);
    m_ligne3->setFont(QFont("Montserrat", 12));

    //_4_

    m_ligne4 = new QLabel("Pour cela, il vous suffit juste de cliquer sur démarer et de commencer à écrire vos première notes", this);
    m_ligne4->move(140, 270);
    m_ligne4->setFont(QFont("Montserrat", 12));

    //_5_

    m_ligne5 = new QLabel("Vous allez voir, c'est très simple", this);
    m_ligne5->move(400, 300);
    m_ligne5->setFont(QFont("Montserrat", 12));

    //- - - - - - - - - - - - - - - - - - - - - - - - - - - -

    //------------------------------------------------------



    //-------------------bouton de démarage-----------------
    m_boutonDemarer = new QPushButton("Démarer", this);

    m_boutonDemarer->setCursor(Qt::PointingHandCursor);
    m_boutonDemarer->move(290, 650);
    m_boutonDemarer->setFixedWidth(500);
    m_boutonDemarer->setToolTip("Démare le logiciel");
    QObject::connect(m_boutonDemarer, &QPushButton::clicked, this, [this]() //connecte le bouton à la fonction demarer
    {
        this->demarer();
    });
    //------------------------------------------------------
}

void PremiereOuverture::demarer()
{
    Menu *fenetreMenu = new Menu;
    fenetreMenu->show();
    close();
}
