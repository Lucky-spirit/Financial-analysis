#ifndef MODDAVIDOVABELIKOV_H
#define MODDAVIDOVABELIKOV_H

#include "evgbasicmodel.h"

const int CountDavidovaBelikov = 4;

class modDavidovaBelikov : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modDavidovaBelikov(QWidget *parent = 0);

    void setRowsDefinitions();

signals:

public slots:
    void calculate(EvgBasicModel *pInputData);
};

#endif // MODDAVIDOVABELIKOV_H
