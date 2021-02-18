#include "raspicaminputplugin.h"

RaspiCamInputPlugin::RaspiCamInputPlugin()
{

}

bool RaspiCamInputPlugin::initialize()
{
    qDebug() << "Initializing RaspiCam plugin";
    return false;
}

char* RaspiCamInputPlugin::getAvailableData()
{
    return nullptr;
}
