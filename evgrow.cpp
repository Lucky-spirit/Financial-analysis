#include "evgrow.h"

// Supporting comment
#include <iostream>

EvgRow::EvgRow(QWidget *parent) :
    QWidget(parent)
{
    pIdCoefficient = new QLabel("x1", this);
    pCoefficientValue = new QDoubleSpinBox(this);
    pDefinitionCoefficient = new QLabel("Some definition", this);

    QHBoxLayout *layoutHor = new QHBoxLayout;
    layoutHor->addStretch(1);
    layoutHor->addWidget(pIdCoefficient);
    layoutHor->addWidget(pCoefficientValue);
    layoutHor->addWidget(pDefinitionCoefficient, 2);
    layoutHor->addStretch(1);

    this->setLayout(layoutHor);

    this->show();
}

EvgRow::~EvgRow()
{
    if (pIdCoefficient)
    {
        delete pIdCoefficient;
        pIdCoefficient = NULL;
    }
    if (pCoefficientValue)
    {
        delete pCoefficientValue;
        pCoefficientValue = NULL;
    }
    if (pDefinitionCoefficient)
    {
        delete pDefinitionCoefficient;
        pDefinitionCoefficient = NULL;
    }

    // Supporting comment
    std::cout << "evgRow Destructor is called!" << std::endl;
}
