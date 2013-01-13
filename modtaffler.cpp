#include "modtaffler.h"

modTaffler::modTaffler(QWidget *parent) :
    EvgBasicModel(CountTaffler,
                  parent,
                  tr("qrc:/models/taffler"),
                  tr("Модель Р. Таффлера"),
                  tr("Z = 0,53X<sub>1</sub> + 0,13X<sub>2</sub> + 0,18X<sub>3</sub> + 0,16X<sub>4</sub>"))
{
}

void modTaffler::calculate(EvgBasicModel *pInputData)
{
    // 11/8
    if (pInputData->getValue(7))
        pCoefficientRows[0]->setValue(pInputData->getValue(10)/pInputData->getValue(7));

    // 2/(7+8)
    if (pInputData->getValue(6) + pInputData->getValue(7))
        pCoefficientRows[1]->setValue(pInputData->getValue(1)/(pInputData->getValue(6) + pInputData->getValue(7)));

    // 8/9
    if (pInputData->getValue(8))
        pCoefficientRows[2]->setValue(pInputData->getValue(7)/pInputData->getValue(8));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[3]->setValue(pInputData->getValue(9)/pInputData->getValue(8));

    if (checkForZeros())
        result = 0.53*pCoefficientRows[0]->getValue()\
                + 0.13*pCoefficientRows[1]->getValue()\
                + 0.18*pCoefficientRows[2]->getValue()\
                + 0.16*pCoefficientRows[3]->getValue();
    else
    {
        result = 0.0f;
        _state = TypeStateUndefined;
        return ;
    }

    if (result < 0.2)
        _state = TypeStateUnstable;
    else if (result >= 0.2 && result < 0.3)
        _state = TypeStateMiddle;
    else
        _state = TypeStateStable;
}

void modTaffler::setRowsDefinitions()
{
    pCoefficientRows[0]->setTextDefinition(tr("ф. 2. р. 050 (055) / ф.1. р. 620 – відношення валового прибутку до суми поточних зобов'язань"));
    pCoefficientRows[1]->setTextDefinition(tr("ф. 1. р. 260 / (ф. 1. р. 480 + 620) – відношення оборотних активів до суми зобов'язань"));
    pCoefficientRows[2]->setTextDefinition(tr("ф. 1. р. 620 / ф.1. р. 640 – відношення поточних зобов’язань до суми активів"));
    pCoefficientRows[3]->setTextDefinition(tr("ф. 2. р. 035 / ф.1. р. 640 – відношення чистого доходу до суми активів"));
}
