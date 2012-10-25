#ifndef MODSPRINGATE_H
#define MODSPRINGATE_H

#include "evgbasicmodel.h"

const int CountSpringate = 4;

class modSpringate : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modSpringate(QWidget *parent = 0);
    

signals:

public slots:
    void calculate(EvgBasicModel *pInputData);

private:
    void setRowsDefinitions();
};

#endif // MODSPRINGATE_H
