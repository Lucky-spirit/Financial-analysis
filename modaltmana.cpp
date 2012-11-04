#include "modaltmana.h"

modAltmana::modAltmana(QWidget *parent) :
    EvgBasicModel(CountAltmana,
                  parent,
                  tr("qrc:/models/altman"),
                  tr("Модель Альтмана"),
                  tr("Z=0,717X1+0,847X2+3,107X3+0,42X4+0,998X5"))
{
}

void modAltmana::calculate(EvgBasicModel *pInputData)
{
    qDebug("Altmana calculate!");

    pCoefficientRows[0].setValue(7.5f);

    result = 13.57f;
}

void modAltmana::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("ф.1, р. 260 / ф.1, р. 640 – відношення оборотного капіталу до суми активів;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.1, р. 350 / ф.1, р. 640 – відношення нерозподіленого прибутку до суми активів;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.2, р. 100(105) / ф.1, р. 640 – відношення операційного прибутку до суми активів;"));
    pCoefficientRows[3].setTextDefinition(tr("(ф.1, р. 380+430+630) / (ф.1, р. 480+620) – співвідношення між власним та позиковим капіталом;"));
    pCoefficientRows[4].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів."));
}
