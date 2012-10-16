#include "evgallmodels.h"

// Supporting comment
#include <iostream>

EvgAllModels::EvgAllModels(QObject *parent) :
    QObject(parent),
    count(1)
{
    pInputModel = new InputData;

    connect(pInputModel, SIGNAL(signalCalculate()), this, SLOT(calculateAllModels()));

    pModAltmana = new modAltmana;
}

EvgAllModels::~EvgAllModels()
{
    // Supporting comment
    std::cout << "EvgAllModels destructor is called!" << std::endl;
}

EvgBasicModel* EvgAllModels::model(modelTypes model) const
{
    switch (model)
    {
    case TypeModelInput :
        return pInputModel;
        break;

    case TypeModelAltman :
        return pModAltmana;
        break;

    default :
        std::cerr << "Error in EvgAllModels.model()!" << std::endl;
        return NULL;
        break;
    }
}

void EvgAllModels::calculateAllModels()
{
    qDebug("We have click!");

    EvgBasicModel* pointersArray[] = {pModAltmana};

    for (int i = 0; i < count; i++)
        pointersArray[i]->calculate();
}
