#ifndef EXTENDROW_H
#define EXTENDROW_H

#include "evgrow.h"

class ExtendRow : public EvgRow
{
    Q_OBJECT
public:
    explicit ExtendRow(QWidget *parent = 0);

    // Init functions;
    void init();

    void changeIdToText(QString &idName);
    void setStringByState(TypeState state);

signals:
    
public slots:

private:

};

#endif // EXTENDROW_H
