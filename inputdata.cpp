#include "inputdata.h"

InputData::InputData(QWidget *parent) :
    EvgBasicModel(InputCount, parent, "qrc:/models/input", tr("Вихідні дані"), tr("Будь ласка, введіть вихідні дані:"))
{
}

void InputData::calculate(EvgBasicModel *pInputData)
{
    if (this != pInputData)
        qDebug("A-ah! Something wrong with Input");
}

void InputData::createCalculateButton()
{
    btnCalculate = new QPushButton(tr("Розрахувати все"), this);

    connect(btnCalculate, SIGNAL(clicked()), this, SIGNAL(signalCalculate()));
}

void InputData::createTopLayout()
{
    pLabelResult->hide();

    topLayout = new QHBoxLayout;
    topLayout->addStretch(1);
    topLayout->addWidget(pLabelFormula, 0);
    topLayout->addStretch(1);
}

void InputData::createBottomLayout()
{
    createCalculateButton();

    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch(3);
    bottomLayout->addWidget(btnCalculate, 2);
    bottomLayout->addStretch(3);
}

void InputData::createCentralLayout()
{
    this->EvgBasicModel::createCentralLayout();
    centralGrid->setSpacing(5);
}

void InputData::createMainLayout()
{
    mainLayout = new QVBoxLayout;

    mainLayout->addLayout(topLayout, 0);
    mainLayout->addStretch(1);
    mainLayout->addLayout(centralLayout);
    mainLayout->addStretch(1);
    mainLayout->addLayout(bottomLayout, 0);
    mainLayout->addStretch(1);
    mainLayout->addWidget(pTextDefinitionModel);
    this->setLayout(mainLayout);
}

void InputData::setRowsDefinitions()
{

}
