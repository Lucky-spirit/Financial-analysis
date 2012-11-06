#ifndef MODTAFFLER_H
#define MODTAFFLER_H

#include "evgbasicmodel.h"

const int CountTaffler = 4;

class modTaffler : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modTaffler(QWidget *parent = 0);

    void setRowsDefinitions();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODTAFFLER_H
