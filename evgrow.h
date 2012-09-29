#ifndef EVGROW_H
#define EVGROW_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>

class EvgRow : public QWidget
{
    Q_OBJECT
public:
    explicit EvgRow(QWidget *parent = 0);
    ~EvgRow();

signals:
    
public slots:
    
private:
    QLabel *pIdCoefficient;
    QDoubleSpinBox *pCoefficientValue;
    QLabel *pDefinitionCoefficient;
};

#endif // EVGROW_H
