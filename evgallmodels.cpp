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
        for (int i = TypeModelInput; i < TypeModelGeneral; i++)
        {
            pAllModelsArray[i]->calculate(input);
            pAllModelsArray[i]->setResultValue();
        }
    }

    modGeneral *genModel = dynamic_cast< modGeneral * > (pAllModelsArray[TypeModelGeneral]);
    if (genModel)
    {for (int i = TypeModelAltman; i < TypeModelGeneral; i++)
            genModel->calculate(i, pAllModelsArray[i]);
    }
}

void EvgAllModels::createAllModels()
{
    // pAllModelsArray[TypeModelMAX];
    for (int i = TypeModelInput; i < TypeModelMAX; i++)
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
    case TypeModelTaffler :
        pointer = new modTaffler;
        break;
    case TypeModelLis :
        pointer = new modLisa;
        break;
    case TypeModelBiver :
        pointer = new modBiver;
        break;
    case TypeModelDavidovaBelikova :
        pointer = new modDavidovaBelikov;
        break;
    case TypeModelSajfulinKadikov :
        pointer = new modSajfulinKadikov;
        break;
    case TypeModelSavickaja :
        pointer = new modSavickaja;
        break;
    case TypeModelTereschenko :
        pointer = new modTereschenko;
        break;
    case TypeModelChupis :
        pointer = new modChupis;
        break;
    case TypeModelGeneral :
        pointer = new modGeneral;
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
