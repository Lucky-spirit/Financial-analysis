#ifndef MODSAJFULINKADIKOV_H
#define MODSAJFULINKADIKOV_H

#include "evgbasicmodel.h"

const int CountSajfulinKadikov = 5;

class modSajfulinKadikov : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modSajfulinKadikov(QWidget *parent = 0);

    void setRowsDefinitions();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODSAJFULINKADIKOV_H
