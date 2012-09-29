#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "evgbasicmodel.h"

class InputData : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit InputData(QWidget *parent = 0);
    
signals:
    
public slots:
    void calculate();
};

#endif // INPUTDATA_H
