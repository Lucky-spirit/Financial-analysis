#include "modspringate.h"

modSpringate::modSpringate(QWidget *parent) :
    EvgBasicModel(CountSpringate,
                  parent,
                  tr("qrc:/models/springate"),
                  tr("Модель Г. Спрінгейта"),
                  tr("Z=1,03X1+3,07X2+0,66X3+0,4X4"))
{
}

void modSpringate::calculate(EvgBasicModel *pInputData)
{
    // 2/9
    if (pInputData->getValue(8))
        pCoefficientRows[0].setValue(pInputData->getValue(1)/pInputData->getValue(8));

    // 5/9
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue(pInputData->getValue(4)/pInputData->getValue(8));

    // 5/8
    if (pInputData->getValue(7))
        pCoefficientRows[2].setValue(pInputData->getValue(4)/pInputData->getValue(7));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[3].setValue(pInputData->getValue(9)/pInputData->getValue(8));

    if (checkForZeros())
        result = 1.03*pCoefficientRows[0].getValue()\
                + 3.07*pCoefficientRows[1].getValue()\
                + 0.66*pCoefficientRows[2].getValue()\
                + 0.4*pCoefficientRows[3].getValue();
    else
        result = 0.0f;
}

void modSpringate::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 640 – відношення оборотного капіталу до суми активів;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 640 – відношення нерозподіленого прибутку до суми активів;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 620 – відношення нерозподіленого прибутку до суми поточних зобов’язань;"));
    pCoefficientRows[3].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів."));
}
