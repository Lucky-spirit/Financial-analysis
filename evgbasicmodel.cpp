#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(QWidget *parent, int coefficientsCount) :
    QWidget(parent),
    count(coefficientsCount)
{
    pLabelFormula = new QLabel(tr("Formula"), this);
    pLabelResult = new QLabel(tr("Result"), this);
    pCoefficientRows = new EvgRow[count];

    QVBoxLayout layoutVertical;

    layoutVertical.addWidget(pLabelFormula);
    layoutVertical.addWidget(pLabelResult);
    for (int i = 0; i < count; i++)
        layoutVertical.addWidget(&(pCoefficientRows[i]));

    this->setLayout(&layoutVertical);

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
