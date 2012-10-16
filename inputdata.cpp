#include "inputdata.h"

InputData::InputData(QWidget *parent) :
    EvgBasicModel(8, parent)
{
    pTextDefinitionModel->hide();

    createCalculateButton();
}

void InputData::calculate()
{
}

void InputData::createCalculateButton()
{
    btnCalculate = new QPushButton(tr("Calculate all"), this);

    connect(btnCalculate, SIGNAL(clicked()), this, SIGNAL(signalCalculate()));
}
