#include "mainwindow.h"
#include <QApplication>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setApplicationName("CyberChat");
    a.setApplicationVersion("1.0");
    a.setOrganizationName("CyberNilsen");
    a.setApplicationDisplayName("CyberChat - Secure Anonymous Messaging");

    a.setWindowIcon(QIcon(":/logo.png"));

    MainWindow w;
    w.show();

    return a.exec();
}
// Here is what happens when we start the program, we initilize the window and show it, we also keep it running when it has started
