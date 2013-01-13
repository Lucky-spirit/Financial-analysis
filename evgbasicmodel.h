#ifndef EVGBASICMODEL_H
#define EVGBASICMODEL_H

#include <QWidget>
#include <QLabel>
#include <QTextBrowser>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include "extendrow.h"
#include "evgtextbrowser.h"

class EvgBasicModel : public QWidget
{
    Q_OBJECT
public:
    explicit EvgBasicModel(int coefficientsCount, QWidget *parent = 0, QString source = "", QString modelName = "", QString formulaText = "", bool extended = FALSE);
    ~EvgBasicModel();

    virtual void createRows(bool extended);
    virtual float getResult() const;
    virtual void setResultValue();

    virtual void createTopLayout();
    virtual void createBottomLayout();
    virtual void createCentralLayout();
    virtual void createMainLayout();
    virtual void setRowsDefinitions() = 0;
    virtual void setEditable(bool yes = TRUE);

    double getValue(int number) const;
    QString getName() const;
    TypeState getState() const;
    void setTypeState(TypeState newState);

    virtual bool checkForZeros() const;

signals:
    void sendCalculateToOthers();

public slots:
    virtual void calculate(EvgBasicModel *pInputData) = 0;

protected:
    int count;
    float result;
    QString name;
    QString textOfFormula;
    QLabel *pLabelFormula;
    QLabel *pLabelResult;
    EvgRow **pCoefficientRows;
    evgTextBrowser *pTextDefinitionModel;
    QHBoxLayout *topLayout;
    QHBoxLayout *centralLayout;
    QHBoxLayout *bottomLayout;
    QGridLayout *centralGrid;
    QVBoxLayout *mainLayout;
    TypeState _state;
};

#endif // EVGBASICMODEL_H
