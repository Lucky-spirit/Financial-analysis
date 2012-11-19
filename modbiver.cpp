#include "modbiver.h"

modBiver::modBiver(QWidget *parent) :
    EvgBasicModel(CountBiver,
                  parent,
                  tr("qrc:/models/biver"),
                  tr("Модель Бівера"),
                  tr(""))
{
    pLabelResult->setText(tr(""));
}

void modBiver::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("– коефіцієнт Бівера;"));
    pCoefficientRows[1].setTextDefinition(tr("– рентабельність активів;"));
    pCoefficientRows[2].setTextDefinition(tr("– коефіцієнт фінансового левериджу;"));
    pCoefficientRows[3].setTextDefinition(tr("– коефіцієнт покриття активів обіговим капіталом;"));
    pCoefficientRows[4].setTextDefinition(tr("– коефіцієнт загальної ліквідності."));
}

void modBiver::calculate(EvgBasicModel *pInputData)
{
    // 2/9
    if (pInputData->getValue(8))
        pCoefficientRows[0].setValue(pInputData->getValue(1)/pInputData->getValue(8));

    // 5/9
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue(pInputData->getValue(4)/pInputData->getValue(8));

    // 12/9
    if (pInputData->getValue(8))
        pCoefficientRows[2].setValue(pInputData->getValue(11)/pInputData->getValue(8));

    // 4/(7+8)
    if (pInputData->getValue(6) + pInputData->getValue(7))
        pCoefficientRows[3].setValue(pInputData->getValue(3)/(pInputData->getValue(6) + pInputData->getValue(7)));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[4].setValue(pInputData->getValue(9)/pInputData->getValue(8));

    if (checkForZeros())
        result = 0.717*pCoefficientRows[0].getValue()\
                + 0.847*pCoefficientRows[1].getValue()\
                + 3.107*pCoefficientRows[2].getValue()\
                + 0.42*pCoefficientRows[3].getValue()\
                + 0.998*pCoefficientRows[4].getValue();
    else
        result = 0.0f;
}
