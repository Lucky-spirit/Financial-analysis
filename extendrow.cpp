#include "extendrow.h"

ExtendRow::ExtendRow(QWidget *parent) :
    EvgRow(parent)
{
}

void ExtendRow::init()
{
    EvgRow::init();
}

void ExtendRow::changeIdToText(QString &idName)
{
    pIdCoefficient->setText(idName);
}

void ExtendRow::setStringByState(TypeState state)
{
    QString foo(tr(" фінансовий стан"));

    switch (state)
    {
    case TypeStateUnstable :
        foo.insert(0, tr("Нестійкий"));
        break;
    case TypeStateMiddle :
        foo.insert(0, tr("Середній"));
        break;
    case TypeStateStable :
        foo.insert(0, tr("Стійкий"));
        break;

    default :
        foo.insert(0, tr("Невизначений"));
        break;
    }
    setTextDefinition(foo);
}
