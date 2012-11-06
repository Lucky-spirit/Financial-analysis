#include "modlisa.h"

modLisa::modLisa(QWidget *parent) :
    EvgBasicModel(CountLisa,
                  parent,
                  tr("qrc:/models/lis"),
                  tr("Модель Р. Ліса"),
                  tr("Z=0,063Х1+0,092Х2+0,057Х3+0,001Х4"))
{
}

void modLisa::calculate(EvgBasicModel *pInputData)
{
    // 2/9
    if (pInputData->getValue(8))
        pCoefficientRows[0].setValue(pInputData->getValue(1)/pInputData->getValue(8));

    // 11/9
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue(pInputData->getValue(10)/pInputData->getValue(8));

    // 5/9
    if (pInputData->getValue(8))
        pCoefficientRows[2].setValue(pInputData->getValue(4)/pInputData->getValue(8));

    // 6/(7+8)
    if (pInputData->getValue(6) + pInputData->getValue(7))
        pCoefficientRows[3].setValue(pInputData->getValue(5)/(pInputData->getValue(6) + pInputData->getValue(7)));

    if (checkForZeros())
        result = 0.063*pCoefficientRows[0].getValue()\
                + 0.092*pCoefficientRows[1].getValue()\
                + 0.057*pCoefficientRows[2].getValue()\
                + 0.001*pCoefficientRows[3].getValue();
    else
        result = 0.0f;
}

void modLisa::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 640 – відношення оборотного капіталу до суми активів;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.2, р. 050(055) / ф.1, р. 640 – відношення валового прибутку до суми активів;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 640 – відношення нерозподіленого прибутку до суми активів;"));
    pCoefficientRows[3].setTextDefinition(tr("ф.1, р. 380 / (ф.1, р. 480+620) – відношення власного капіталу до суми зобов’язань."));
}
