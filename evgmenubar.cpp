#include "evgmenubar.h"

#include <iostream>

EvgMenuBar::EvgMenuBar(QWidget *parent) :
    QMenuBar(parent)
{
    pFileMenu = this->addMenu("File");
    pEditMenu = this->addMenu("Edit");
    pHelpMenu = this->addMenu("Help");

    pFileMenu->addAction("Calculate all");

    this->show();
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
