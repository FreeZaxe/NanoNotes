#include "nouvellenote.h"
#include "quitter.h"
#include "menu.h"

#include <string>
#include <sstream>
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
    setWindowIcon(QIcon("debug/assets/icon.png"));

    //--------------bouton de sauvegarde-------------
    m_sauvegarder = new QPushButton("Sauvegarder", this);

    m_sauvegarder->setCursor(Qt::PointingHandCursor); //https://doc.qt.io/qt-5/qt.html#CursorShape-enum pour avoir tout les types de curseurs
    m_sauvegarder->setToolTip("Sauvegarde votre Note");
    m_sauvegarder->move(540,10);

    QObject::connect(m_sauvegarder, &QPushButton::clicked, this, [this](){
        this->sauvegarder();
    });
    //-----------------------------------------------


    //---------------bouton pour quitter-------------
    m_quitter = new QPushButton("Quitter", this);

    m_quitter->setCursor(Qt::PointingHandCursor);
    m_quitter->setToolTip("Ferme le logiciel !");
    m_quitter->move(630,10);

    QObject::connect(m_quitter, &QPushButton::clicked, this, [this](){
        this->ouvrirFenQuit();
    });
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

    QObject::connect(m_sliderR, &QSlider::valueChanged, this, [this](int r){

        auto g = m_sliderG->value();
        auto b = m_sliderB->value();

        this->changerCouleur(r, g, b);
    });
    QObject::connect(m_sliderG, &QSlider::valueChanged, this, [this](int g){

        auto r = m_sliderR->value();
        auto b = m_sliderB->value();

        this->changerCouleur(r, g, b);
    });
    QObject::connect(m_sliderB, &QSlider::valueChanged, this, [this](int b){

        auto r = m_sliderR->value();
        auto g = m_sliderG->value();

        this->changerCouleur(r, g, b);
    });

    //- - - - - - - Labels sliders - - - - - - - -
    m_r = new QLabel("R :", this);
    m_r->move(530, 100);
    m_r->setStyleSheet("font-weight: bold; color : red");

    m_g = new QLabel("G :", this);
    m_g->move(530, 130);
    m_g->setStyleSheet("font-weight: bold; color : green");

    m_b = new QLabel("B :", this);
    m_b->move(530, 160);
    m_b->setStyleSheet("font-weight: bold; color : blue");
    //- - - - - - - - - - - - - - - - - - - - - -

    //-----------------------------------------------
}


void NouvelleNote::sauvegarder() //fonction pour sauvegarder les notes
{
    std::string const fichierNombreSauvegarde("debug/sauvegardes/nbrSaves.txt");
    std::ifstream nbrSauvegardes(fichierNombreSauvegarde.c_str());

    if(nbrSauvegardes)
    {
        //- - - - - - - - - - - - - - - - Sauvegarde - - - - - - - - - - - - - - - - - - - - - -
        std::string nString;
        nbrSauvegardes >> nString;  //prend le numéro de la prochaine note

        int n;
        std::istringstream(nString) >> n;   //le transforme en int pour pouvoir ajouter 1 à ce numéro une fois la note enregistré pour que
                                            //la prochaine ai un autre numéro
        nbrSauvegardes.close(); //ferme le fichier pour éviter les erreurs


        std::string fichierSauvegarde("debug/sauvegardes/save");
        fichierSauvegarde += nString;     //on rajoute le numéro de la sauvegarde
        fichierSauvegarde += ".txt";        //et le .txt qui spécifie le type de fichier
        std::ofstream sauvegarde(fichierSauvegarde.c_str());

        if(sauvegarde)
        {
            //On peut créer ou modifier le fichier

            QString noteQt = m_note->toPlainText(); //met tout le texte de la note dans une variable QString
            std::string note = noteQt.toStdString(); //passe le texte d'une variable QString à une variable string

            sauvegarde << note; //met le texte de la variable string dans le fichier .txtre

            sauvegarde.close();

        }
        else
        {
            std::cout << "ERREUR [2] : Impossible d'ouvrir un nouveau fichier pour creer une nouvelle sauvegarde." << std::endl;
        }

        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

        //- - - - - - - - - - - Changement du numéro de la sauvegarde - - - - - - - - - - - - -
        n += 1;  //ajoute 1 au numéro de la sauvegarde

        std::ofstream nbrSauvegardes(fichierNombreSauvegarde.c_str());

        nbrSauvegardes << n; //remplace l'ancien numéro par le nouveau pour que la prochaine sauvegarde est un nom différent

        nbrSauvegardes.close();

        Menu *fenetreMenu = new Menu;   //recrée une fenêtre menu et ferme la fenetre de nouvelle note
        fenetreMenu->show();
        close();
        //- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    }
    else
    {
        std::cout << "ERREUR [1.1] : Impossible d'ouvrir le fichier pour lire le nombre de sauvegardes afin de créer une nouvelle note." << std::endl;
    }

}



void NouvelleNote::changerCouleur(int r, int g, int b) //fonction pour changer la couleur du texte
{
    m_note->setTextColor(QColor(r, g, b, 255));

}

void NouvelleNote::ouvrirFenQuit() //fonction qui ouvre une fenetre pour demander si nous sommes bien sur de vouloir fermer le programme
{
    FenetreQuitter *fenetreQuitter = new FenetreQuitter;
    fenetreQuitter->show();
}
