#ifndef FENETREQUITTER_H
#define FENETREQUITTER_H

#include <QApplication>
#include <QPushButton>
#include <QLabel>

class FenetreQuitter : public QWidget
{
    Q_OBJECT

    public:
    FenetreQuitter();

    public slots :


    private:
    QPushButton *m_quitter;
    QLabel *m_texteQuitter;

};
#endif
