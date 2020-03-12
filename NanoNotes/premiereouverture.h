#ifndef FIRSTOPENNING_H
#define FIRSTOPENNING_H

#include <QApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>

class PremiereOuverture : public QWidget
{
    Q_OBJECT

    public:
    PremiereOuverture();

    public slots:
    void demarer();

    private:
    QPushButton *m_boutonDemarer;

    QLabel *m_bienvenue;
    QLabel *m_ligne1;
    QLabel *m_ligne2;
    QLabel *m_ligne3;
    QLabel *m_ligne4;
    QLabel *m_ligne5;

};
#endif
