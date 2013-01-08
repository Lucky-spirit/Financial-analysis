#include "extendrow.h"

ExtendRow::ExtendRow(QWidget *parent) :
    EvgRow(parent)
{
    stateDefinition = new QLabel(QString(tr("Невизначений фінансовий стан")));
}
