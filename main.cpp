#include <QApplication>
#include <QStyleFactory>
#include <QDir>
#include <QStandardPaths>
#include <QLoggingCategory>

#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication app(argc, argv);

    app.setApplicationName("CyberChat");
    app.setApplicationVersion("1.0.0");
    app.setOrganizationName("CyberNilsen");
    app.setOrganizationDomain("github.com/CyberNilsen/CyberChat");

    app.setWindowIcon(QIcon(":/images/CyberChat.png"));

#ifdef Q_OS_WIN
    app.setStyle(QStyleFactory::create("windowsvista"));
#elif defined(Q_OS_MAC)
    app.setStyle(QStyleFactory::create("macintosh"));

    app.setStyle(QStyleFactory::create("fusion"));
#endif

#ifndef QT_DEBUG
#endif

    MainWindow window;
    window.show();

    return app.exec();
}
