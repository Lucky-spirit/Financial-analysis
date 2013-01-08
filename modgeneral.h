#ifndef MODGENERAL_H
#define MODGENERAL_H

#include "evgbasicmodel.h"
#include "extendrow.h"

const int CountGeneral = 10;

class modGeneral : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modGeneral(QWidget *parent = 0);

    void setRowsDefinitions();
    void createRows(int countOfRows);
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODGENERAL_H
