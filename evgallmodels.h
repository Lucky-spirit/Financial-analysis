#ifndef EVGALLMODELS_H
#define EVGALLMODELS_H

#include <QObject>
#include "inputdata.h"
#include "modaltmana.h"

enum modelTypes {
    TypeModelInput,
    TypeModelAltman
};

class EvgAllModels : public QObject
{
    Q_OBJECT
public:
    explicit EvgAllModels(QObject *parent = 0);
    ~EvgAllModels();

    EvgBasicModel* model(modelTypes model) const;
    
signals:

public slots:
    void calculateAllModels();

private:
    int count;
    InputData *pInputModel;
    modAltmana *pModAltmana;
};

#endif // EVGALLMODELS_H
