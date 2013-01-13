#include "modaltmana.h"

modAltmana::modAltmana(QWidget *parent) :
    EvgBasicModel(CountAltmana,
                  parent,
                  tr("qrc:/models/altman"),
                  tr("Модель Альтмана"),
                  tr("Z = 0,717X<sub>1</sub> + 0,847X<sub>2</sub> + 3,107X<sub>3</sub> + 0,42X<sub>4</sub> + 0,998X<sub>5</sub>"))
{
}

void modAltmana::calculate(EvgBasicModel *pInputData)
{
    // 2/9
    if (pInputData->getValue(8))
        pCoefficientRows[0]->setValue(pInputData->getValue(1)/pInputData->getValue(8));

    // 5/9
    if (pInputData->getValue(8))
        pCoefficientRows[1]->setValue(pInputData->getValue(4)/pInputData->getValue(8));

    // 12/9
    if (pInputData->getValue(8))
        pCoefficientRows[2]->setValue(pInputData->getValue(11)/pInputData->getValue(8));

    // 4/(7+8)
    if (pInputData->getValue(6) + pInputData->getValue(7))
        pCoefficientRows[3]->setValue(pInputData->getValue(3)/(pInputData->getValue(6) + pInputData->getValue(7)));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[4]->setValue(pInputData->getValue(9)/pInputData->getValue(8));

    if (checkForZeros())
        result = 0.717*pCoefficientRows[0]->getValue()\
                + 0.847*pCoefficientRows[1]->getValue()\
                + 3.107*pCoefficientRows[2]->getValue()\
                + 0.42*pCoefficientRows[3]->getValue()\
                + 0.998*pCoefficientRows[4]->getValue();
    else
    {
        result = 0.0f;
        _state = TypeStateUndefined;
        return;
    }

    if (result < 1.23f)
        _state = TypeStateUnstable;
    else if (result >= 1.23f && result < 2.90f)
        _state = TypeStateMiddle;
    else
        _state = TypeStateStable;
}

void modAltmana::setRowsDefinitions()
{
    pCoefficientRows[0]->setTextDefinition(tr("ф. 1. р. 260 / ф. 1. р. 640 – відношення оборотного капіталу до суми активів"));
    pCoefficientRows[1]->setTextDefinition(tr("ф. 1. р. 350 / ф. 1. р. 640 – відношення нерозподіленого прибутку до суми активів"));
    pCoefficientRows[2]->setTextDefinition(tr("ф. 2. р. 100 (105) / ф. 1. р. 640 – відношення операційного прибутку до суми активів"));
    pCoefficientRows[3]->setTextDefinition(tr("(ф. 1. р. 380 + 430 + 630) / (ф. 1. р. 480 + 620) – співвідношення між власним та позиковим капіталом"));
    pCoefficientRows[4]->setTextDefinition(tr("ф. 2. р. 035 / ф. 1. р. 640 – відношення чистого доходу до суми активів"));
}
