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
    pCoefficientRows[0].setTextDefinition(tr("080 Необоротні активи"));
    pCoefficientRows[1].setTextDefinition(tr("260 Оборотний капітал"));
    pCoefficientRows[2].setTextDefinition(tr("270 Витрати майбутніх періодів"));
    pCoefficientRows[3].setTextDefinition(tr("300 Статутний капітал"));
    pCoefficientRows[4].setTextDefinition(tr("350 Нерозподілений прибуток"));
    pCoefficientRows[5].setTextDefinition(tr("380 Власний капітал"));
    pCoefficientRows[6].setTextDefinition(tr("480 Довгострокові зобов'язання"));
    pCoefficientRows[7].setTextDefinition(tr("620 Поточні зобов'язання"));
    pCoefficientRows[8].setTextDefinition(tr("640 Сукупні активи (Валюта балансу)"));
    pCoefficientRows[9].setTextDefinition(tr("Чистий Дохід від реалізації"));
    pCoefficientRows[10].setTextDefinition(tr("Валовий прибуток"));
    pCoefficientRows[11].setTextDefinition(tr("Операційний прибуток"));
    pCoefficientRows[12].setTextDefinition(tr("Чистий прибуток"));
    pCoefficientRows[13].setTextDefinition(tr("Амортизація"));
    pCoefficientRows[14].setTextDefinition(tr("Інтегральні витрати"));
}
