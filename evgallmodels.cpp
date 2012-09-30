#include "evgallmodels.h"

// Supporting comment
#include <iostream>

EvgAllModels::EvgAllModels(QObject *parent) :
    QObject(parent)
{
    pInputModel = new InputData;
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
    case modelInput :
        return pInputModel;
        break;

    case modelAltman :
        return NULL;
        break;

    default :
        std::cerr << "Error in EvgAllModels.model()!" << std::endl;
        return NULL;
        break;
    }
}

void EvgAllModels::calculateAllModels()
{

}
