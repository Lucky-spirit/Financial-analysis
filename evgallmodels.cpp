#include "evgallmodels.h"

// Supporting comment
#include <iostream>

EvgAllModels::EvgAllModels(QObject *parent) :
    QObject(parent)
{
    createAllModels();
    setConnection();
}

EvgAllModels::~EvgAllModels()
{
}

EvgBasicModel * EvgAllModels::model(int model)
{
    return pAllModelsArray[model];
}

void EvgAllModels::calculateAllModels()
{
    qDebug("We have click!");
}

void EvgAllModels::createAllModels()
{
    pAllModelsArray[TypeModelMAX];
    for (int i = TypeModelInput; i < TypeModelMAX; i++)
    {
        pAllModelsArray[i] = createModel(i);
    }
}

EvgBasicModel* EvgAllModels::createModel(const int type)
{
    EvgBasicModel *pointer = NULL;

    switch (type)
    {
    case TypeModelInput :
        pointer = new InputData;
        break;
    case TypeModelAltman :
        pointer = new modAltmana;
        break;
    case TypeModelSpringate :
        pointer = new modSpringate;
        break;

    default :
        qDebug("Error with creating model %d.", type);
        break;
    }

    return pointer;
}

void EvgAllModels::setConnection()
{
    InputData *pInput = dynamic_cast< InputData * >(pAllModelsArray[TypeModelInput]);
    if (pInput)
        this->connect(pInput, SIGNAL(signalCalculate()), this, SLOT(calculateAllModels()));
}
