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
    result = 12.57f;
}

void modSpringate::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 640 – відношення оборотного капіталу до суми активів;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 640 – відношення нерозподіленого прибутку до суми активів;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 620 – відношення нерозподіленого прибутку до суми поточних зобов’язань;"));
    pCoefficientRows[3].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів."));
}
