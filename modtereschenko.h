#ifndef MODTERESCHENKO_H
#define MODTERESCHENKO_H

#include "evgbasicmodel.h"

const int CountTereschenko = 6;

class modTereschenko : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modTereschenko(QWidget *parent = 0);
    
    void setRowsDefinitions();

signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODTERESCHENKO_H
