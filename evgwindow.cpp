#include "evgwindow.h"

#include <iostream>

EvgWindow::EvgWindow(QWidget *parent) :
    QMainWindow(parent)
{
    pItsMenuBar = new EvgMenuBar(this);
    pItsTabBar = new QTabBar(this);

    this->createTabs();

    this->setMenuBar(pItsMenuBar);
    this->statusBar();
    this->setCentralWidget(pItsTabBar);

    this->setWindowIcon(QIcon(":/all/main_icon"));

    this->connect(pItsMenuBar, SIGNAL(signToQuit()), this, SLOT(mayToQuit()));

    this->showMaximized();
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

//    if (pInputData)
//    {
//        delete pInputData;
//        pInputData = NULL;
//    }
    std::cout << "EvgWindow Destructor is called!" << std::endl;
}

void EvgWindow::mayToQuit()
{
    delete this;
}

void EvgWindow::createTabs()
{
    pInputData = new InputData(pItsTabBar);
}
