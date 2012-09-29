#include <QApplication>

#include "evgwindow.h"
#include "evgrow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    EvgWindow *pItsWindow = new EvgWindow;

    // EvgRow itsRow;
    // itsRow.show();

    QObject::connect(&app, SIGNAL(aboutToQuit()), pItsWindow, SLOT(mayToQuit()));

    // delete pItsWindow;
    // pItsWindow = NULL;

    // delete pApp;
    // pApp = NULL;

    return app.exec();
}
