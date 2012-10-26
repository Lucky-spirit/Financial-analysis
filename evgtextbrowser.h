#ifndef EVGTEXTBROWSER_H
#define EVGTEXTBROWSER_H

#include <QTextBrowser>

class evgTextBrowser : public QTextBrowser
{
    Q_OBJECT
public:
    explicit evgTextBrowser(QWidget *parent = 0);

    // QSize sizeHint() const;
    // QSize minimumSizeHint() const;


signals:
    
public slots:
    
};

#endif // EVGTEXTBROWSER_H
