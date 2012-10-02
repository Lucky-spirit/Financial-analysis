#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(QWidget *parent, int coefficientsCount) :
    QWidget(parent),
    count(coefficientsCount)
{
    pLabelFormula = new QLabel(tr("Formula"), this);
    pLabelResult = new QLabel(tr("Result"), this);
    pCoefficientRows = new EvgRow[count];

    QHBoxLayout *layoutHor = new QHBoxLayout;
    layoutHor->addStretch(1);
    layoutHor->addWidget(pLabelFormula, 0);
    layoutHor->addWidget(pLabelResult, 0);
    layoutHor->addStretch(1);

    QVBoxLayout *layoutVertical = new QVBoxLayout;
    layoutVertical->addLayout(layoutHor, 0);
    layoutVertical->addStretch(1);
    for (int i = 0; i < count; i++)
        layoutVertical->addWidget(&(pCoefficientRows[i]), 0);

    this->setLayout(layoutVertical);

    this->show();
}

EvgBasicModel::~EvgBasicModel()
{
    delete [] pCoefficientRows;
}

void EvgBasicModel::setFormulaText(QString text)
{
    pLabelFormula->setText(text);
}

void EvgBasicModel::setResultValue(float value)
{
    QString result;
    pLabelResult->setText(result.setNum(value, 'g', 4));
}
