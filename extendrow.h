#ifndef EXTENDROW_H
#define EXTENDROW_H

#include "evgrow.h"

class ExtendRow : public EvgRow
{
    Q_OBJECT
public:
    explicit ExtendRow(QWidget *parent = 0);

    void setStringByState(TypeState state);
    
signals:
    
public slots:

private:
    QLabel *stateDefinition;
};

#endif // EXTENDROW_H
