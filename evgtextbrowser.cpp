#include "evgtextbrowser.h"

evgTextBrowser::evgTextBrowser(QWidget *parent) :
    QTextBrowser(parent)
{
}

//QSize evgTextBrowser::sizeHint() const
//{
//    if (document()->isEmpty())
//        return QSize(0, 0);
//    else
//    {
//        QMargins m(contentsMargins());
//        return document()->size().toSize() + QSize(m.left() + m.right(), m.top() + m.bottom());
//    }
//}

//QSize evgTextBrowser::minimumSizeHint() const
//{
//    if (document()->isEmpty())
//        return QSize(0, 0);
//    else
//        return document()->size().toSize();
//}
