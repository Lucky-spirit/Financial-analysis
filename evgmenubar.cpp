#include "evgmenubar.h"

#include <iostream>

EvgMenuBar::EvgMenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    pFileMenu = this->addMenu(tr("&Файл"));
    pEditMenu = this->addMenu(tr("&Правка"));
    pHelpMenu = this->addMenu(tr("&Допомога"));

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
    pCalculateAllAction = pFileMenu->addAction(QIcon(":/all/calculator"), tr("Розрахувати все"));
    pFileMenu->addSeparator();
    pQuitAction = pFileMenu->addAction(QIcon(":/all/quit"), tr("&Вихід"));

    this->connect(pCalculateAllAction, SIGNAL(triggered()), this, SIGNAL(calculateAll()));
    this->connect(pQuitAction, SIGNAL(triggered()), this, SIGNAL(signToQuit()));
}
