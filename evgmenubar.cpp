#include "evgmenubar.h"

#include <iostream>

EvgMenuBar::EvgMenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    pFileMenu = this->addMenu(tr("&File"));
    pEditMenu = this->addMenu(tr("&Edit"));
    pHelpMenu = this->addMenu(tr("&Help"));

    createMenus();
}

EvgMenuBar::~EvgMenuBar()
{
    if (pFileMenu)
    {
        delete pFileMenu;
        pFileMenu = NULL;
    }

    if (pEditMenu)
    {
        delete pEditMenu;
        pEditMenu = NULL;
    }

    if (pHelpMenu)
    {
        delete pHelpMenu;
        pHelpMenu = NULL;
    }
    std::cout << "EvgMenuBar Destructor is called!" << std::endl;
}

void EvgMenuBar::createMenus()
{
    pCalculateAllAction = pFileMenu->addAction(QIcon(":/all/calculator"), tr("&Calculate all"));
    pFileMenu->addSeparator();
    pQuitAction = pFileMenu->addAction(QIcon(":/all/quit"), tr("&Quit"));

    this->connect(pCalculateAllAction, SIGNAL(triggered()), this, SIGNAL(calculateAll()));
    this->connect(pQuitAction, SIGNAL(triggered()), this, SIGNAL(signToQuit()));
}
