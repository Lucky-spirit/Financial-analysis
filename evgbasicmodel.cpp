#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(QWidget *parent) :
    QWidget(parent)
{
    pLabelFormula = new QLabel(tr(""), this);
    pLabelResult = new QLabel(tr(""), this);
}

EvgBasicModel::~EvgBasicModel()
{
//    if (pLabelFormula)
//    {
//        delete pLabelFormula;
//        pLabelFormula = NULL;
//    }

//    if (pLabelResult)
//    {
//        delete pLabelResult;
//        pLabelResult = NULL;
//    }
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
