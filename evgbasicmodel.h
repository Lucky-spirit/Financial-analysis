#ifndef EVGBASICMODEL_H
#define EVGBASICMODEL_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QVBoxLayout>
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

    virtual void createTopLayout();
    virtual void createBottomLayout();
    virtual void createMainLayout();

signals:
    void sendCalculateToOthers();

public slots:
    virtual void calculate() = 0;

protected:
    int count;
    float result;
    QString textOfFormula;
    QLabel *pLabelFormula;
    QLabel *pLabelResult;
    EvgRow *pCoefficientRows;
    evgTextBrowser *pTextDefinitionModel;
    QHBoxLayout *topLayout;
    QHBoxLayout *bottomLayout;
    QVBoxLayout *mainLayout;
};

#endif // EVGBASICMODEL_H
