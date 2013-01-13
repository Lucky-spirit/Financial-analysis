#include "modgeneral.h"

modGeneral::modGeneral(QWidget *parent) :
    EvgBasicModel(CountGeneral,
                  parent,
                  tr("qrc:/models/general"),
                  tr("Узагальнююча Модель"),
                  tr(""),
                  1)
{

    setCofficientName();
}

void modGeneral::setRowsDefinitions()
{
    // Job of this function makes next func.
    // void modGeneral::setCofficientName()
    // Thanks for it! :-)
}

void modGeneral::setCofficientName()
{
    QString MODELS_NAMES[] = {tr("Модель Альтмана 1983 р."),
                              tr("Модель Г. Спрінгейта"),
                              tr("Модель Р. Таффлера"),
                              tr("Модель Р. Ліса"),
                              tr("Коефіцієнт У. Бівера"),
                              tr("Модель Давидової-Бєлікова"),
                              tr("Модель Сайфулліна і Кадикова"),
                              tr("Модель Савицької"),
                              tr("Модель Терещенка"),
                              tr("Модель Чупіса"),
                              tr("Узагальнююча оцінка")};

    for (int i = 0; i < count; i++)
    {
        pCoefficientRows[i]->changeIdToText(MODELS_NAMES[i]);
        pCoefficientRows[i]->setStringByState(TypeStateUndefined);
    }
}

void modGeneral::createTopLayout()
{
    pLabelResult->hide();
    pLabelFormula->hide();

    topLayout = new QHBoxLayout;
}

void modGeneral::createCentralLayout()
{
    EvgBasicModel::createCentralLayout();
    centralGrid->setSpacing(10);
}


void modGeneral::calculate(EvgBasicModel *pInputData)
{
    if (this != pInputData)
    {
        qDebug("Error in modGeneral::%s", __FUNCTION__);
        return;
    }

    result = (pCoefficientRows[0]->getValue()/2.065
              + pCoefficientRows[1]->getValue()/ 0.862
              + pCoefficientRows[2]->getValue()/ 0.25
              + pCoefficientRows[3]->getValue()/ 0.037
              + pCoefficientRows[4]->getValue()/ 0.31
              + pCoefficientRows[5]->getValue()/ 0.25
              + pCoefficientRows[6]->getValue()
              - pCoefficientRows[7]->getValue()/ 0.5
              + pCoefficientRows[8]->getValue()/ 0.16
              - pCoefficientRows[9]->getValue()) / 10;

    pCoefficientRows[10]->setValue(result);

    if (result < -0.434)
        _state = TypeStateUnstable;
    else if (result >= -0.434 && result <= 1.234)
        _state = TypeStateMiddle;
    else
        _state = TypeStateStable;
}

void modGeneral::calculate(int number, EvgBasicModel *model)
{
    pCoefficientRows[number-1]->setValue(model->getResult());
    pCoefficientRows[number-1]->setStringByState(model->getState());
    calculate(this);
}

