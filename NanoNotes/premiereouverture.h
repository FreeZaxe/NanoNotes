#ifndef FIRSTOPENNING_H
#define FIRSTOPENNING_H

#include <QApplication>
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
};
#endif
