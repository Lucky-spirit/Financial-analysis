#include "modaltmana.h"

modAltmana::modAltmana(QWidget *parent) :
    EvgBasicModel(CountAltmana, parent, "qrc:/models/altman", "Z=0,717X1+0,847X2+3,107X3+0,42X4+0,998X5")
{
}

void modAltmana::calculate(EvgBasicModel *pInputData)
{
    qDebug("Altmana calculate!");
}
