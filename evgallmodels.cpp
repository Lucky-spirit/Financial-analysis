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
    InputData *input = dynamic_cast< InputData * > (pAllModelsArray[TypeModelInput]);

    if (input)
    {
        for (int i = TypeModelInput; i < TypeModelTaffler; i++)
        {
            // pAllModelsArray[i]->setEditable();
            pAllModelsArray[i]->calculate(input);
            pAllModelsArray[i]->setResultValue();
        }
    }
}

void EvgAllModels::createAllModels()
{
    pAllModelsArray[TypeModelMAX];
    for (int i = TypeModelInput; i < TypeModelTaffler; i++)
    {
        pAllModelsArray[i] = createModel(i);
        pAllModelsArray[i]->setRowsDefinitions();
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

    if (pointer)
    {
        pointer->createTopLayout();
        pointer->createBottomLayout();
        pointer->createCentralLayout();
        pointer->createMainLayout();
    }

    return pointer;
}

void EvgAllModels::setConnection()
{
    InputData *pInput = dynamic_cast< InputData * >(pAllModelsArray[TypeModelInput]);
    if (pInput)
        this->connect(pInput, SIGNAL(signalCalculate()), this, SLOT(calculateAllModels()));
}
