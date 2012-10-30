#include "modspringate.h"

modSpringate::modSpringate(QWidget *parent) :
    EvgBasicModel(CountSpringate, parent, "qrc:/models/springate", tr("Модель Г. Спрінгейта"), "Z=1,03X1+3,07X2+0,66X3+0,4X4")
{
}

void modSpringate::calculate(EvgBasicModel *pInputData)
{

}

void modSpringate::setRowsDefinitions()
{

}
