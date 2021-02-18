#ifndef INPUTPLUGININTERFACE_H
#define INPUTPLUGININTERFACE_H

#include <QObject>

class InputPluginInterface : public QObject
{
    Q_OBJECT
public:
    virtual ~InputPluginInterface() {}

    virtual bool initialize() = 0;
    virtual char* getAvailableData() = 0;
signals:
    virtual void newDataAvailable();
};

#endif // INPUTPLUGININTERFACE_H
