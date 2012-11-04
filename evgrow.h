#ifndef EVGROW_H
#define EVGROW_H

#include <QWidget>
#include <QLabel>
#include <QDoubleSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>

class EvgRow : public QWidget
{
    Q_OBJECT
public:
    explicit EvgRow(QWidget *parent = 0);
    ~EvgRow();

    void setIdText(int newId);
    void setTextDefinition(QString newText);

    double getValue() const;
    void setValue(float value);
    void setEditable(bool yes = TRUE);

    QLabel *labelId();
    QDoubleSpinBox *spinBoxRow();
    QLabel *labelDefinition();

signals:
    
public slots:
    
private:
    void createSpinBox();

private:
    QLabel *pIdCoefficient;
    QDoubleSpinBox *pCoefficientValue;
    QLabel *pDefinitionCoefficient;
};

#endif // EVGROW_H
