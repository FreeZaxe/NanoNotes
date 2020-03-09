#include "quitter.h"

FenetreQuitter::FenetreQuitter()
{
    setFixedSize(360, 200);


    //---------------bouton pour quitter-------------
    m_quitter = new QPushButton("Oui", this);

    m_quitter->setCursor(Qt::PointingHandCursor);
    m_quitter->setToolTip("Ferme le logiciel !");
    m_quitter->move(150,150);

    QObject::connect(m_quitter, &QPushButton::clicked, qApp, [](){
        qApp->quit();
    });
    //-----------------------------------------------

    //----------------Label quitter------------------
    m_texteQuitter = new QLabel("Êtes vous sûr de bien vouloir quitter le logiciel ?", this);
    m_texteQuitter->move(80, 60);

    //-----------------------------------------------
}
