#ifndef EVGBASICMODEL_H
#define EVGBASICMODEL_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include "evgrow.h"
#include "evgtextbrowser.h"

class EvgBasicModel : public QWidget
{
    Q_OBJECT
public:
    explicit EvgBasicModel(QWidget *parent = 0, int coefficientsCount = 0);
    ~EvgBasicModel();

    void setFormulaText(QString text);
    void setResultValue(float value);

signals:
    void sendCalculateToOthers();

public slots:
    virtual void calculate() = 0;

private:
    int count;
    QLabel *pLabelFormula;
    QLabel *pLabelResult;
    EvgRow *pCoefficientRows;
    evgTextBrowser *pTextDefinitionModel;
};

#endif // EVGBASICMODEL_H
