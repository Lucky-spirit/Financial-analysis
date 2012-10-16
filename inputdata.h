#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "evgbasicmodel.h"

#include <QPushButton>

class InputData : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit InputData(QWidget *parent = 0);

    void createCalculateButton();
    
signals:
    void signalCalculate();

public slots:
    void calculate();

private:
    QPushButton *btnCalculate;
};

#endif // INPUTDATA_H
