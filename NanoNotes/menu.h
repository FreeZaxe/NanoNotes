#ifndef DEF_MENU
#define DEF_MENU

#include <QApplication>
#include <QWidget>
#include <QPushButton>

class Menu : public QWidget
{

    public:
    Menu();

    public slots:
    void ouvrirNote();

    private:
    QPushButton *m_nouvelleNote;

};
#endif
