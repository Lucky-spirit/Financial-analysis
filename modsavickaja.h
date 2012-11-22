#ifndef MODSAVICKAJA_H
#define MODSAVICKAJA_H

#include "evgbasicmodel.h"

const int CountSavickaja = 4;

class modSavickaja : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modSavickaja(QWidget *parent = 0);

    void setRowsDefinitions();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODSAVICKAJA_H
