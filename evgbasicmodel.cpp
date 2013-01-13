#include "evgbasicmodel.h"

EvgBasicModel::EvgBasicModel(int coefficientsCount, QWidget *parent, QString source, QString modelName, QString formulaText, bool extended) :
    QWidget(parent),
    count(coefficientsCount),
    result(0.0f),
    name(modelName),
    textOfFormula("<h2>" + formulaText + "</h2>"),
    _state(TypeStateUndefined)
{
    pLabelFormula = new QLabel(textOfFormula, this);
    pLabelResult = new QLabel(tr("<h2> = ?</h2>"), this);
    createRows(extended);

    pTextDefinitionModel = new evgTextBrowser(0);
    pTextDefinitionModel->setSource(QUrl(source));
}

EvgBasicModel::~EvgBasicModel()
{
    delete [] pCoefficientRows;
}

void EvgBasicModel::createRows(bool extended)
{
    pCoefficientRows = new EvgRow*[count];
    for (int i=0; i < count; i++)
    {
        if (extended)
            pCoefficientRows[i] = new ExtendRow;
        else
            pCoefficientRows[i] = new EvgRow;
    }

    // Init all Rows by their type
    for (int i = 0; i < count; i++)
    {
        pCoefficientRows[i]->init();
        pCoefficientRows[i]->settingLayout();
        pCoefficientRows[i]->setIdText(i + 1);
    }
}

float EvgBasicModel::getResult() const
{
    return result;
}

void EvgBasicModel::setResultValue()
{
    QString strResult;
    strResult.setNum(result, 'g', 4);
    strResult.insert(0, tr("<h2> = "));
    strResult.append(tr("</h2>"));
    pLabelResult->setText(strResult);
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

void EvgBasicModel::createCentralLayout()
{
    centralGrid = new QGridLayout;
    centralGrid->setSpacing(25);
    for (int i = 0; i < count; i++)
    {
        centralGrid->addWidget(pCoefficientRows[i]->labelId(), i, 0, Qt::AlignLeft | Qt::AlignVCenter);
        centralGrid->addWidget(pCoefficientRows[i]->spinBoxRow(), i, 1, Qt::AlignLeft | Qt::AlignVCenter);
        centralGrid->addWidget(pCoefficientRows[i]->labelDefinition(), i, 2, Qt::AlignLeft | Qt::AlignVCenter);
    }

    centralLayout = new QHBoxLayout;
    centralLayout->addStretch(1);
    centralLayout->addLayout(centralGrid);
    centralLayout->addStretch(1);
}

void EvgBasicModel::createMainLayout()
{
    mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout, 0);
    mainLayout->addStretch(1);
    mainLayout->addLayout(centralLayout);
    mainLayout->addStretch(1);
    mainLayout->addLayout(bottomLayout, 0);
    this->setLayout(mainLayout);
}

void EvgBasicModel::setEditable(bool yes)
{
    for (int i = 0; i < count; i++)
    {
        pCoefficientRows[i]->setEditable(yes);
    }
}

double EvgBasicModel::getValue(int number) const
{
    return pCoefficientRows[number]->getValue();
}

QString EvgBasicModel::getName() const
{
    return name;
}

TypeState EvgBasicModel::getState() const
{
    return _state;
}

void EvgBasicModel::setTypeState(TypeState newState)
{
    _state = newState;
}

bool EvgBasicModel::checkForZeros() const
{
    for (int i = 0; i < count; i++)
    {
        if (pCoefficientRows[i]->getValue() == 0.0)
            return FALSE;
    }
    return TRUE;
}
