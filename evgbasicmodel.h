#ifndef EVGBASICMODEL_H
#define EVGBASICMODEL_H

#include <QWidget>
#include <QLabel>

class EvgBasicModel : public QWidget
{
    Q_OBJECT
public:
    explicit EvgBasicModel(QWidget *parent = 0);
    ~EvgBasicModel();

    void setFormulaText(QString text);
    void setResultValue(float value);

signals:
    void sendCalculateToOthers();

public slots:
    virtual void calculate() = 0;

private:
    QLabel *pLabelFormula;
    QLabel *pLabelResult;
};

#endif // EVGBASICMODEL_H
