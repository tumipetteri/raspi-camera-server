#ifndef SERVER_H
#define SERVER_H

#include <QtHttpServer/QtHttpServer>
#include <QtHttpServer/QHttpServerRequest>

#include "inputplugininterface.h"

class Server : QHttpServer
{
    Q_OBJECT
public:
    Server();
    void configure();
    bool start();

    char* streamBuffer;

    bool setInputPlugin(InputPluginInterface* plugin);

protected:

    InputPluginInterface* inputPlugin = 0;
};

#endif // SERVER_H
