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
    void calculateAll();
    void signToQuit();

public slots:

private:
    void createMenus();
    
private:
    QMenu *pFileMenu;
    QMenu *pEditMenu;
    QMenu *pHelpMenu;

    QAction *pCalculateAllAction;
    QAction *pQuitAction;
};

#endif // EVGMENUBAR_H
