#ifndef MODALTMANA_H
#define MODALTMANA_H

#include "evgbasicmodel.h"

const int CountAltmana = 5;

class modAltmana : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modAltmana(QWidget *parent = 0);
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);

protected:
    void setRowsDefinitions();
};

#endif // MODALTMANA_H
