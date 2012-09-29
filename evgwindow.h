#ifndef EVGWINDOW_H
#define EVGWINDOW_H

#include <QMainWindow>
#include <QTabBar>
#include "evgmenubar.h"

class EvgWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit EvgWindow(QWidget *parent = 0);
    ~EvgWindow();
    
signals:
    
public slots:
    void mayToQuit();

private:
    void createMenus();

private:
    EvgMenuBar *pItsMenuBar;
    QTabBar *pItsTabBar;
    QIcon *pItsIcon;
};

#endif // EVGWINDOW_H
