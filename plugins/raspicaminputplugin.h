#ifndef RASPICAMINPUTPLUGIN_H
#define RASPICAMINPUTPLUGIN_H

#include "inputplugininterface.h"
#include <QtPlugin>

class RaspiCamInputPlugin: public InputPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.pelcone.raspberry.PlugAndPaint.FilterInterface" ) //FILE "inputplugins.json"
    //Q_INTERFACES(InputPluginInterface)
public:
    RaspiCamInputPlugin();

    virtual bool initialize();
    virtual char* getAvailableData();
};

#endif // RASPICAMINPUTPLUGIN_H
