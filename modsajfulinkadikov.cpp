#include "modsajfulinkadikov.h"

modSajfulinKadikov::modSajfulinKadikov(QWidget *parent) :
    EvgBasicModel(CountSajfulinKadikov,
                  parent,
                  tr("qrc:/models/sajfulinkadikov"),
                  tr("Модель Сайфулліна і Кадикова"),
                  tr("Z=2Х1+0,1Х2+0,08Х3+0,45Х4+Х5"))
{
}

void modSajfulinKadikov::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("(ф.1, р. 380-080)/ ф.1, р. 260 – коефіцієнт забезпеченості власними засобами;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 620 – коефіцієнт поточної ліквідності;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів;"));
    pCoefficientRows[3].setTextDefinition(tr("ф.2, р. 050(055) / ф.2, р. 035 – коефіцієнт менеджменту, який характеризується відношенням прибутку від реалізації до величини виручки від реалізації;"));
    pCoefficientRows[4].setTextDefinition(tr("ф.2, р. 050(055) / ф.1, р. 380 – рентабельність власного капіталу."));
}

void modSajfulinKadikov::calculate(EvgBasicModel *pInputData)
{
    // (6-1)/2
    if (pInputData->getValue(1))
        pCoefficientRows[0].setValue((pInputData->getValue(5)-pInputData->getValue(0))/pInputData->getValue(1));

    // 2/8
    if (pInputData->getValue(7))
        pCoefficientRows[1].setValue(pInputData->getValue(1)/pInputData->getValue(7));

    // 10/9
    if (pInputData->getValue(8))
        pCoefficientRows[2].setValue(pInputData->getValue(9)/pInputData->getValue(8));

    // 11/10
    if (pInputData->getValue(9))
        pCoefficientRows[3].setValue(pInputData->getValue(10)/pInputData->getValue(9));

    // 11/6
    if (pInputData->getValue(5))
        pCoefficientRows[4].setValue(pInputData->getValue(10)/pInputData->getValue(5));

    if (checkForZeros())
        result = 2.0f*pCoefficientRows[0].getValue()\
                + 0.1f*pCoefficientRows[1].getValue()\
                + 0.08f*pCoefficientRows[2].getValue()\
                + 0.45f*pCoefficientRows[3].getValue()\
                + pCoefficientRows[4].getValue();
    else
        result = 0.0f;
}
