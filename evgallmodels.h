#ifndef EVGALLMODELS_H
#define EVGALLMODELS_H

#include <QObject>
#include "inputdata.h"
#include "modaltmana.h"
#include "modspringate.h"
#include "modtaffler.h"
#include "modlisa.h"

enum modelTypes {
    TypeModelInput,
    TypeModelAltman,
    TypeModelSpringate,
    TypeModelTaffler,
    TypeModelLis,
    TypeModelBiver,
    TypeModelDavidovaBelikova,
    TypeModelSajfulinKadikov,
    TypeModelSavickaja,
    TypeModelTereschenko,
    TypeModelChupis,
    TypeModelMAX
};

class EvgAllModels : public QObject
{
    Q_OBJECT
public:
    explicit EvgAllModels(QObject *parent = 0);
    ~EvgAllModels();

    EvgBasicModel *model(int model);

    void createAllModels();
    EvgBasicModel *createModel(const int);
    void setConnection();
    
signals:

public slots:
    void calculateAllModels();

private:
    EvgBasicModel *pAllModelsArray[TypeModelMAX];
};

#endif // EVGALLMODELS_H
