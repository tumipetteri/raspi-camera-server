#ifndef SERVERAPP_H
#define SERVERAPP_H

#include <QCoreApplication>

class ServerApp : public QCoreApplication
{
    Q_OBJECT
public:
    ServerApp(int &argc, char **argv);
};

#endif // SERVERAPP_H
