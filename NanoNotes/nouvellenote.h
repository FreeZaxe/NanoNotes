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


    private:
    QPushButton *m_sauvegarder;
    QTextEdit *m_note;


};
#endif
