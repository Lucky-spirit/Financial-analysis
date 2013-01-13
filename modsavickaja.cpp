#include "modsavickaja.h"

modSavickaja::modSavickaja(QWidget *parent) :
    EvgBasicModel(CountSavickaja,
                  parent,
                  tr("qrc:/models/savickaja"),
                  tr("Модель Савицької"),
                  tr("Z = 1 – 0,98Х<sub>1</sub> – 1,8Х<sub>2</sub> – 1,83Х<sub>3</sub> - 0,28Х<sub>4</sub>"))
{
}

void modSavickaja::setRowsDefinitions()
{
    pCoefficientRows[0]->setTextDefinition(tr("(ф. 1. р. 260 + 270 - 620 - 630) / ф. 1. р. 640 – відношення робочого капіталу до суми активів"));
    pCoefficientRows[1]->setTextDefinition(tr("ф. 2. р. 035 / ф. 1. р. 260 – відношення чистого доходу до суми оборотних активів"));
    pCoefficientRows[2]->setTextDefinition(tr("ф. 1. р. 380 / ф. 1. р. 640 – відношення власного капіталу до суми активів"));
    pCoefficientRows[3]->setTextDefinition(tr("ф. 2. р. 220 (225) / ф. 1. р. 380 – відношення чистого прибутку до власного капіталу"));
}

void modSavickaja::calculate(EvgBasicModel *pInputData)
{
    // ((2+3)-8)/9
    if (pInputData->getValue(8))
        pCoefficientRows[0]->setValue((pInputData->getValue(1)+pInputData->getValue(2)-pInputData->getValue(7))/pInputData->getValue(8));

    // 10/2
    if (pInputData->getValue(1))
        pCoefficientRows[1]->setValue(pInputData->getValue(9)/pInputData->getValue(1));

    // 6/9
    if (pInputData->getValue(8))
        pCoefficientRows[2]->setValue(pInputData->getValue(5)/pInputData->getValue(8));

    // 13/6*100
    if (pInputData->getValue(5))
        pCoefficientRows[3]->setValue(pInputData->getValue(12)/pInputData->getValue(5)*100.0f);

    if (checkForZeros())
        result = 1.0f - 0.98f*pCoefficientRows[0]->getValue()\
                - 1.8f*pCoefficientRows[1]->getValue()\
                - 1.83f*pCoefficientRows[2]->getValue()\
                - 0.28f*pCoefficientRows[3]->getValue();
    else
    {
        result = 0.0f;
        _state = TypeStateUndefined;
        return;
    }

    if (result >= 1)
        _state = TypeStateUnstable;
    else if (result < 1 && result >= 0)
        _state = TypeStateMiddle;
    else
        _state = TypeStateStable;
}
