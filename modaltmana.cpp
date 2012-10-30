#include "modaltmana.h"

modAltmana::modAltmana(QWidget *parent) :
    EvgBasicModel(CountAltmana, parent, "qrc:/models/altman", tr("Модель Альтмана"), "Z=0,717X1+0,847X2+3,107X3+0,42X4+0,998X5")
{
}

void modAltmana::calculate(EvgBasicModel *pInputData)
{
    qDebug("Altmana calculate!");


}

void modAltmana::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 640 – відношення оборотного капіталу до суми активів"));
}
