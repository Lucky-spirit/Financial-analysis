#include "modbiver.h"

modBiver::modBiver(QWidget *parent) :
    EvgBasicModel(CountBiver,
                  parent,
                  tr("qrc:/models/biver"),
                  tr("Модель Бівера"),
                  tr("Система коефіцієнтів У.Бівера"))
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

void modBiver::setResultValue()
{
    pLabelResult->setText(tr(""));
}

void modBiver::calculate(EvgBasicModel *pInputData)
{
    // (13+14)/(7+8)
    if (pInputData->getValue(6) + pInputData->getValue(7))
        pCoefficientRows[0].setValue((pInputData->getValue(12) + pInputData->getValue(13))/(pInputData->getValue(6) + pInputData->getValue(7)));

    // (11/9)*100
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue(pInputData->getValue(10)/pInputData->getValue(8) * 100.0f);

    // (7+8)/(9-7-8)
    if (pInputData->getValue(8) - pInputData->getValue(6) - pInputData->getValue(7))
        pCoefficientRows[2].setValue((pInputData->getValue(6) + pInputData->getValue(7))\
                                     / pInputData->getValue(8) - pInputData->getValue(6) - pInputData->getValue(7));

    // 2/9
    if (pInputData->getValue(8))
        pCoefficientRows[3].setValue(pInputData->getValue(1)/pInputData->getValue(8));

    // 2/8
    if (pInputData->getValue(7))
        pCoefficientRows[4].setValue(pInputData->getValue(1)/pInputData->getValue(7));
}
