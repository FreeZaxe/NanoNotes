#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QFontComboBox>


class NouvelleNote : public QWidget
{
    Q_OBJECT

    public:
    NouvelleNote();

    public slots:
    void sauvegarder();
    void changerCouleur();

    private:
    QPushButton *m_sauvegarder;
    QPushButton *m_quitter;
    QTextEdit *m_note;
    QFontComboBox *m_boitePolice;
    QComboBox *m_boiteCouleur;


};
#endif
