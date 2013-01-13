#include "evgrow.h"

// Supporting comment
#include <iostream>

EvgRow::EvgRow(QWidget *parent) :
    QWidget(parent)
{
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
}

void EvgRow::init()
{
    pIdCoefficient = new QLabel("", this);
    pDefinitionCoefficient = new QLabel("", this);
    createSpinBox();
}

void EvgRow::createSpinBox()
{
    pCoefficientValue = new QDoubleSpinBox(this);

    pCoefficientValue->setMaximum(99999.9999);
    pCoefficientValue->setMinimum(-99999.9999);
    pCoefficientValue->setDecimals(4);
    pCoefficientValue->setReadOnly(TRUE);
}

void EvgRow::settingLayout()
{
    QHBoxLayout *layoutHor = new QHBoxLayout;

    layoutHor->addStretch(1);
    layoutHor->addWidget(pIdCoefficient);
    layoutHor->addWidget(pCoefficientValue);
    layoutHor->addWidget(pDefinitionCoefficient, 2);
    layoutHor->addStretch(1);

    this->setLayout(layoutHor);
}

void EvgRow::setIdText(int newId)
{
    QString foo;
    foo.setNum(newId);
    foo.insert(0, "x<sub>");
    foo.append("</sub>");
    pIdCoefficient->setText(foo);
}

void EvgRow::changeIdToText(QString &)
{
    qDebug("EvgRow::%s error! V-Table.", __FUNCTION__);
}

void EvgRow::setStringByState(TypeState state)
{
    qDebug("EvgRow::%s error! V-Table.", __FUNCTION__);
}

void EvgRow::setTextDefinition(QString newText)
{
    pDefinitionCoefficient->setText(newText);
}

double EvgRow::getValue() const
{
    return pCoefficientValue->value();
}

void EvgRow::setValue(float value)
{
    pCoefficientValue->setValue(value);
}

void EvgRow::setEditable(bool yes)
{
    pCoefficientValue->setReadOnly(!yes);
}

QLabel *EvgRow::labelId()
{
    return pIdCoefficient;
}

QDoubleSpinBox *EvgRow::spinBoxRow()
{
    return pCoefficientValue;
}

QLabel *EvgRow::labelDefinition()
{
    return pDefinitionCoefficient;
}
