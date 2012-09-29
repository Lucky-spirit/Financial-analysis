#include "evgwindow.h"

#include <iostream>

EvgWindow::EvgWindow(QWidget *parent) :
    QMainWindow(parent)
{
    pItsMenuBar = new EvgMenuBar(this);
    pItsTabBar = new QTabBar(this);
    pItsIcon = new QIcon();


    this->setMenuBar(pItsMenuBar);
    // this->menuBar();
    this->statusBar();
    this->setCentralWidget(pItsTabBar);

    this->setWindowIcon(QIcon(":/all/main_icon"));

    this->show();
}

EvgWindow::~EvgWindow()
{
    if (pItsMenuBar)
    {
        delete pItsMenuBar;
        pItsMenuBar = NULL;
    }

    if (pItsTabBar)
    {
        delete pItsTabBar;
        pItsTabBar = NULL;
    }

    if (pItsIcon)
    {
        delete pItsIcon;
        pItsIcon = NULL;
    }

    std::cout << "EvgWindow Destructor is called!" << std::endl;
}

void EvgWindow::mayToQuit()
{
    delete this;
}
