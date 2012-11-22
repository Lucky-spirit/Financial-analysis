#include "modtereschenko.h"

modTereschenko::modTereschenko(QWidget *parent) :
    EvgBasicModel(CountTereschenko,
                  parent,
                  tr("qrc:/models/tereschenko"),
                  tr("Модель Терещенко"),
                  tr("Z=0,105Х1+1,567Х2+0,301Х3+1,375Х4+1,689Х5+0,168Х6-0,260"))
{
}

void modTereschenko::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 620 – коефіцієнт загальної ліквідності;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.1, р. 380 / ф.1, р. 640 – відношення власного капіталу до суми активів;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів;"));
    pCoefficientRows[3].setTextDefinition(tr("(ф.2, р. 220(225)+260) / ф.2, р. 035 – коефіцієнт рентабельності операційного продажу за грошовим потоком;"));
    pCoefficientRows[4].setTextDefinition(tr("ф.2, р. 050(055) / ф.2, р. 035 – відношення валового прибутку до чистого доходу;"));
    pCoefficientRows[5].setTextDefinition(tr("ф.2, р. 220(225) / ф.1, р. 380 – відношення чистого прибутку підприємства до суми власного капіталу."));
}

void modTereschenko::calculate(EvgBasicModel *pInputData)
{
    // 2/8
    if (pInputData->getValue(7))
        pCoefficientRows[0].setValue(pInputData->getValue(1)/pInputData->getValue(7));

    // 6/9
    if (pInputData->getValue(8))
        pCoefficientRows[1].setValue(pInputData->getValue(5)/pInputData->getValue(8));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[2].setValue(pInputData->getValue(9)/pInputData->getValue(8));

    // (13+14)/10
    if (pInputData->getValue(9))
        pCoefficientRows[3].setValue((pInputData->getValue(12)+pInputData->getValue(13))/pInputData->getValue(9));

    // 11/10
    if (pInputData->getValue(9))
        pCoefficientRows[4].setValue(pInputData->getValue(10)/pInputData->getValue(9));

    // 13/6
    if (pInputData->getValue(5))
        pCoefficientRows[5].setValue(pInputData->getValue(12)/pInputData->getValue(5));

    if (checkForZeros())
        result = 0.105f*pCoefficientRows[0].getValue()\
                + 1.567f*pCoefficientRows[1].getValue()\
                + 0.301f*pCoefficientRows[2].getValue()\
                + 1.375f*pCoefficientRows[3].getValue()\
                + 1.689f*pCoefficientRows[4].getValue()\
                + 0.168f*pCoefficientRows[5].getValue() - 0.26f;
    else
        result = 0.0f;
}
