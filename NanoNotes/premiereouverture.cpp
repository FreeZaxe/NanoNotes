#include "premiereouverture.h"
#include "menu.h"

#include <QApplication>
#include <QPushButton>

PremiereOuverture::PremiereOuverture()
{
    setFixedSize(1080,720);

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
}
