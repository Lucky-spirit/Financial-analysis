#ifndef EVGWINDOW_H
#define EVGWINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include "evgmenubar.h"
#include "evgallmodels.h"
// #include "inputdata.h"

class EvgWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit EvgWindow(QWidget *parent = 0);
    ~EvgWindow();

    QMenuBar *menuBar() const;
    
signals:

public slots:
    void mayToQuit();

private:
    void createMenus();
    void createTabs();
    void createAllModels();

private:
    EvgMenuBar *pItsMenuBar;
    QTabWidget *pItsTabWidget;
    EvgAllModels *pAllModels;
    // InputData *pInputData;
};

#endif // EVGWINDOW_H
