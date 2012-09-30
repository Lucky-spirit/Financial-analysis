#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(int coefficientsCount, QWidget *parent) :
    count(coefficientsCount),
    QWidget(parent)
{
    pLabelFormula = new QLabel(tr("Formula"), this);
    pLabelResult = new QLabel(tr("Result"), this);
    pCoefficientRows = new EvgRow[count];

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
