#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QFontComboBox>
#include <QLabel>


class NouvelleNote : public QWidget
{
    Q_OBJECT

    public:
    NouvelleNote();

    public slots:
    void sauvegarder();
    void changerCouleur(int r, int g, int b);
    void ouvrirFenQuit();

    private:
    QPushButton *m_sauvegarder;
    QPushButton *m_quitter;
    QTextEdit *m_note;
    QFontComboBox *m_boitePolice;

    QSlider *m_sliderR;
    QSlider *m_sliderG;
    QSlider *m_sliderB;
    QLabel *m_r;
    QLabel *m_g;
    QLabel *m_b;
    QRect *m_rectangle;


};
#endif
