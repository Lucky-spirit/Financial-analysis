#include <QApplication>
#include <QTextCodec>

#include "evgwindow.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QTextCodec *russianCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(russianCodec);

    EvgWindow *pItsWindow = new EvgWindow;

    QObject::connect(&app, SIGNAL(aboutToQuit()), pItsWindow, SLOT(mayToQuit()));

    pItsWindow->showMaximized();

    return app.exec();
}
