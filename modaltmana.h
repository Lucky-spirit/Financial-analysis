#ifndef MODALTMANA_H
#define MODALTMANA_H

#include "evgbasicmodel.h"

class modAltmana : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modAltmana(QWidget *parent = 0);
    
signals:
    
public slots:
    void calculate();
};

#endif // MODALTMANA_H
