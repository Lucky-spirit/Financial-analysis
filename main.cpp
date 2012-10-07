#include <QApplication>

#include "evgwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    EvgWindow *pItsWindow = new EvgWindow;

    QObject::connect(&app, SIGNAL(aboutToQuit()), pItsWindow, SLOT(mayToQuit()));

    pItsWindow->showMaximized();

    return app.exec();
}
