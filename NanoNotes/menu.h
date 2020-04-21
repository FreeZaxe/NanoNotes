#ifndef DEF_MENU
#define DEF_MENU

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include <QTimer>
#include <QTime>
#include<QTabWidget>



class Menu : public QWidget
{
    Q_OBJECT

    public:
    Menu();

    public slots:
    void ouvrirNote();
    void ouvrirFenQuit();

    private:
    QPushButton *m_nouvelleNote;
    QPushButton *m_quitter;
    QTimer *m_timer;

    QLabel *m_clock;
    QLabel *m_ouvrirNote;
    QLabel *m_nanoNoteTexte;
    QLabel *m_pasDeNotes;

    QTextEdit *m_appNote;
    QTabWidget *m_tabNotes;

    private slots:
    void updateTime();

};
#endif
