#ifndef MODLISA_H
#define MODLISA_H

#include "evgbasicmodel.h"

const int CountLisa = 4;

class modLisa : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modLisa(QWidget *parent = 0);

    void setRowsDefinitions();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODLISA_H
