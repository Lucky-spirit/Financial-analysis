#include "evgrow.h"

// Supporting comment
#include <iostream>

EvgRow::EvgRow(QWidget *parent) :
    QWidget(parent)
{
    pIdCoefficient = new QLabel("", this);
    createSpinBox();
    pDefinitionCoefficient = new QLabel("", this);

    QHBoxLayout *layoutHor = new QHBoxLayout;
    layoutHor->addStretch(1);
    layoutHor->addWidget(pIdCoefficient);
    layoutHor->addWidget(pCoefficientValue);
    layoutHor->addWidget(pDefinitionCoefficient, 2);
    layoutHor->addStretch(1);

    this->setLayout(layoutHor);
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

void EvgRow::setIdText(int newId)
{
    QString foo;
    foo.setNum(newId);
    foo.insert(0, "x");
    pIdCoefficient->setText(foo);
}

void EvgRow::setTextDefinition(QString newText)
{
    pDefinitionCoefficient->setText(newText);
}

double EvgRow::getValue() const
{
    return pCoefficientValue->value();
}

void EvgRow::createSpinBox()
{
    pCoefficientValue = new QDoubleSpinBox(this);

    pCoefficientValue->setMaximum(99999.9999);
    pCoefficientValue->setMinimum(-99999.9999);
    pCoefficientValue->setDecimals(4);
}
