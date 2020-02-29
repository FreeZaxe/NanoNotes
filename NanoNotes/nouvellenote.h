#ifndef NOUVELLENOTE_H
#define NOUVELLENOTE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>


class NouvelleNote : public QWidget
{
    Q_OBJECT

    public:
    NouvelleNote();

    public slots:
    void sauvegarder();

    private:
    QPushButton *m_sauvegarder;
    QPushButton *m_quitter;
    QTextEdit *m_note;


};
#endif
