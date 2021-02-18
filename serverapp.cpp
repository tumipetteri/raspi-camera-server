#include "serverapp.h"
#include "server.h"
#include <QtCore>

ServerApp::ServerApp(int &argc, char **argv) : QCoreApplication(argc, argv)
{
    Server httpServer;
    httpServer.configure();
    if(!httpServer.start()) {
        qApp->quit();
    }
}
