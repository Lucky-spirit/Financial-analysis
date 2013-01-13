#include "moddavidovabelikov.h"

modDavidovaBelikov::modDavidovaBelikov(QWidget *parent) :
    EvgBasicModel(CountDavidovaBelikov,
                  parent,
                  tr("qrc:/models/davidovabelikov"),
                  tr("Модель Давидової-Бєлікова"),
                  tr("Z = 8,38X<sub>1</sub> + X<sub>2</sub> + 0,054X<sub>3</sub> + 0,63Х<sub>4</sub>"))
{
}

void modDavidovaBelikov::setRowsDefinitions()
{
    pCoefficientRows[0]->setTextDefinition(tr("(ф. 1. р. 260 + 270 - 620 - 630) / ф. 1. р. 640 – відношення робочого капіталу до суми активів"));
    pCoefficientRows[1]->setTextDefinition(tr("ф. 2. р. 220 (225) / ф. 1. р. 380 – відношення чистого прибутку до суми власного капіталу"));
    pCoefficientRows[2]->setTextDefinition(tr("ф. 2. р. 035 / ф. 1. р. 640 – відношення чистого доходу до суми активів"));
    pCoefficientRows[3]->setTextDefinition(tr("ф. 2. р. 220 (225) / (ф. 2. р. 070 + 080 + 090) – відношення чистого прибутку до інтегральних витрат"));
}

void modDavidovaBelikov::calculate(EvgBasicModel *pInputData)
{
    // ((2+3)-8)/9
    if (pInputData->getValue(8))
        pCoefficientRows[0]->setValue((pInputData->getValue(1)+pInputData->getValue(2)-pInputData->getValue(7))/pInputData->getValue(8));

    // 13/6
    if (pInputData->getValue(5))
        pCoefficientRows[1]->setValue(pInputData->getValue(12)/pInputData->getValue(5));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[2]->setValue(pInputData->getValue(9)/pInputData->getValue(8));

    // 13/15
    if (pInputData->getValue(14))
        pCoefficientRows[3]->setValue(pInputData->getValue(12)/pInputData->getValue(14));

    if (checkForZeros())
        result = 8.38f*pCoefficientRows[0]->getValue()\
                + pCoefficientRows[1]->getValue()\
                + 0.054f*pCoefficientRows[2]->getValue()\
                + 0.63f*pCoefficientRows[3]->getValue();
    else
    {
        result = 0.0f;
        _state = TypeStateUndefined;
        return;
    }

    if (result < 0.18)
        _state = TypeStateUnstable;
    else if (result >= 0.18 && result < 0.32)
        _state = TypeStateMiddle;
    else
        _state = TypeStateStable;
}
