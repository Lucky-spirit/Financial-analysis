#include "evgrow.h"

// Supporting comment
#include <iostream>

EvgRow::EvgRow(QWidget *parent) :
    QWidget(parent)
{
    pIdCoefficient = new QLabel(this);
    pCoefficientValue = new QDoubleSpinBox(this);
    pDefinitionCoefficient = new QLabel(this);
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
