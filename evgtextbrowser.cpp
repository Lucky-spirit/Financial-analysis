#include "evgtextbrowser.h"

evgTextBrowser::evgTextBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
}

QSize evgTextBrowser::sizeHint() const
{
    QMargins m(contentsMargins());
    return document()->size().toSize() + QSize(m.left() + m.right(), m.top() + m.bottom());
}

QSize evgTextBrowser::minimumSizeHint() const
{
    return QSize(1, 1);
}
