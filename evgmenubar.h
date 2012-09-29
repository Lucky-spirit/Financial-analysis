#ifndef EVGMENUBAR_H
#define EVGMENUBAR_H

#include <QMenuBar>
#include <QMenu>

class EvgMenuBar : public QMenuBar
{
    Q_OBJECT
public:
    explicit EvgMenuBar(QWidget *parent = 0);
    ~EvgMenuBar();
    
signals:
    
public slots:
    
private:
    QMenu *pFileMenu;
    QMenu *pEditMenu;
    QMenu *pHelpMenu;
};

#endif // EVGMENUBAR_H
