#ifndef MODGENERAL_H
#define MODGENERAL_H

#include "evgbasicmodel.h"

const int CountGeneral = 11;

class modGeneral : public EvgBasicModel
{
    Q_OBJECT
public:
    explicit modGeneral(QWidget *parent = 0);


    void setRowsDefinitions();
    void setCofficientName();

    void createTopLayout();
    void createCentralLayout();
    
signals:
    
public slots:
    void calculate(EvgBasicModel *pInputData);
    void calculate(int number, EvgBasicModel *model);

private:
    QString *modelsNames;
};

#endif // MODGENERAL_H
