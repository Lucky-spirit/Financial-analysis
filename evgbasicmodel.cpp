#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(int coefficientsCount, QWidget *parent, QString source, QString formulaText) :
    QWidget(parent),
    count(coefficientsCount),
    textOfFormula("<h2>" + formulaText + "</h2>")
{
    pLabelFormula = new QLabel(textOfFormula, this);
    pLabelResult = new QLabel(tr("Result"), this);
    createRows(count);

    pTextDefinitionModel = new evgTextBrowser(0);
    pTextDefinitionModel->setSource(QUrl(source));

    QHBoxLayout *layoutHor = new QHBoxLayout;
    layoutHor->addStretch(1);
    layoutHor->addWidget(pLabelFormula, 0);
    layoutHor->addWidget(pLabelResult, 0);
    layoutHor->addStretch(1);

    QHBoxLayout *pLayoutHorBottom = new QHBoxLayout;
    pLayoutHorBottom->addWidget(pTextDefinitionModel, 1);

    QVBoxLayout *layoutVertical = new QVBoxLayout;
    layoutVertical->addLayout(layoutHor, 0);
    layoutVertical->addStretch(1);
    for (int i = 0; i < count; i++)
        layoutVertical->addWidget(&(pCoefficientRows[i]), 0);
    layoutVertical->addStretch(1);
    layoutVertical->addLayout(pLayoutHorBottom, 0);

    this->setLayout(layoutVertical);
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
