#include "inputdata.h"

InputData::InputData(QWidget *parent) :
    EvgBasicModel(InputCount, parent, "", tr("Пожалуйста, введите исходные данные:"))
{
    this->createTopLayout();
    this->createBottomLayout();
    this->createMainLayout();
}

void InputData::calculate()
{
}

void InputData::createCalculateButton()
{
    btnCalculate = new QPushButton(tr("Рассчитать все"), this);

    connect(btnCalculate, SIGNAL(clicked()), this, SIGNAL(signalCalculate()));
}

void InputData::createTopLayout()
{
    if (topLayout != NULL)
    {
        delete topLayout;
        topLayout = NULL;
    }

    if (pLabelResult != NULL)
        pLabelResult->hide();

    topLayout = new QHBoxLayout;
    topLayout->addStretch(1);
    topLayout->addWidget(pLabelFormula, 0);
    topLayout->addStretch(1);
}

void InputData::createBottomLayout()
{
    // pTextDefinitionModel->hide();

    createCalculateButton();

    if (bottomLayout != NULL)
    {
        delete bottomLayout;
        bottomLayout = NULL;
    }

    bottomLayout = new QHBoxLayout;
    bottomLayout->addStretch(3);
    bottomLayout->addWidget(btnCalculate, 2);
    bottomLayout->addStretch(3);
}

void InputData::createMainLayout()
{
    if (mainLayout != NULL)
    {
        delete mainLayout;
        mainLayout = NULL;
    }

    mainLayout = new QVBoxLayout;

    mainLayout->addLayout(topLayout, 0);
    mainLayout->addStretch(1);
    for (int i = 0; i < count; i++)
        mainLayout->addWidget(&(pCoefficientRows[i]), 0);
    mainLayout->addStretch(1);
    mainLayout->addLayout(bottomLayout, 0);
    mainLayout->addStretch(1);
    mainLayout->addWidget(pTextDefinitionModel);
    this->setLayout(mainLayout);
}
