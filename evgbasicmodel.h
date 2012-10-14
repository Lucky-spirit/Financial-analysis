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
    explicit EvgBasicModel(int coefficientsCount, QWidget *parent = 0, QString source = "", QString formulaText = "");
    ~EvgBasicModel();

    void createRows(int countOfRows);
    void setResultValue(float value);

signals:
    void sendCalculateToOthers();

public slots:
    virtual void calculate() = 0;

private:
    int count;
    QString textOfFormula;
    QLabel *pLabelFormula;
    QLabel *pLabelResult;
    EvgRow *pCoefficientRows;
    evgTextBrowser *pTextDefinitionModel;
};

#endif // EVGBASICMODEL_H
