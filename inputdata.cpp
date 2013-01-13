#include "inputdata.h"

InputData::InputData(QWidget *parent) :
    EvgBasicModel(InputCount, parent, "qrc:/models/input", tr("Вихідні дані"), tr("Будь ласка, введіть вихідні дані:"))
{
    this->setEditable(TRUE);
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
    EvgBasicModel::createCentralLayout();
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
    pCoefficientRows[0]->setTextDefinition(tr("ф. 1. р. 080 Необоротні активи"));
    pCoefficientRows[1]->setTextDefinition(tr("ф. 1. р. 260 Оборотні активи"));
    pCoefficientRows[2]->setTextDefinition(tr("ф. 1. р. 270 Витрати майбутніх періодів"));
    pCoefficientRows[3]->setTextDefinition(tr("ф. 1. р. 300 Статутний капітал"));
    pCoefficientRows[4]->setTextDefinition(tr("ф. 1. р. 350 Нерозподілений прибуток"));
    pCoefficientRows[5]->setTextDefinition(tr("ф. 1. р. 380 Власний капітал"));
    pCoefficientRows[6]->setTextDefinition(tr("ф. 1. р. 480 Довгострокові зобов’язання"));
    pCoefficientRows[7]->setTextDefinition(tr("ф. 1. р. 620 Поточні зобов’язання"));
    pCoefficientRows[8]->setTextDefinition(tr("ф. 1. р. 640 Всього активів (валюта балансу)"));
    pCoefficientRows[9]->setTextDefinition(tr("ф. 2. р. 035 Чистий дохід від реалізації"));
    pCoefficientRows[10]->setTextDefinition(tr("ф. 2. р. 050 (055) Валовий прибуток (збиток)"));
    pCoefficientRows[11]->setTextDefinition(tr("ф. 2. р. 100 (105) Операційний прибуток (збиток)"));
    pCoefficientRows[12]->setTextDefinition(tr("ф. 2. р. 220 (225) Чистий прибуток (збиток)"));
    pCoefficientRows[13]->setTextDefinition(tr("ф. 2. р. 260 Амортизація"));
    pCoefficientRows[14]->setTextDefinition(tr("ф. 2. р. 070-090 Інтегральні витрати"));
}
