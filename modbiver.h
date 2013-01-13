#ifndef MODBIVER_H
#define MODBIVER_H

#include "evgbasicmodel.h"

const int CountBiver = 5;

class modBiver : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modBiver(QWidget *parent = 0);

    float getResult() const;

    void setRowsDefinitions();
    void setResultValue();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODBIVER_H
