#ifndef EVGALLMODELS_H
#define EVGALLMODELS_H

#include <QObject>
#include "inputdata.h"
#include "modaltmana.h"
#include "modspringate.h"
#include "modtaffler.h"
#include "modlisa.h"
#include "modbiver.h"
#include "moddavidovabelikov.h"
#include "modsajfulinkadikov.h"
#include "modsavickaja.h"
#include "modtereschenko.h"
#include "modchupis.h"
#include "modgeneral.h"

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
    TypeModelGeneral,
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
