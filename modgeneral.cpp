#include "modgeneral.h"

modGeneral::modGeneral(QWidget *parent) :
    EvgBasicModel(CountGeneral,
                  parent,
                  tr("qrc:/models/general"),
                  tr("Узагальнююча Модель"),
                  tr("Z=0,105Х1+1,567Х2+0,301Х3+1,375Х4+1,689Х5+0,168Х6-0,260"))
{
}

void modGeneral::setRowsDefinitions()
{
    pCoefficientRows[0].setTextDefinition(tr("(ф.1, р. 260+270-620-630)/ ф.1, р. 640 – відношення робочого капіталу до суми активів;"));
    pCoefficientRows[1].setTextDefinition(tr("ф.2, р. 220(225) / ф.1, р. 380– відношення чистого прибутку до суми власного капіталу;"));
    pCoefficientRows[2].setTextDefinition(tr("ф.2, р. 035 / ф.1, р. 640 – відношення чистого доходу до суми активів;"));
    pCoefficientRows[3].setTextDefinition(tr("ф.2, р. 220(225) / (ф.2, р. 070+080+090) – відношення чистого прибутку до інтегральних витрат."));
}

void modGeneral::createRows(int countOfRows)
{
    pCoefficientRows = new ExtendRow[countOfRows];

    for (int i = 0; i < countOfRows; i++)
        pCoefficientRows[i].setIdText(i + 1);
}

void modGeneral::calculate(EvgBasicModel *pInputData)
{

}
