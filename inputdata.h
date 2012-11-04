#ifndef INPUTDATA_H
#define INPUTDATA_H

#include "evgbasicmodel.h"

#include <QPushButton>

const int InputCount = 15;

class InputData : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit InputData(QWidget *parent = 0);

    void createCalculateButton();
    void createTopLayout();
    void createBottomLayout();
    void createCentralLayout();
    void createMainLayout();
    
signals:
    void signalCalculate();

public slots:
    void calculate(EvgBasicModel *pInputData);

private:
    void setRowsDefinitions();

    QPushButton *btnCalculate;
};

#endif // INPUTDATA_H
