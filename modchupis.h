#ifndef MODCHUPIS_H
#define MODCHUPIS_H

#include "evgbasicmodel.h"

const int CountChupis = 2;

class modChupis : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modChupis(QWidget *parent = 0);

    void setRowsDefinitions();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODCHUPIS_H
