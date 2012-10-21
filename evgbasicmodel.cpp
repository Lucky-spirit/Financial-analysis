#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(int coefficientsCount, QWidget *parent, QString source, QString formulaText) :
    QWidget(parent),
    count(coefficientsCount),
    result(0.0f),
    textOfFormula("<h2>" + formulaText + "</h2>")
{
    pLabelFormula = new QLabel(textOfFormula, this);
    pLabelResult = new QLabel(tr("<h2> = ?</h2>"), this);
    createRows(count);

    pTextDefinitionModel = new evgTextBrowser(0);
    pTextDefinitionModel->setSource(QUrl(source));

    this->createTopLayout();
    this->createBottomLayout();
    this->createMainLayout();
}

EvgBasicModel::~EvgBasicModel()
{
    delete [] pCoefficientRows;
}

void EvgBasicModel::createRows(int countOfRows)
{
    pCoefficientRows = new EvgRow[countOfRows];

    for (int i = 0; i < countOfRows; i++)
        pCoefficientRows[i].setIdText(i + 1);
}

void EvgBasicModel::setResultValue(float value)
{
    QString result;
    pLabelResult->setText(result.setNum(value, 'g', 4));
}

void EvgBasicModel::createTopLayout()
{
    topLayout = new QHBoxLayout;
    topLayout->addStretch(1);
    topLayout->addWidget(pLabelFormula, 0);
    topLayout->addWidget(pLabelResult, 0);
    topLayout->addStretch(1);
}

void EvgBasicModel::createBottomLayout()
{
    bottomLayout = new QHBoxLayout;
    bottomLayout->addWidget(pTextDefinitionModel, 1);
}

void EvgBasicModel::createMainLayout()
{
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout, 0);
    mainLayout->addStretch(1);
    for (int i = 0; i < count; i++)
        mainLayout->addWidget(&(pCoefficientRows[i]), 0);
    mainLayout->addStretch(1);
    mainLayout->addLayout(bottomLayout, 0);
    this->setLayout(mainLayout);
}

double EvgBasicModel::getValue(int number) const
{
    return pCoefficientRows[number].getValue();
}
