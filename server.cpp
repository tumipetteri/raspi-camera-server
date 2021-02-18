#include "server.h"
#include "plugins/raspicaminputplugin.h"

Server::Server()
{
    setInputPlugin(new RaspiCamInputPlugin());
}

void Server::configure()
{
    route("/", []() {
        return "Hello world";
    });

    route("/stream/mjpeg", [] () {
        return QString("You will get mjpeg video stream from here when the code is ready");
    });

    route("/stream/h264", [] () {
        return QString("You will get h264 video stream from here when the code is ready");
    });


    route("/admin", [] (qint32 id, const QHttpServerRequest &request) {
        return QString("this will serve admin interface");
    });

    route("/admin/api/brightness/", [] (qint32 brightness, const QHttpServerRequest &request) {
        return QString("You can use this interface to adjust brightness");
    });

    route("/admin/api/contrast/", [] (qint32 contrast, const QHttpServerRequest &request) {
        return QString("You can use this interface to adjust contrast");
    });

}

bool Server::start()
{
    const auto port = listen(QHostAddress::Any, 80);
    if (port == -1) {
        qDebug() << QCoreApplication::translate(
                "QHttpServerExample", "Could not run on http://127.0.0.1:%1/").arg(port);
        return false;
    }

    qDebug() << QCoreApplication::translate(
            "QHttpServerExample", "Running on http://127.0.0.1:%1/ (Press CTRL+C to quit)").arg(port);

    return true;
}

bool Server::setInputPlugin(InputPluginInterface* plugin)
{
    if(inputPlugin!=0) {
        delete inputPlugin;
    }
    inputPlugin = plugin;
    if(!inputPlugin->initialize()) {
        return false;
    }

    return true;
}
